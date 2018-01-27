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

#include <unordered_map>
#include <map>

#include <IDataBase.h>
#include "CryptoNoteCore/BlockchainReadBatch.h"
#include "CryptoNoteCore/BlockchainWriteBatch.h"

namespace CryptoNote {

class DataBaseMock : public IDataBase {
public:
  DataBaseMock() = default;
  ~DataBaseMock() override;

  std::error_code write(IWriteBatch& batch) override;
  std::error_code writeSync(IWriteBatch& batch) override;
  std::error_code read(IReadBatch& batch) override;
  std::unordered_map<uint32_t, RawBlock> blocks();

  std::map<std::string, std::string> baseState;
};
}
