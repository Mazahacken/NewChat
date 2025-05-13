#pragma once
#include <vector>
#include <exception>
#include <memory>
#include "Message.h"

struct UserLoginExp{};

struct UserNameExp{};

class Chat {
	bool _isChatWork = false;
	std::vector<User> _userList;
	std::vector<Message> _messageList;
	std::shared_ptr<User> _currentUser = nullptr;

	void login();
	void singUp();
	void showChat() const;
	void showAllUserName() const;
	void addMessage();
	std::vector<User>& getAllUsers() { return _userList; }
	std::vector<Message>& getAllMessages() { return _messageList; }
	std::shared_ptr<User> getUserByLogin(const std::string& login) const;

public:
	void start();
	bool isChatWork() const { return _isChatWork; }
	std::shared_ptr<User> getCureentUser() const { return _currentUser; }
	void showLoginMenu();
	void showUserMenu();


};
