#include <string>

class User {
	const std::string _login;
	std::string _password;
	std::string _name;
public:
	User(std::string login,std::string password,std::string name): _login(login), _password(password), _name(name){}
	const std::string getLogin() const { return _login; };
	const std::string getPassword() const { return _password; };
	void setPassword(std::string password) { _password = password; };
	const std::string getName() const { return _name; };
	void setPassword(std::string name) { _name = name; };

};
	
	