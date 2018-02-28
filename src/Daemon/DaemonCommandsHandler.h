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

#include "Common/ConsoleHandler.h"

#include <Logging/LoggerRef.h>
#include <Logging/LoggerManager.h>

namespace CryptoNote {
class Core;
class NodeServer;
}

class DaemonCommandsHandler
{
public:
  DaemonCommandsHandler(CryptoNote::Core& core, CryptoNote::NodeServer& srv, Logging::LoggerManager& log);

  bool start_handling() {
    m_consoleHandler.start();
    return true;
  }

  void stop_handling() {
    m_consoleHandler.stop();
  }

private:

  Common::ConsoleHandler m_consoleHandler;
  CryptoNote::Core& m_core;
  CryptoNote::NodeServer& m_srv;
  Logging::LoggerRef logger;
  Logging::LoggerManager& m_logManager;

  std::string get_commands_str();
  bool print_block_by_height(uint32_t height);
  bool print_block_by_hash(const std::string& arg);

  bool exit(const std::vector<std::string>& args);
  bool help(const std::vector<std::string>& args);
  bool print_pl(const std::vector<std::string>& args);
  bool show_hr(const std::vector<std::string>& args);
  bool hide_hr(const std::vector<std::string>& args);
  bool print_bc_outs(const std::vector<std::string>& args);
  bool print_cn(const std::vector<std::string>& args);
  bool print_bc(const std::vector<std::string>& args);
  bool print_bci(const std::vector<std::string>& args);
  bool set_log(const std::vector<std::string>& args);
  bool print_block(const std::vector<std::string>& args);
  bool print_height(const std::vector<std::string>& args);
  bool print_tx(const std::vector<std::string>& args);
  bool print_pool(const std::vector<std::string>& args);
  bool print_pool_sh(const std::vector<std::string>& args);
  bool start_mining(const std::vector<std::string>& args);
  bool stop_mining(const std::vector<std::string>& args);
  bool version(const std::vector<std::string>& args);
  bool diff(const std::vector<std::string>& args);
  bool total_txs(const std::vector<std::string>& args);
  bool mempool(const std::vector<std::string>& args);
  bool hashrate(const std::vector<std::string>& args);
};
