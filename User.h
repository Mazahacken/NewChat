#include <string>

class User {
	const std::string _login;
	std::string _password;
	std::string _name;
public:
	User(std::string login,std::string password,std::string name): _login(login), _password(password), _name(name){}
	const std::string getLogin() const { return _login; };


};
	
	