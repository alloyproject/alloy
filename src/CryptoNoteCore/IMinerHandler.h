/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#pragma once

#include "CryptoNoteCore/CryptoNoteBasic.h"
#include "CryptoNoteCore/Difficulty.h"

namespace CryptoNote {
  struct IMinerHandler {
    virtual bool handle_block_found(BlockTemplate& b) = 0;
    virtual bool get_block_template(BlockTemplate& b, const AccountPublicAddress& adr, Difficulty& diffic, uint32_t& height, const BinaryArray& ex_nonce) = 0;

  protected:
    ~IMinerHandler(){};
  };
}
