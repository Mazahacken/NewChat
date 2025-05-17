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

void Chat::login()
{
	std::string login;
	std::string password;
	char operation;

	do
	{
		std::cout << "login";
		std::cin >> login;
		std::cout << "password: ";
		std::cin >> password;

		_currentUser = getUserByLogin(login);
		if (_currentUser == nullptr || (password != _currentUser->getPassword()))
		{
			_currentUser = nullptr;
			std::cout << "login failed...  (0)exit";
			std::cin >> operation;
			if (operation == '0')
				break;
		}

	} while (!_currentUser);
}