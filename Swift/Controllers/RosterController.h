#ifndef SWIFTEN_RosterController_H
#define SWIFTEN_RosterController_H

#include "Swiften/JID/JID.h"
#include "Swiften/Base/String.h"
#include "Swiften/Elements/Presence.h"
#include "Swiften/Roster/UserRosterAction.h"
#include "Swiften/Avatars/AvatarManager.h"

#include <boost/signals.hpp>
#include <boost/shared_ptr.hpp>

namespace Swift {
	class IQRouter;
	class Roster;
	class XMPPRoster;
	class MainWindow;
	class MainWindowFactory;
	class TreeWidgetFactory;
	class OfflineRosterFilter;

	class RosterController {
		public:
			RosterController(boost::shared_ptr<XMPPRoster> xmppRoster, AvatarManager* avatarManager, MainWindowFactory *mainWindowFactory, TreeWidgetFactory *treeWidgetFactory);
			~RosterController();
			void showRosterWindow();
			MainWindow* getWindow() {return mainWindow_;};
			boost::signal<void (const JID&)> onStartChatRequest;
			boost::signal<void (const JID&, const String&)> onJoinMUCRequest;
			boost::signal<void (StatusShow::Type, const String&)> onChangeStatusRequest;
			void handleIncomingPresence(boost::shared_ptr<Presence> presence);
			void handleAvatarChanged(const JID& jid, const String& hash);

		private:
			void handleOnJIDAdded(const JID &jid);
			void handleStartChatRequest(const JID& contact);
			void handleJoinMUCRequest(const JID &muc, const String &nick);
			void handleUserAction(boost::shared_ptr<UserRosterAction> action);
			void handleChangeStatusRequest(StatusShow::Type show, const String &statusText);
			void handleShowOfflineToggled(bool state);
			boost::shared_ptr<XMPPRoster> xmppRoster_;
			MainWindowFactory* mainWindowFactory_;
			TreeWidgetFactory* treeWidgetFactory_;
			MainWindow* mainWindow_;
			Roster* roster_;
			OfflineRosterFilter* offlineFilter_;
			AvatarManager* avatarManager_;
	};
}
#endif

