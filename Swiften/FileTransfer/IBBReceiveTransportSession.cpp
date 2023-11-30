/*
 * Copyright (c) 2015-2016 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#include <Swiften/FileTransfer/IBBReceiveTransportSession.h>

#include <boost/bind.hpp>
using namespace boost::placeholders;

namespace Swift {

  IBBReceiveTransportSession::IBBReceiveTransportSession(std::shared_ptr<IBBReceiveSession> session) : session(session) {
    finishedConnection = session->onFinished.connect(boost::bind(boost::ref(onFinished), _1));
  }

  IBBReceiveTransportSession::~IBBReceiveTransportSession() {}

  void IBBReceiveTransportSession::start() {
    session->start();
  }

  void IBBReceiveTransportSession::stop() {
    session->stop();
  }

} // namespace Swift
