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

#include <CryptoNoteCore/IMainChainStorage.h>
#include <CryptoNoteCore/Currency.h>

#include <vector>

namespace CryptoNote {

class VectorMainChainStorage: public IMainChainStorage {
public:
  virtual void pushBlock(const RawBlock& rawBlock) override;
  virtual void popBlock() override;
  virtual RawBlock getBlockByIndex(uint32_t index) const override;
  virtual uint32_t getBlockCount() const override;
  virtual void clear() override;

private:
  std::vector<RawBlock> storage;
};

std::unique_ptr<IMainChainStorage> createVectorMainChainStorage(const Currency& currency);

}
