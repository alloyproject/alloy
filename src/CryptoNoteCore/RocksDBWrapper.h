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

#include <atomic>
#include <memory>
#include <string>

#include "rocksdb/db.h"

#include "IDataBase.h"
#include "DataBaseConfig.h"

#include <Logging/LoggerRef.h>

namespace CryptoNote {

class RocksDBWrapper : public IDataBase {
public:
  RocksDBWrapper(Logging::ILogger& logger);
  virtual ~RocksDBWrapper();

  RocksDBWrapper(const RocksDBWrapper&) = delete;
  RocksDBWrapper(RocksDBWrapper&&) = delete;

  RocksDBWrapper& operator=(const RocksDBWrapper&) = delete;
  RocksDBWrapper& operator=(RocksDBWrapper&&) = delete;

  void init(const DataBaseConfig& config);
  void shutdown();
  void destoy(const DataBaseConfig& config); //Be careful with this method!

  std::error_code write(IWriteBatch& batch) override;
  std::error_code writeSync(IWriteBatch& batch) override;
  std::error_code read(IReadBatch& batch) override;

private:
  std::error_code write(IWriteBatch& batch, bool sync);

  rocksdb::Options getDBOptions(const DataBaseConfig& config);
  std::string getDataDir(const DataBaseConfig& config);

  enum State {
    NOT_INITIALIZED,
    INITIALIZED
  };

  Logging::LoggerRef logger;
  std::unique_ptr<rocksdb::DB> db;
  std::atomic<State> state;
};
}
