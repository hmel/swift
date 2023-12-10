/*
 * Copyright (c) 2010-2016 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#include <Swift/QtUI/QtSoundPlayer.h>

#include <iostream>

#include <QSoundEffect>

#include <Swiften/Base/Path.h>

#include <SwifTools/Application/ApplicationPathProvider.h>

#include <Swift/QtUI/QtSwiftUtil.h>

namespace Swift {

  QtSoundPlayer::QtSoundPlayer(ApplicationPathProvider* applicationPathProvider) : applicationPathProvider(applicationPathProvider) {}

  void QtSoundPlayer::playSound(SoundEffect sound, const std::string& soundResource) {

    switch (sound) {
      case MessageReceived:
        playSound(soundResource.empty() ? "/sounds/message-received.wav" : soundResource);
        break;
    }
  }

  void QtSoundPlayer::playSound(const std::string& soundResource) {
    boost::filesystem::path resourcePath = applicationPathProvider->getResourcePath(soundResource);
    if (boost::filesystem::exists(resourcePath)) {
      QSoundEffect effect;
      effect.setSource(QUrl::fromLocalFile(P2QSTRING(pathToString(resourcePath))));
      effect.play();
    }
    else if (boost::filesystem::exists(soundResource)) {
      QSoundEffect effect;
      effect.setSource(QUrl::fromLocalFile(P2QSTRING(pathToString(soundResource))));
      effect.play();
    }
    else {
      std::cerr << "Unable to find sound: " << soundResource << std::endl;
    }
  }

} // namespace Swift
