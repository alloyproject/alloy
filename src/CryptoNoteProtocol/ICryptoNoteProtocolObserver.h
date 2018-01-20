/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#pragma once

#include <cstddef>
#include <cstdint>
#include <cstddef>

namespace CryptoNote {

class ICryptoNoteProtocolObserver {
public:
  virtual void peerCountUpdated(size_t count) {}
  virtual void lastKnownBlockHeightUpdated(uint32_t height) {}
  virtual void blockchainSynchronized(uint32_t topHeight) {}
};

} //namespace CryptoNote
