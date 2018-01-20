/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#pragma once

#include <cstdint>
#include <memory>

namespace CryptoNote {

class IInputStream {
public:
  virtual size_t read(char* data, size_t size) = 0;
};

class IOutputStream {
public:
  virtual void write(const char* data, size_t size) = 0;
};

}
