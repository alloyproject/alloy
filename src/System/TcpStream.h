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

#include <array>
#include <cstdint>
#include <streambuf>

namespace System {

class TcpConnection;

class TcpStreambuf : public std::streambuf {
public:
  explicit TcpStreambuf(TcpConnection& connection);
  TcpStreambuf(const TcpStreambuf&) = delete;
  ~TcpStreambuf();
  TcpStreambuf& operator=(const TcpStreambuf&) = delete;

private:
  TcpConnection& connection;
  std::array<char, 4096> readBuf;
  std::array<uint8_t, 1024> writeBuf;

  std::streambuf::int_type overflow(std::streambuf::int_type ch) override;
  int sync() override;
  std::streambuf::int_type underflow() override;
  bool dumpBuffer(bool finalize);
};

}
