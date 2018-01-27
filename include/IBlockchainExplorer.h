/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#pragma once

#include <array>
#include <vector>
#include <istream>
#include <ostream>

#include "BlockchainExplorerData.h"

namespace CryptoNote {

class IBlockchainObserver {
public:
  virtual ~IBlockchainObserver() {}

  virtual void blockchainUpdated(const std::vector<BlockDetails>& newBlocks, const std::vector<BlockDetails>& alternativeBlocks) {}
  virtual void poolUpdated(const std::vector<TransactionDetails>& newTransactions, const std::vector<std::pair<Crypto::Hash, TransactionRemoveReason>>& removedTransactions) {}

  virtual void blockchainSynchronized(const BlockDetails& topBlock) {}
};

class IBlockchainExplorer {
public:
  virtual ~IBlockchainExplorer() {};

  virtual bool addObserver(IBlockchainObserver* observer) = 0;
  virtual bool removeObserver(IBlockchainObserver* observer) = 0;

  virtual void init() = 0;
  virtual void shutdown() = 0;

  virtual bool getBlocks(const std::vector<uint32_t>& blockHeights, std::vector<std::vector<BlockDetails>>& blocks) = 0;
  virtual bool getBlocks(const std::vector<Crypto::Hash>& blockHashes, std::vector<BlockDetails>& blocks) = 0;
  virtual bool getBlocks(uint64_t timestampBegin, uint64_t timestampEnd, uint32_t blocksNumberLimit, std::vector<BlockDetails>& blocks, uint32_t& blocksNumberWithinTimestamps) = 0;

  virtual bool getBlockchainTop(BlockDetails& topBlock) = 0;

  virtual bool getTransactions(const std::vector<Crypto::Hash>& transactionHashes, std::vector<TransactionDetails>& transactions) = 0;
  virtual bool getTransactionsByPaymentId(const Crypto::Hash& paymentId, std::vector<TransactionDetails>& transactions) = 0;
  virtual bool getPoolState(const std::vector<Crypto::Hash>& knownPoolTransactionHashes, Crypto::Hash knownBlockchainTop, bool& isBlockchainActual, std::vector<TransactionDetails>& newTransactions, std::vector<Crypto::Hash>& removedTransactions) = 0;

  virtual uint64_t getRewardBlocksWindow() = 0;
  virtual uint64_t getFullRewardMaxBlockSize(uint8_t majorVersion) = 0;

  virtual bool isSynchronized() = 0;
};

}
