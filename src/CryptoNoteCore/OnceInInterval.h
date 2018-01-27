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

#include <time.h>

namespace CryptoNote
{

class OnceInInterval {
public:

  OnceInInterval(unsigned interval, bool startNow = true) 
    : m_interval(interval), m_lastCalled(startNow ? 0 : time(nullptr)) {}

  template<class F>
  bool call(F func) {
    time_t currentTime = time(nullptr);

    if (currentTime - m_lastCalled > m_interval) {
      bool res = func();
      time(&m_lastCalled);
      return res;
    }

    return true;
  }

private:
  time_t m_lastCalled;
  time_t m_interval;
};

}
