/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#include "gtest/gtest.h"
#include <Common/JsonValue.h>

using Common::JsonValue;

namespace {

std::vector<std::string> goodPatterns{
  "{}",
  "   {}   ",
  "   {   }   ",
  "100",
  "[10,20,30]",
  "  [  10  , \n 20  , \n  30  ]  ",
  "{\"prop\": 100}",
  "{\"prop\": 100, \"prop2\": [100, 20, 30] }",
  "{\"prop\": 100, \"prop2\": { \"p\":\"test\" } }",

};


std::vector<std::string> badPatterns{
  "",
  "1..2",
  "\n\n",
  "{",
  "[",
  "[100,",
  "[[]",
  "\"",
  "{\"prop: 100 }",
  "{\"prop\" 100 }",
  "{ prop: 100 }",
};

}

TEST(JsonValue, testGoodPatterns) {
  for (const auto& p : goodPatterns) {
    std::cout << "Pattern: " << p << std::endl;
    ASSERT_NO_THROW(Common::JsonValue::fromString(p));
  }
}

TEST(JsonValue, testBadPatterns) {
  for (const auto& p : badPatterns) {
    ASSERT_ANY_THROW(Common::JsonValue::fromString(p));
  }
}

