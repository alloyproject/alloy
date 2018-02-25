/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#include "Miner.h"

#include <functional>

#include "crypto/crypto.h"
#include "CryptoNoteCore/CachedBlock.h"
#include "CryptoNoteCore/CryptoNoteFormatUtils.h"

#include <System/InterruptedException.h>

namespace CryptoNote {

Miner::Miner(System::Dispatcher& dispatcher, Logging::ILogger& logger) :
  m_dispatcher(dispatcher),
  m_miningStopped(dispatcher),
  m_state(MiningState::MINING_STOPPED),
  m_logger(logger, "Miner") {
}

Miner::~Miner() {
  assert(m_state != MiningState::MINING_IN_PROGRESS);
}

BlockTemplate Miner::mine(const BlockMiningParameters& blockMiningParameters, size_t threadCount) {
  if (threadCount == 0) {
    throw std::runtime_error("Miner requires at least one thread");
  }

  if (m_state == MiningState::MINING_IN_PROGRESS) {
    throw std::runtime_error("Mining is already in progress");
  }

  m_state = MiningState::MINING_IN_PROGRESS;
  m_miningStopped.clear();

  runWorkers(blockMiningParameters, threadCount);

  assert(m_state != MiningState::MINING_IN_PROGRESS);
  if (m_state == MiningState::MINING_STOPPED) {
    m_logger(Logging::DEBUGGING) << "Mining has been stopped";
    throw System::InterruptedException();
  }

  assert(m_state == MiningState::BLOCK_FOUND);
  return m_block;
}

void Miner::stop() {
  MiningState state = MiningState::MINING_IN_PROGRESS;

  if (m_state.compare_exchange_weak(state, MiningState::MINING_STOPPED)) {
    m_miningStopped.wait();
    m_miningStopped.clear();
  }
}

void Miner::runWorkers(BlockMiningParameters blockMiningParameters, size_t threadCount) {
  assert(threadCount > 0);

  int height = boost::get<BaseInput>( blockMiningParameters.blockTemplate.baseTransaction.inputs.front()).blockIndex;

  m_logger(Logging::INFO) << "Starting mining block " << height << " for difficulty " << blockMiningParameters.difficulty;

  try {
    blockMiningParameters.blockTemplate.nonce = Crypto::rand<uint32_t>();

    for (size_t i = 0; i < threadCount; ++i) {
      m_workers.emplace_back(std::unique_ptr<System::RemoteContext<void>> (
        new System::RemoteContext<void>(m_dispatcher, std::bind(&Miner::workerFunc, this, blockMiningParameters.blockTemplate, blockMiningParameters.difficulty, threadCount, i)))
      );

      blockMiningParameters.blockTemplate.nonce++;
    }

    m_workers.clear();

  } catch (std::exception& e) {
    m_logger(Logging::ERROR) << "Error occurred during mining: " << e.what();
    m_state = MiningState::MINING_STOPPED;
  }

  m_miningStopped.set();
}

void Miner::workerFunc(const BlockTemplate& blockTemplate, Difficulty difficulty, uint32_t nonceStep, int threadnum) {
  try {
    BlockTemplate block = blockTemplate;
    Crypto::cn_context cryptoContext;

int hashes=0;
 clock_t t;
    t = clock();

    while (m_state == MiningState::MINING_IN_PROGRESS) {
      CachedBlock cachedBlock(block);
      Crypto::Hash hash = cachedBlock.getBlockLongHash(cryptoContext);
	hashes++;

	float	 telapsed = clock() - t;

	float 	hs=hashes/(telapsed/CLOCKS_PER_SEC);
	if (hashes  % 300 ==0) {
	 m_logger(Logging::INFO) << "Thread:" << threadnum  << "  Hashes per Second:"<<hs <<"      hashes : " << hashes;
	}

      if (check_hash(hash, difficulty)) {
        m_logger(Logging::INFO) << "Found block for difficulty " << difficulty;

        if (!setStateBlockFound()) {
          m_logger(Logging::DEBUGGING) << "block is already found or mining stopped";
          return;
        }

        m_block = block;
        return;
      }

      block.nonce += nonceStep;
    }
  } catch (std::exception& e) {
    m_logger(Logging::ERROR) << "Miner got error: " << e.what();
    m_state = MiningState::MINING_STOPPED;
  }
}

bool Miner::setStateBlockFound() {
  auto state = m_state.load();

  for (;;) {
    switch (state) {
      case MiningState::BLOCK_FOUND:
        return false;

      case MiningState::MINING_IN_PROGRESS:
        if (m_state.compare_exchange_weak(state, MiningState::BLOCK_FOUND)) {
          return true;
        }
        break;

      case MiningState::MINING_STOPPED:
        return false;

      default:
        assert(false);
        return false;
    }
  }
}

} //namespace CryptoNote
