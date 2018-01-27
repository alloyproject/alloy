/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#include "UpgradeManager.h"

#include "CryptoNoteConfig.h"

namespace CryptoNote {

UpgradeManager::UpgradeManager() {
}

UpgradeManager::~UpgradeManager() {
}

void UpgradeManager::addMajorBlockVersion(uint8_t targetVersion, uint32_t upgradeHeight) {
  assert(m_upgradeDetectors.empty() || m_upgradeDetectors.back()->targetVersion() < targetVersion);
  m_upgradeDetectors.emplace_back(makeUpgradeDetector(targetVersion, upgradeHeight));
}

uint8_t UpgradeManager::getBlockMajorVersion(uint32_t blockIndex) const {
  for (auto it = m_upgradeDetectors.rbegin(); it != m_upgradeDetectors.rend(); ++it) {
    if (it->get()->upgradeIndex() < blockIndex) {
      return it->get()->targetVersion();
    }
  }

  return BLOCK_MAJOR_VERSION_1;
}

}
