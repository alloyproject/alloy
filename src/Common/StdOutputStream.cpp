/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#include "StdOutputStream.h"

namespace Common {

StdOutputStream::StdOutputStream(std::ostream& out) : out(out) {
}

size_t StdOutputStream::writeSome(const void* data, size_t size) {
  out.write(static_cast<const char*>(data), size);
  if (out.bad()) {
    return 0;
  }

  return size;
}

}
