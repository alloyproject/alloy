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

#include <cstddef>
#include <cstdint>
#include <limits>
#include <initializer_list>

namespace CryptoNote {
namespace parameters {

#define CRYPTONOTE_MAX_BLOCK_NUMBER                     500000000
#define CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                  500000000
#define CRYPTONOTE_MAX_TX_SIZE                          1000000000
#define CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX         54 // starts with "A"
#define CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW            30
#define CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT              60 * 60 * 2

#define BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW               60

#define MONEY_SUPPLY                                    84000000
#define MIN_MIXIN                                       0
#define MANDATORY_MIXIN_BLOCK_VERSION                   0
#define KILL_HEIGHT                                     0
#define ZAWY_DIFFICULTY_BLOCK_INDEX                     0
#define ZAWY_DIFFICULTY_V2                              1
#define ZAWY_DIFFICULTY_DIFFICULTY_BLOCK_VERSION        0


#define EMISSION_SPEED_FACTOR                           20
#define GENESIS_BLOCK_REWARD                            4560000

#define CRYPTONOTE_REWARD_BLOCKS_WINDOW                 100
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE       100000
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2    90000
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1    80000
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE
#define CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE          600
#define CRYPTONOTE_MONEY_DECIMAL_POINT                  12
#define CRYPTONOTE_MONEY_DECIMAL_UNITS                  (uint64_t)pow(10, CRYPTONOTE_MONEY_DECIMAL_POINT)
#define MINIMUM_FEE                                     (uint64_t)pow(10, CRYPTONOTE_MONEY_DECIMAL_POINT / 2)
#define DEFAULT_FEE                                     (uint64_t)pow(10, CRYPTONOTE_MONEY_DECIMAL_POINT - 2)
#define DEFAULT_DUST_THRESHOLD                          MINIMUM_FEE

#define ALLOY_TRANSACTION_SIZE_LIMIT                    57000 
#define MEMPOOL_POLLING_INTERVAL                        60 // how often to clean mempool

#define DIFFICULTY_TARGET                               180
#define EXPECTED_NUMBER_OF_BLOCKS_PER_DAY               24 * 60 * 60 / DIFFICULTY_TARGET
#define DIFFICULTY_WINDOW                               EXPECTED_NUMBER_OF_BLOCKS_PER_DAY
#define DIFFICULTY_WINDOW_V1                            DIFFICULTY_WINDOW
#define DIFFICULTY_WINDOW_V2                            DIFFICULTY_WINDOW
#define DIFFICULTY_WINDOW_V4                            62
#define DIFFICULTY_CUT                                  60
#define DIFFICULTY_CUT_V1                               DIFFICULTY_CUT
#define DIFFICULTY_CUT_V2                               DIFFICULTY_CUT
#define DIFFICULTY_LAG                                  15
#define DIFFICULTY_LAG_V1                               DIFFICULTY_LAG
#define DIFFICULTY_LAG_V2                               DIFFICULTY_LAG

#define MAX_BLOCK_SIZE_INITIAL                          100 * 1024
#define MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR           100 * 1024
#define MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR         365 * 24 * 60 * 60 / DIFFICULTY_TARGET

#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS       1
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS      DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS

#define CRYPTONOTE_MEMPOOL_TX_LIVETIME                  60 * 60 * 24
#define CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME   CRYPTONOTE_MEMPOOL_TX_LIVETIME * 7
#define CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL 7

#define FUSION_TX_MIN_INPUT_COUNT                       12
#define FUSION_TX_MIN_IN_OUT_COUNT_RATIO                4

#define KEY_IMAGE_CHECKING_BLOCK_INDEX                  0
#define UPGRADE_HEIGHT_V2                               1
#define UPGRADE_HEIGHT_V3                               2
#define UPGRADE_HEIGHT_V4                               17500
#define UPGRADE_HEIGHT_V5                               99999999999999999999

#define UPGRADE_VOTING_THRESHOLD                        90
#define UPGRADE_VOTING_WINDOW                           EXPECTED_NUMBER_OF_BLOCKS_PER_DAY
#define UPGRADE_WINDOW                                  EXPECTED_NUMBER_OF_BLOCKS_PER_DAY

#define CRYPTONOTE_BLOCKS_FILENAME                      "blocks.bin"
#define CRYPTONOTE_BLOCKINDEXES_FILENAME                "blockindexes.bin"
#define CRYPTONOTE_POOLDATA_FILENAME                    "poolstate.bin"
#define P2P_NET_DATA_FILENAME                           "p2pstate.bin"
#define MINER_CONFIG_FILE_NAME                          "miner_conf.json"

} // parameters

#define CRYPTONOTE_NAME                                 "alloy"
#define CRYPTONOTE_GENESIS_TX                           "011e01ff00018080a0fef0fa97a43f029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd0880712101d201f0ee231168072d806ecd2c733bb79286c398aa24d9b0d06d7bfb89d2869d"

#define TRANSACTION_VERSION_1                           1
#define TRANSACTION_VERSION_2                           2
#define CURRENT_TRANSACTION_VERSION                     TRANSACTION_VERSION_1
#define BLOCK_MAJOR_VERSION_1                           1
#define BLOCK_MAJOR_VERSION_2                           2
#define BLOCK_MAJOR_VERSION_3                           3
#define BLOCK_MAJOR_VERSION_4                           4
#define BLOCK_MAJOR_VERSION_5                           5


#define BLOCK_MINOR_VERSION_0                           0
#define BLOCK_MINOR_VERSION_1                           1

#define BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT          10000
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT              128
#define COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT           1000

#define P2P_DEFAULT_PORT                                1810
#define RPC_DEFAULT_PORT                                1811

#define P2P_LOCAL_WHITE_PEERLIST_LIMIT                  1000
#define P2P_LOCAL_GRAY_PEERLIST_LIMIT                   5000

#define P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE            64 * 1024 * 1024
#define P2P_DEFAULT_CONNECTIONS_COUNT                   8
#define P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT       70
#define P2P_DEFAULT_HANDSHAKE_INTERVAL                  60
#define P2P_DEFAULT_PACKET_MAX_SIZE                     50000000
#define P2P_DEFAULT_PEERS_IN_HANDSHAKE                  250
#define P2P_DEFAULT_CONNECTION_TIMEOUT                  5000
#define P2P_DEFAULT_PING_CONNECTION_TIMEOUT             2000
#define P2P_DEFAULT_INVOKE_TIMEOUT                      60 * 2 * 1000
#define P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT            5000
#define P2P_STAT_TRUSTED_PUB_KEY                        "8f80f9a5a434a9f1510d13336228debfee9c918ce505efe225d8c94d045fa115"

const std::initializer_list<const char*> SEED_NODES {
   "34.197.53.233:1810",
  "89.18.26.10:1810",
  "89.18.27.201:1810",
  "195.201.35.225:1810"
  
};

struct CheckpointData {
  uint32_t index;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

const std::initializer_list<CheckpointData> CHECKPOINTS {
  { 1, "5220a193ed61aabd5807ab8e1c948cd97bb45a53487975949fa9fef06c5fab05" },
  { 2500, "6a116d1d01afae5520e476f215dee28c1e720a9a95b8bb099450acfa59a04e4e" },
  { 5000, "f4819ea83564fde4f4eba0cb9fac9ed93558de0d6ef81e41beb538ad1b079465" },
  {9670, "c7528f5cc457e128932a5eeae16bdd93e52475f7da11660c2ad8bcb93891a1d6" },
  {13200, "a08896b7f43240bc6e97f0fe69fa3002d13ea9de7b5224779e7a6cf3d7f21356"},
  {14850, "de4cc2ab2f1b111b10bf71a788f62b5573975321b6a8336d62c46d00b714f5ed"},

{15000,"76c27f4cdc918843285e242852a6e47d09ecc1e553c7aa49083c5e72cdf439f4"},

{15257,"6341780358d992f75de2a1f2549940889db055a86c8fd2b308c157139225a3f0"},
{15258, "8b08c4ae4e21a5a4a03c90bf8a7e451d02ccd5e2be4b0636dcd7e911c66da147"},
{15259,"5a7fb6e05d506af495017008501007bf8c976ea15a517fc802d71b069646a09d"},
{15260,"674952685a0d35b553353d305b38d09f57b4698c142794c487f69e063cb2a491"},
{15261,"4009419ee181ef6ec47baaf7ab5bb2c5f251e0ddfd24af9eba6dfa77be01bec2"},
{15262,"2ded52aae2d18adea006eabc4a8b7bacdb10e8054e6d81f336e1ef85785c521d"},
{15263, "5f4898734df48fbc189490e07e353f5181836c94c0aa8a752c2f8ffef9d3a211"},
{15264, "4a69275e70d2dc90e982e1c1dcbc9f94f554baac789de258b9ad87a8d274d32d"},
{15281,"827076b6eda612b5e1a55bf0decd76d231b9c4079f08ce859c8acb97cfd035e9"},
{15282,"619f25eeabae9173410266f8770fe3620c19e5e5d33dcfc232b19ca129d43157"},
{15283,"23b3373341b0efc6f00c7f10f25ada710b8be3243d66029e15db03aca03ad086"},
{15284,"877244f49025029946ffde5bd85b0548fd0e889b1d8df4bd3e33baef75b1079e"},
{15800, "37aef506f2b5f6568e56d001790badb8bc1f09d2e0af5e1eba45a7afbe5842ad"},


{17665, "ca518008a7558a464c0fe8fa8fbea97041aa42d6434f2a11239017b107541711"},

{18200, "a81fc84267dd514d29c05c968419ac78610813097df2e3d75c3993a902eebd14"}


};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS
