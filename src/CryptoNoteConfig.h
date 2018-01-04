// Copyright (c) 2017-2018, The Alloy Developers.
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>
#include <initializer_list>

namespace CryptoNote {
namespace parameters {

#define CRYPTONOTE_MAX_BLOCK_NUMBER                   500000000
#define CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                500000000
#define CRYPTONOTE_MAX_TX_SIZE                        1000000000
#define CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       0x2 // address starts with "A"
#define CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          60
#define CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            60 * 60 * 2

#define BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             60

#define MONEY_SUPPLY                                  84000000
#define EMISSION_SPEED_FACTOR                         20

#define CRYPTONOTE_REWARD_BLOCKS_WINDOW               100
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     30000 // size of block (bytes) after which reward for block calculated using block size
#define CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        600
#define CRYPTONOTE_MONEY_DECIMAL_POINT                12
#define CRYPTONOTE_MONEY_DECIMAL_UNITS                (uint64_t)pow(10, CRYPTONOTE_MONEY_DECIMAL_POINT)
#define MINIMUM_FEE                                   100000
#define DEFAULT_DUST_THRESHOLD                        MINIMUM_FEE
#define DIFFICULTY_TARGET                             180 // seconds
#define EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             24 * 60 * 60 / DIFFICULTY_TARGET
#define DIFFICULTY_WINDOW                             EXPECTED_NUMBER_OF_BLOCKS_PER_DAY // blocks
#define DIFFICULTY_CUT                                60 // timestamps to cut after sorting
#define DIFFICULTY_LAG                                15

#define MAX_BLOCK_SIZE_INITIAL                        20 * 1024
#define MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         100 * 1024
#define MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       365 * 24 * 60 * 60 / DIFFICULTY_TARGET

#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     1
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS

#define CRYPTONOTE_MEMPOOL_TX_LIVETIME                60 * 60 * 24 // seconds, one day
#define CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME 60 * 60 * 24 * 7 // seconds, one week
#define CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL 7 // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME time to forget tx

#define FUSION_TX_MAX_SIZE                            CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 30 / 100
#define FUSION_TX_MIN_INPUT_COUNT                     12
#define FUSION_TX_MIN_IN_OUT_COUNT_RATIO              4

#define CRYPTONOTE_BLOCKS_FILENAME                    "blocks.dat"
#define CRYPTONOTE_BLOCKINDEXES_FILENAME              "blockindexes.dat"
#define CRYPTONOTE_BLOCKSCACHE_FILENAME               "blockscache.dat"
#define CRYPTONOTE_POOLDATA_FILENAME                  "poolstate.bin"
#define P2P_NET_DATA_FILENAME                         "p2pstate.bin"
#define CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME        "blockchainindices.dat"
#define MINER_CONFIG_FILE_NAME                        "miner_conf.json"

} // parameters

#define CRYPTONOTE_NAME                               "alloy"
#define GENESIS_COINBASE_TX_HEX                       "013c01ff00018080d49ca79812029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd08807121015c1bec331dab2fc1b8744b8785e9fa59d5c880c429eca3aca70b3b77250890ec"

#define CURRENT_TRANSACTION_VERSION                   1
#define BLOCK_MAJOR_VERSION_1                         1
#define BLOCK_MINOR_VERSION_0                         0

#define BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        10000 // by default, blocks ids count in synchronizing
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            128 // by default, blocks count in blocks downloading
#define COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         1000

#define P2P_DEFAULT_PORT                              1810
#define RPC_DEFAULT_PORT                              1811

#define P2P_LOCAL_WHITE_PEERLIST_LIMIT                1000
#define P2P_LOCAL_GRAY_PEERLIST_LIMIT                 5000

#define P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          64 * 1024 * 1024 // 64 MB
#define P2P_DEFAULT_CONNECTIONS_COUNT                 8
#define P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     70
#define P2P_DEFAULT_HANDSHAKE_INTERVAL                60 // seconds
#define P2P_DEFAULT_PACKET_MAX_SIZE                   50000000 // 50000000 bytes maximum packet size
#define P2P_DEFAULT_PEERS_IN_HANDSHAKE                250
#define P2P_DEFAULT_CONNECTION_TIMEOUT                5000 // 5 seconds
#define P2P_DEFAULT_PING_CONNECTION_TIMEOUT           2000 // 2 seconds
#define P2P_DEFAULT_INVOKE_TIMEOUT                    60 * 2 * 1000 // 2 minutes
#define P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          5000 // 5 seconds
#define P2P_STAT_TRUSTED_PUB_KEY                      "8f80f9a5a434a9f1510d13336228debfee9c918ce505efe225d8c94d045fa115"

#define CRYPTONOTE_NETWORK                            { { 0x01, 0x07, 0x03, 0x9f, 0x4b, 0x08, 0x01, 0xFF, 0x24, 0x4a, 0x06, 0x7b, 0x5a, 0x03, 0x01, 0xFE } }

const std::initializer_list<const char*> SEED_NODES {
  "144.217.165.72:1810",
  "144.217.165.189:1810",
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

const std::initializer_list<CheckpointData> CHECKPOINTS {
  { 1200, "1272f51d8a5936583651b05347a9c2b98057832900a0408fcd6179b7a87f6a84" },
};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS
