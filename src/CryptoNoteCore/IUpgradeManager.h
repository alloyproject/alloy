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

#include <cstdint>

namespace CryptoNote {

class IUpgradeManager {
public:
  virtual ~IUpgradeManager() {}

  virtual void addMajorBlockVersion(uint8_t targetVersion, uint32_t upgradeHeight) = 0;
  virtual uint8_t getBlockMajorVersion(uint32_t blockIndex) const = 0;
};

}
