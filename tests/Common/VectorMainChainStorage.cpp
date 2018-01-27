/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#include "VectorMainChainStorage.h"

#include <CryptoNoteCore/CryptoNoteTools.h>

namespace CryptoNote {

void VectorMainChainStorage::pushBlock(const RawBlock& rawBlock) {
  storage.push_back(rawBlock);
}

void VectorMainChainStorage::popBlock() {
  storage.pop_back();
}

RawBlock VectorMainChainStorage::getBlockByIndex(uint32_t index) const {
  return storage.at(index);
}

uint32_t VectorMainChainStorage::getBlockCount() const {
  return static_cast<uint32_t>(storage.size());
}

void VectorMainChainStorage::clear() {
  storage.clear();
}

std::unique_ptr<IMainChainStorage> createVectorMainChainStorage(const Currency& currency) {
  std::unique_ptr<IMainChainStorage> storage(new VectorMainChainStorage());

  RawBlock genesis;
  genesis.block = toBinaryArray(currency.genesisBlock());
  storage->pushBlock(genesis);

  return storage;
}

}
