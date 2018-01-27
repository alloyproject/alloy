/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#include "DatabaseBlockchainCacheFactory.h"

#include "IDataBase.h"

#include "BlockchainCache.h"
#include "DatabaseBlockchainCache.h"

namespace CryptoNote {

DatabaseBlockchainCacheFactory::DatabaseBlockchainCacheFactory(IDataBase& database, Logging::ILogger& logger): database(database), logger(logger) {

}

DatabaseBlockchainCacheFactory::~DatabaseBlockchainCacheFactory() {

}

std::unique_ptr<IBlockchainCache> DatabaseBlockchainCacheFactory::createRootBlockchainCache(const Currency& currency) {
  return std::unique_ptr<IBlockchainCache> (new DatabaseBlockchainCache(currency, database, *this, logger));
}

std::unique_ptr<IBlockchainCache> DatabaseBlockchainCacheFactory::createBlockchainCache(const Currency& currency, IBlockchainCache* parent, uint32_t startIndex) {
  return std::unique_ptr<IBlockchainCache> (new BlockchainCache("", currency, logger, parent, startIndex));
}

} //namespace CryptoNote
