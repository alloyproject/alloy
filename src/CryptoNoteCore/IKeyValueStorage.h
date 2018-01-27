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

#include <vector>

namespace CryptoNote {

class WriteBatch;
class ReadBatch;

class IKeyValueStorage {
public:
  virtual ~IKeyValueStorage() {
  }

  virtual bool insert(const WriteBatch& batch, bool sync = false) = 0;
  virtual void read(const ReadBatch& batch) const = 0;
};
}
