set(SWIFT_TOOLS_SRCS
  CrashReporter.cpp
  Application/ApplicationPathProvider.cpp
  Application/UnixApplicationPathProvider.cpp
  EmojiMapper.cpp
  Idle/IdleDetector.cpp
  Idle/ActualIdleDetector.cpp
  Idle/IdleQuerier.cpp
  Idle/PlatformIdleQuerier.cpp
  AutoUpdater/AutoUpdater.cpp
  AutoUpdater/PlatformAutoUpdaterFactory.cpp
  Linkify.cpp
  TabComplete.cpp
  LastLineTracker.cpp
  Dock/Dock.cpp
  Notifier/Notifier.cpp
  URIHandler/XMPPURI.cpp
  URIHandler/URIHandler.cpp
)

add_library(swift_tools ${SWIFT_TOOLS_SRCS})
target_include_directories(swift_tools PRIVATE ../)
