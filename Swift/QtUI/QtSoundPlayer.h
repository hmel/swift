/*
 * Copyright (c) 2010-2016 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#pragma once

#include <map>
#include <memory>

#include <QObject>
#include <QSoundEffect>

#include <Swift/Controllers/SoundPlayer.h>
#include <qt5/QtMultimedia/qsound.h>

namespace Swift {
  class ApplicationPathProvider;

  class QtSoundPlayer : public QObject, public SoundPlayer {
    Q_OBJECT
  public:
    QtSoundPlayer(ApplicationPathProvider* applicationPathProvider);

    void playSound(SoundEffect sound, const std::string& soundResource);

  private:
    void playSound(const std::string& soundResource);
    void loadSound(SoundEffect sound, const std::string& soundResource);

  private:
    ApplicationPathProvider* applicationPathProvider;
    std::map<SoundEffect, std::unique_ptr<QSoundEffect>> soundEffects;
  };
} // namespace Swift
