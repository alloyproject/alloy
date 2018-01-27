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

#include "IBlockchainCacheFactory.h"
#include <Logging/LoggerMessage.h>

namespace CryptoNote {

class IDataBase;

class DatabaseBlockchainCacheFactory: public IBlockchainCacheFactory {
public:
  explicit DatabaseBlockchainCacheFactory(IDataBase& database, Logging::ILogger& logger);
  virtual ~DatabaseBlockchainCacheFactory();

  virtual std::unique_ptr<IBlockchainCache> createRootBlockchainCache(const Currency& currency) override;
  virtual std::unique_ptr<IBlockchainCache> createBlockchainCache(const Currency& currency, IBlockchainCache* parent, uint32_t startIndex = 0) override;

private:
  IDataBase& database;
  Logging::ILogger& logger;
};

} //namespace CryptoNote
