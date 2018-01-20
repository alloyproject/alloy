/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#include "crypto/random.c"

#include "crypto-tests.h"

void setup_random(void) {
    memset(&state, 42, sizeof(union hash_state));
}
