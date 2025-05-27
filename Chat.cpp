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

std::shared_ptr<User> Chat::getUserByName(const std::string& name) const
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

void Chat::showUserMenu()
{
	char operation;
	std::cout << "Hi" << _currentUser->getName() << std::endl;
	while (_currentUser) {
		std::cout << "Menu: (1)Show chat | (2)Add message | (3)User | (0)Logout";
		std::cout << std::endl << ">> ";
		std::cin >> operation;

		switch (operation)
		{
		case '1':
			showChat();
			break;
		case '2':
			addMessage();
			break;
		case '3':
			showAllUserName();
			break;
		case '0':
			_currentUser = nullptr;
			break;
		default:
			std::cout << "unknown choice.." << std::endl;
			break;
		}
	}
}

void Chat::registration()
{
	std::string login, password, name;

	std::cout << "login: ";
	std::cin >> login;
	std::cout << "password: ";
	std::cin >> password;
	std::cout << "name: ";
	std::cin >> name;

	if (getUserByLogin(login) || login == "all")
	{
		throw UserLoginExp();
	}
	if (getUserByName(name) || name == "all")
	{
		throw UserNameExp;
	}

	User user = User(login, password, name);
	_userList.push_back(user);
	_currentUser = std::make_shared<User>(user);
}

void Chat::addMessage()
{
	std::string to, text;

	std::cout << "To (name or all): ";
	std::cin >> to;
	std::cout << "Text: ";
	std::cin.ignore();
	getline(std::cin, text);

	if (!(to == "all" || getUserByName(to)))
	{
		std::cout << "error" << std::endl;
		return;
	}
	if (to == "all")
		_messageList.push_back(Message{ _currentUser->getLogin(), "all",text });
	else
		_messageList.push_back(Message{_currentUser->getLogin(),getUserByName(to)->getLogin(), text})
}

void Chat::showChat() const
{
	std::string from, to;

	std::cout << "--- Chat ---" << std::endl;

	for (auto& mess : _messageList)
	{

		if (_currentUser->getLogin() == mess.getFrom() || _currentUser->getLogin() == mess.getTo() == "all")
		{
			from = (_currentUser->getLogin() == mess.getFrom()) ? "me" : getUserByLogin(mess.getFrom())->getName();

			if (mess.getTo() == "all")
			{
				to = "(all)";
			}
			else
			{
				to == (_currentUser->getLogin() == mess.getTo()) ? "me" : getUserByLogin(mess.getTo())->getName();
			}

			std::cout << "Message from " << from << " to " << to << std::endl;
			std::cout << "Text: " << mess.getText() << std::endl;
		}
	}
	std::cout << "-------------" << std::endl;
}
