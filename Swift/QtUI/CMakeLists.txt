project(swift)

set(SWIFT_SRCS
  main.cpp

  FreeDesktopNotifier.cpp
  QtDBUSURIHandler.cpp

  QtCertificateViewerDialog.cpp

  ChatList/ChatListDelegate.cpp
  ChatList/ChatListModel.cpp
  ChatList/ChatListMUCItem.cpp
  ChatList/ChatListRecentItem.cpp
  ChatList/ChatListWhiteboardItem.cpp
  ChatList/QtChatListWindow.cpp
  ChattablesModel.cpp
  ChatSnippet.cpp
  EventViewer/EventDelegate.cpp
  EventViewer/EventModel.cpp
  EventViewer/QtEvent.cpp
  EventViewer/QtEventWindow.cpp
  EventViewer/TwoLineDelegate.cpp
  FlowLayout.cpp
  MessageSnippet.cpp
  MUCSearch/MUCSearchDelegate.cpp
  MUCSearch/MUCSearchEmptyItem.cpp
  MUCSearch/MUCSearchModel.cpp
  MUCSearch/MUCSearchRoomItem.cpp
  MUCSearch/MUCSearchServiceItem.cpp
  MUCSearch/QtLeafSortFilterProxyModel.cpp
  MUCSearch/QtMUCSearchWindow.cpp
  ServerList/ServerListDelegate.cpp
  ServerList/ServerListModel.cpp
  ServerList/QtServerListView.cpp
  #qrc_DefaultTheme.cc
  #qrc_Swift.cc
  QtAboutWidget.cpp
  QtAddBookmarkWindow.cpp
  QtAdHocCommandWindow.cpp
  QtAdHocCommandWithJIDWindow.cpp
  QtAffiliationEditor.cpp
  QtAvatarWidget.cpp
  QtBlockListEditorWindow.cpp
  QtBookmarkDetailWindow.cpp
  QtCachedImageScaler.cpp
  QtChatOverview.cpp
  QtChatOverviewBundle.cpp
  QtChatOverviewDelegate.cpp
  QtChatTabs.cpp
  QtChatTabsBase.cpp
  QtChatTheme.cpp
  QtChatView.cpp
  QtChatWindow.cpp
  QtChatWindowFactory.cpp
  QtChatWindowJSBridge.cpp
  QtCheckBoxStyledItemDelegate.cpp
  QtClickableLabel.cpp
  QtClosableLineEdit.cpp
  QtColorSelectionStyledItemDelegate.cpp
  QtColorToolButton.cpp
  QtConnectionSettingsWindow.cpp
  QtContactEditWidget.cpp
  QtContactEditWindow.cpp
  QtEditBookmarkWindow.cpp
  QtElidingLabel.cpp
  QtEmojiCell.cpp
  QtEmojisGrid.cpp
  QtEmojisScroll.cpp
  QtEmojisSelector.cpp
  QtEmoticonsGrid.cpp
  QtExpandedListView.cpp
  QtFdpFormSubmitWindow.cpp
  QtFileTransferListItemModel.cpp
  QtFileTransferListWidget.cpp
  QtFormResultItemModel.cpp
  QtFormWidget.cpp
  QtHighlightNotificationConfigDialog.cpp
  QtHistoryWindow.cpp
  QtJoinMUCWindow.cpp
  QtLineEdit.cpp
  QtListWidget.cpp
  QtLoginWindow.cpp
  QtMainWindow.cpp
  QtMUCConfigurationWindow.cpp
  QtNameWidget.cpp
  QtPlainChatView.cpp
  QtProfileWindow.cpp
  QtRecentEmojisGrid.cpp
  QtResourceHelper.cpp
  QtRosterHeader.cpp
  QtScaledAvatarCache.cpp
  QtSettingsProvider.cpp
  QtSingleWindow.cpp
  QtSoundPlayer.cpp
  QtSoundSelectionStyledItemDelegate.cpp
  QtSpellCheckerWindow.cpp
  QtSpellCheckHighlighter.cpp
  QtStatusWidget.cpp
  QtSubscriptionRequestWindow.cpp
  QtSwift.cpp
  QtSystemTray.cpp
  QtTabbable.cpp
  QtTabWidget.cpp
  QtTextEdit.cpp
  QtUIFactory.cpp
  QtUISettingConstants.cpp
  QtUpdateFeedSelectionDialog.cpp
  QtURIHandler.cpp
  QtURLValidator.cpp
  QtUtilities.cpp
  QtWebKitChatView.cpp
  QtWebView.cpp
  QtXMLConsoleWidget.cpp
  QtCertificateViewerDialog.cpp
  Roster/DelegateCommons.cpp
  Roster/GroupItemDelegate.cpp
  Roster/QtFilterWidget.cpp
  Roster/QtOccupantListWidget.cpp
  Roster/QtRosterWidget.cpp
  Roster/QtTreeWidget.cpp
  Roster/RosterDelegate.cpp
  Roster/RosterModel.cpp
  Roster/RosterTooltip.cpp
  SystemMessageSnippet.cpp
  Trellis/QtDNDTabBar.cpp
  Trellis/QtDynamicGridLayout.cpp
  Trellis/QtGridSelectionDialog.cpp
  UserSearch/ContactListDelegate.cpp
  UserSearch/ContactListModel.cpp
  UserSearch/QtContactListWidget.cpp
  UserSearch/QtSuggestingJIDInput.cpp
  UserSearch/QtUserSearchDetailsPage.cpp
  UserSearch/QtUserSearchFieldsPage.cpp
  UserSearch/QtUserSearchFirstMultiJIDPage.cpp
  UserSearch/QtUserSearchFirstPage.cpp
  UserSearch/QtUserSearchResultsPage.cpp
  UserSearch/QtUserSearchWindow.cpp
  UserSearch/UserSearchDelegate.cpp
  UserSearch/UserSearchModel.cpp
  Whiteboard/ColorWidget.cpp
  Whiteboard/FreehandLineItem.cpp
  Whiteboard/GView.cpp
  Whiteboard/QtWhiteboardWindow.cpp
  Whiteboard/TextDialog.cpp

  QtVCardWidget/QtCloseButton.cpp
  QtVCardWidget/QtRemovableItemDelegate.cpp
  QtVCardWidget/QtResizableLineEdit.cpp
  QtVCardWidget/QtTagComboBox.cpp
  QtVCardWidget/QtVCardHomeWork.cpp
  QtVCardWidget/QtVCardAddressField.cpp
  QtVCardWidget/QtVCardAddressLabelField.cpp
  QtVCardWidget/QtVCardBirthdayField.cpp
  QtVCardWidget/QtVCardDescriptionField.cpp
  QtVCardWidget/QtVCardInternetEMailField.cpp
  QtVCardWidget/QtVCardJIDField.cpp
  QtVCardWidget/QtVCardOrganizationField.cpp
  QtVCardWidget/QtVCardPhotoAndNameFields.cpp
  QtVCardWidget/QtVCardRoleField.cpp
  QtVCardWidget/QtVCardTelephoneField.cpp
  QtVCardWidget/QtVCardTitleField.cpp
  QtVCardWidget/QtVCardURLField.cpp
  QtVCardWidget/QtVCardGeneralField.cpp
  QtVCardWidget/QtVCardWidget.cpp
)


set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Gui X11Extras DBus Widgets WebKitWidgets Multimedia Svg)
find_package(Boost REQUIRED COMPONENTS program_options filesystem serialization regex)
find_package(PkgConfig REQUIRED)
pkg_check_modules(IDN REQUIRED IMPORTED_TARGET libidn)
if(${IDN_FOUND})
    MESSAGE(${PKG_CONFIG_EXECUTABLE})
    MESSAGE(${IDN_LIBRARIES})
    MESSAGE(${IDN_LINK_LIBRARIES})
endif()


add_executable(Swift ${SWIFT_SRCS})

target_link_libraries(Swift Qt5::Core Qt5::Gui Qt5::DBus Qt5::X11Extras Qt5::Widgets Qt5::WebKitWidgets Qt5::Multimedia
  swift_controllers
  swift_tools
  swiften
  Boost::filesystem
  Boost::program_options
  Boost::serialization
  Boost::regex
  Boost::serialization
  resolv
  ssl
  crypto
  expat
  ${IDN_LIBRARIES}
  z
)

target_include_directories(Swift PRIVATE ../../ ../ QtVCardWidget/)
