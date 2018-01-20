/*
 * Copyright (c) 2017-2018, The Alloy Developers.
 *
 * This file is part of Alloy.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#pragma once

namespace System {

class Dispatcher;
class Event;

class RemoteEventLock {
public:
  RemoteEventLock(Dispatcher& dispatcher, Event& event);
  ~RemoteEventLock();

private:
  Dispatcher& dispatcher;
  Event& event;
};

}
