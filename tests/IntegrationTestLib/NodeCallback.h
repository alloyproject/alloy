/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#include <future>
#include <INode.h>

namespace Tests {

class NodeCallback {
public:
  CryptoNote::INode::Callback callback() {
    prom = std::promise<std::error_code>(); // reset std::promise
    result = prom.get_future();
    return [this](std::error_code ec) {
      std::promise<std::error_code> localPromise(std::move(prom));
      localPromise.set_value(ec);
    };
  }

  std::error_code get() {
    return result.get();
  }

private:
  std::promise<std::error_code> prom;
  std::future<std::error_code> result;
};

}
