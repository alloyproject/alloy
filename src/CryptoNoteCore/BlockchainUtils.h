/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#pragma once

#include <vector>

#include "CachedTransaction.h"
#include "CryptoNote.h"
#include "CryptoNoteTools.h"

namespace CryptoNote {
namespace Utils {

bool restoreCachedTransactions(const std::vector<BinaryArray>& binaryTransactions, std::vector<CachedTransaction>& transactions);

} //namespace Utils
} //namespace CryptoNote
