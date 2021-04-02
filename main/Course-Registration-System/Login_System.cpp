#include "Login_System.h"

bool checkFile(std::string name)
{
	std::ifstream check(name + ".txt");
	if (check.is_open())
	{
		check.close();
		return true;
	}
	return false;
}

void registering(std::string name, std::string pass, int type)
{
	std::ofstream write(name + ".txt", std::ios::out);
	if (write.is_open())
	{
		write << name << std::endl;
		write << pass << std::endl;
		write << type;
		write.close();
	}
}

int checkLogin(std::string name, std::string pass)
{
	if (!checkFile(name)) return 404;

	std::ifstream file(name + ".txt", std::ios::in);
	if (file.is_open())
	{
		std::string check;
		int type;

		std::getline(file, check);

		//check name
		if (check.compare(name) != 0)
		{
			//username doesn't match with file's name
			//file might be tampered
			return -2;
		}

		file >> check;

		//check password
		if (check.compare(pass) != 0)
		{
			return -1;
		}

		file >> type;

		//check type of user
		//return -2 if type isn't [0;1]
		if (type == 0) return 0;
		else if (type == 1) return 1;
		else return -2;

		file.close();
	}

}

User viewProfile(std::string name)
{
	User _user;

	std::ifstream file(name + ".txt", std::ios::in);
	if (file.is_open())
	{
		std::getline(file, _user._name);
		file >> _user._pass;
		file >> _user.type;

		file.close();
	}
	return _user;
}

void changePass(User _user, std::string pass)
{
	registering(_user._name, pass, _user.type);
}