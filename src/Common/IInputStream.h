// Copyright (c) 2017-2018, The Alloy Developers.
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstddef>

namespace Common {

class IInputStream {
public:
  virtual ~IInputStream() { }
  virtual size_t readSome(void* data, size_t size) = 0;
};

}
