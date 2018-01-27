/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#include "UpgradeDetector.h"
#include "IUpgradeDetector.h"

namespace CryptoNote {

class SimpleUpgradeDetector : public IUpgradeDetector {
public:
  SimpleUpgradeDetector(uint8_t targetVersion, uint32_t upgradeIndex) :
    m_targetVersion(targetVersion), m_upgradeIndex(upgradeIndex) {
  }
 
  uint8_t targetVersion() const override {
    return m_targetVersion;
  }
  
  uint32_t upgradeIndex() const override {
    return m_upgradeIndex;
  }

  ~SimpleUpgradeDetector() override {
  }

private:
  uint8_t m_targetVersion;
  uint32_t m_upgradeIndex;
};

std::unique_ptr<IUpgradeDetector> makeUpgradeDetector(uint8_t targetVersion, uint32_t upgradeIndex) {
  return std::unique_ptr<SimpleUpgradeDetector>(new SimpleUpgradeDetector(targetVersion, upgradeIndex));
}

}
