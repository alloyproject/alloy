/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#include "ErrorMessage.h"

#ifndef NOMINMAX
#define NOMINMAX
#endif

#include <cstddef>
#include <windows.h>

namespace System {

std::string lastErrorMessage() {
  return errorMessage(GetLastError());
}

std::string errorMessage(int error) {
  struct Buffer {
    ~Buffer() {
      if (pointer != nullptr) {
        LocalFree(pointer);
      }
    }

    LPTSTR pointer = nullptr;
  } buffer;

  auto size = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER, nullptr, error,
                            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), reinterpret_cast<LPTSTR>(&buffer.pointer), 0, nullptr);
  return "result=" + std::to_string(error) + ", " + std::string(buffer.pointer, size);
}

}
