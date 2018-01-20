/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#pragma once

#include <future>

namespace System {

namespace Detail {

template<class T> using Future = std::future<T>;

template<class T> Future<T> async(std::function<T()>&& operation) {
  return std::async(std::launch::async, std::move(operation));
}

}

}

