#include <iostream>
#include "Chat.h"

void Chat::start() {
	_isChatWork = true;
}

std::shared_ptr<User> Chat::getUserByLogin(const std::string& login) const
{
	for (auto& user : _userList)
	{
		if (login == user.getLogin())
			return std::make_shared<User>(user);
	}
	return nullptr;
}

std::shared_ptr<User> Chat::getUserByLogin(const std::string name) const
{
	for (auto& user : _userList)
	{
		if (name == user.getName())
			return std::make_shared<User>(user);
	}
	return nullptr;
}