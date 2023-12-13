/*
 * Copyright (c) 2010-2016 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#include <Swift/QtUI/QtSoundPlayer.h>

#include <iostream>

#include <Swiften/Base/Path.h>
#include <Swiften/Base/Log.h>

#include <SwifTools/Application/ApplicationPathProvider.h>

#include <Swift/QtUI/QtSwiftUtil.h>
#include <memory>
#include <qt5/QtMultimedia/qsound.h>

namespace Swift {

  QtSoundPlayer::QtSoundPlayer(ApplicationPathProvider* applicationPathProvider) : applicationPathProvider(applicationPathProvider) {}

  void QtSoundPlayer::playSound(SoundEffect sound, const std::string& soundResource) {

    auto s = soundEffects.find(sound);
    if (s == soundEffects.end()) {
      switch (sound) {
        case MessageReceived:
          loadSound(sound, soundResource.empty() ? "/sounds/message-received.wav" : soundResource);
          break;
        default:
          SWIFT_LOG(warning) << "Trying to play unknown sound" << sound;
      }
    }
    if (soundEffects.find(sound) != soundEffects.end()) {
      soundEffects[sound]->play();
    }
  }

  void QtSoundPlayer::loadSound(SoundEffect sound, const std::string& soundResource) {
    boost::filesystem::path resourcePath = applicationPathProvider->getResourcePath(soundResource);
    if (boost::filesystem::exists(resourcePath)) {
      std::unique_ptr<QSoundEffect> effect = std::make_unique<QSoundEffect>();
      effect->setSource(QUrl::fromLocalFile(P2QSTRING(pathToString(resourcePath))));
      soundEffects.emplace(sound, std::move(effect));
    }
    else if (boost::filesystem::exists(soundResource)) {
      std::unique_ptr<QSoundEffect> effect = std::make_unique<QSoundEffect>();
      effect->setSource(QUrl::fromLocalFile(P2QSTRING(pathToString(soundResource))));
      soundEffects.emplace(sound, std::move(effect));
    }
    else {
      SWIFT_LOG(warning) << "Unable to find sound: " << soundResource;
    }
  }

  void QtSoundPlayer::playSound(const std::string& soundResource) {}

} // namespace Swift
