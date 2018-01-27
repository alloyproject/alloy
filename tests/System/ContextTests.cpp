/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#include <System/Context.h>
#include <System/Dispatcher.h>
#include <System/Event.h>
#include <System/InterruptedException.h>
#include <System/Timer.h>
#include <gtest/gtest.h>

using namespace System;

TEST(ContextTests, getReturnsResult) {
  Dispatcher dispatcher;
  Context<int> context(dispatcher, [&] { 
    return 2; 
  });

  ASSERT_EQ(2, context.get());
}

TEST(ContextTests, getRethrowsException) {
  Dispatcher dispatcher;
  Context<> context(dispatcher, [&] {
    throw std::string("Hi there!"); 
  });

  ASSERT_THROW(context.get(), std::string);
}

TEST(ContextTests, destructorIgnoresException) {
  Dispatcher dispatcher;
  ASSERT_NO_THROW(Context<>(dispatcher, [&] {
    throw std::string("Hi there!");
  }));
}

TEST(ContextTests, interruptIsInterrupting) {
  Dispatcher dispatcher;
  Context<> context(dispatcher, [&] {
    if (dispatcher.interrupted()) {
      throw InterruptedException();
    }
  });

  context.interrupt();
  ASSERT_THROW(context.get(), InterruptedException);
}

TEST(ContextTests, getChecksInterruption) {
  Dispatcher dispatcher;
  Event event(dispatcher);
  Context<int> context1(dispatcher, [&] {
    event.wait();
    if (dispatcher.interrupted()) {
      return 11;
    }

    return 10;
  });

  Context<int> context2(dispatcher, [&] {
    event.set();
    return context1.get();
  });

  context2.interrupt();
  ASSERT_EQ(11, context2.get());
}

TEST(ContextTests, getIsInterruptible) {
  Dispatcher dispatcher;
  Event event1(dispatcher);
  Event event2(dispatcher);
  Context<int> context1(dispatcher, [&] {
    event2.wait();
    if (dispatcher.interrupted()) {
      return 11;
    }

    return 10;
  });

  Context<int> context2(dispatcher, [&] {
    event1.set();
    return context1.get();
  });

  event1.wait();
  context2.interrupt();
  event2.set();
  ASSERT_EQ(11, context2.get());
}

TEST(ContextTests, destructorInterrupts) {
  Dispatcher dispatcher;
  bool interrupted = false;
  {
    Context<> context(dispatcher, [&] {
      if (dispatcher.interrupted()) {
        interrupted = true;
      }
    });
  }

  ASSERT_TRUE(interrupted);
}
