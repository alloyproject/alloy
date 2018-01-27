/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#include "VectorOutputStream.h"

namespace Common {

VectorOutputStream::VectorOutputStream(std::vector<uint8_t>& out) : out(out) {
}

size_t VectorOutputStream::writeSome(const void* data, size_t size) {
  out.insert(out.end(), static_cast<const uint8_t*>(data), static_cast<const uint8_t*>(data) + size);
  return size;
}

}
