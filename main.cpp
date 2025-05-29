#include "Chat.h"

auto main() -> int {

	Chat chat;
	chat.start();

	while (chat.isChatWork()) {
		chat.showLoginMenu();

		while (chat.getCureentUser())
		{
			chat.showUserMenu();
		}
	}
}