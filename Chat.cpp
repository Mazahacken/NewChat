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

void Chat::showLoginMenu()
{
	_currentUser = nullptr;

	char operation;

	do
	{
		std::cout << "\033[33m" << "(1)Login" << std::endl;
		std::cout << "(2)Registration" << std::endl;
		std::cout << "(0)Exit" << std::endl;
		std::cin >> operation;
		
		switch (operation)
		{
		case '1':
			login();
			break;
		case '2':
			try
			{
				registration()
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
			break;
		case '0':
			_isChatWork = false;
			break;
		default:
			std::cout << "Enter 1 or 2" << std::endl;
			break;
		}
	} while (!_currentUser && _isChatWork);
}