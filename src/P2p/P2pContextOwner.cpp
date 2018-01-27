/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#include "P2pContextOwner.h"
#include <cassert>
#include "P2pContext.h"

namespace CryptoNote {

P2pContextOwner::P2pContextOwner(P2pContext* ctx, ContextList& contextList) : contextList(contextList) {
  contextIterator = contextList.insert(contextList.end(), ContextList::value_type(ctx));
}

P2pContextOwner::P2pContextOwner(P2pContextOwner&& other) : contextList(other.contextList), contextIterator(other.contextIterator) {
  other.contextIterator = contextList.end();
}

P2pContextOwner::~P2pContextOwner() {
  if (contextIterator != contextList.end()) {
    contextList.erase(contextIterator);
  }
}

P2pContext& P2pContextOwner::get() {
  assert(contextIterator != contextList.end());
  return *contextIterator->get();
}

P2pContext* P2pContextOwner::operator -> () {
  return &get();
}

}
