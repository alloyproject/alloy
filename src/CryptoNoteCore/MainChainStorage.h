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

#include "IMainChainStorage.h"
#include "Currency.h"
#include "SwappedVector.h"

namespace CryptoNote {

class MainChainStorage: public IMainChainStorage {
public:
  MainChainStorage(const std::string& blocksFilame, const std::string& indexesFilename);
  virtual ~MainChainStorage();

  virtual void pushBlock(const RawBlock& rawBlock) override;
  virtual void popBlock() override;

  virtual RawBlock getBlockByIndex(uint32_t index) const override;
  virtual uint32_t getBlockCount() const override;

  virtual void clear() override;

private:
  mutable SwappedVector<RawBlock> storage;
};

std::unique_ptr<IMainChainStorage> createSwappedMainChainStorage(const std::string& dataDir, const Currency& currency);

}
