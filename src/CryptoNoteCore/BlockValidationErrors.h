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

#include <string>
#include <system_error>

namespace CryptoNote {
namespace error {

enum class BlockValidationError {
  VALIDATION_SUCCESS = 0,
  WRONG_VERSION,
  PARENT_BLOCK_SIZE_TOO_BIG,
  PARENT_BLOCK_WRONG_VERSION,
  TIMESTAMP_TOO_FAR_IN_FUTURE,
  TIMESTAMP_TOO_FAR_IN_PAST,
  CUMULATIVE_BLOCK_SIZE_TOO_BIG,
  DIFFICULTY_OVERHEAD,
  BLOCK_REWARD_MISMATCH,
  CHECKPOINT_BLOCK_HASH_MISMATCH,
  PROOF_OF_WORK_TOO_WEAK,
NO_MORE_BLOCK,
  TRANSACTION_ABSENT_IN_POOL
};

// custom category:
class BlockValidationErrorCategory : public std::error_category {
public:
  static BlockValidationErrorCategory INSTANCE;

  virtual const char* name() const throw() {
    return "BlockValidationErrorCategory";
  }

  virtual std::error_condition default_error_condition(int ev) const throw() {
    return std::error_condition(ev, *this);
  }

  virtual std::string message(int ev) const {
    BlockValidationError code = static_cast<BlockValidationError>(ev);

    switch (code) {
      case BlockValidationError::VALIDATION_SUCCESS: return "Block validated successfully";
      case BlockValidationError::WRONG_VERSION: return "Wrong block version";
      case BlockValidationError::PARENT_BLOCK_SIZE_TOO_BIG: return "Parent block size is too big";
      case BlockValidationError::PARENT_BLOCK_WRONG_VERSION: return "Parent block has wrong version";
      case BlockValidationError::TIMESTAMP_TOO_FAR_IN_FUTURE: return "Timestamp is too far in future";
      case BlockValidationError::TIMESTAMP_TOO_FAR_IN_PAST: return "Timestamp is too far in past";
      case BlockValidationError::CUMULATIVE_BLOCK_SIZE_TOO_BIG: return "Cumulative block size is too big";
      case BlockValidationError::DIFFICULTY_OVERHEAD: return "Block difficulty overhead occurred";
      case BlockValidationError::BLOCK_REWARD_MISMATCH: return "Block reward doesn't match expected reward";
      case BlockValidationError::CHECKPOINT_BLOCK_HASH_MISMATCH: return "Checkpoint block hash mismatch";
      case BlockValidationError::PROOF_OF_WORK_TOO_WEAK: return "Proof of work is too weak";
case BlockValidationError::NO_MORE_BLOCK: return "Kill block reached";
      case BlockValidationError::TRANSACTION_ABSENT_IN_POOL: return "Block's transaction is absent in transaction pool";
      default: return "Unknown error";
    }
  }

private:
  BlockValidationErrorCategory() {
  }
};

inline std::error_code make_error_code(CryptoNote::error::BlockValidationError e) {
  return std::error_code(static_cast<int>(e), CryptoNote::error::BlockValidationErrorCategory::INSTANCE);
}

}
}

namespace std {

template <>
struct is_error_code_enum<CryptoNote::error::BlockValidationError>: public true_type {};

}
