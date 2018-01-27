/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#include <gtest/gtest.h>
#include <System/OperationTimeout.h>
#include <System/InterruptedException.h>

using namespace System;

class OperationTimeoutTest : public testing::Test {
public:
  OperationTimeoutTest() : contextGroup(dispatcher), timer(dispatcher) {
  }

  Dispatcher dispatcher;
  ContextGroup contextGroup;
  Timer timer;
};

TEST_F(OperationTimeoutTest, DISABLED_timeoutHappens) {
  OperationTimeout<Timer> op(dispatcher, timer, std::chrono::milliseconds(100));
  contextGroup.spawn([&] { 
    EXPECT_THROW(timer.sleep(std::chrono::milliseconds(200)), InterruptedException); 
  });
  contextGroup.wait();
}

TEST_F(OperationTimeoutTest, DISABLED_timeoutSkipped) {
  {
    OperationTimeout<Timer> op(dispatcher, timer, std::chrono::milliseconds(200));
    contextGroup.spawn([&] { 
      EXPECT_NO_THROW(timer.sleep(std::chrono::milliseconds(100)));
    });
    contextGroup.wait();
  }
}

TEST_F(OperationTimeoutTest, DISABLED_noOperation) {
  {
    OperationTimeout<Timer> op(dispatcher, timer, std::chrono::milliseconds(100));
  }
}
