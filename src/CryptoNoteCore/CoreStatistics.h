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

#include "Serialization/ISerializer.h"

namespace CryptoNote {

struct CoreStatistics {
  uint64_t transactionPoolSize;
  uint64_t blockchainHeight;
  uint64_t miningSpeed;
  uint64_t alternativeBlockCount;
  std::string topBlockHashString;

  void serialize(ISerializer& s) {    
    s(transactionPoolSize, "tx_pool_size");
    s(blockchainHeight, "blockchain_height");
    s(miningSpeed, "mining_speed");
    s(alternativeBlockCount, "alternative_blocks");
    s(topBlockHashString, "top_block_id_str");
  }
};

}
