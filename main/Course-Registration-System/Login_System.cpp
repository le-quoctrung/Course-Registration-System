#include "Login_System.h"

bool checkFile(std::string name)
{
	std::ifstream check("db\\" + name + ".txt");
	if (check.is_open())
	{
		check.close();
		return true;
	}
	return false;
}

void registering(std::string name, std::string pass, int type)
{
	std::ofstream write("db\\" + name + ".txt", std::ios::out);
	if (write.is_open())
	{
		write << name << std::endl;
		write << pass << std::endl;
		write << type;
		write.close();
	}
}

void registering(student user, std::string pass)
{
	std::ofstream write("db\\" + user.ID + ".txt");
	if (write.is_open())
	{
		write << user.ID << std::endl;
		write << pass << std::endl;
		write << 0;
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

void changePass(std::string name, std::string pass)
{
	registering(name, pass, 1);
}

void changePass(student user, std::string pass)
{
	registering(user,pass);
}

void login()
{
	string name="", pass = "";
	char chpass, chname;
	cout << "username: ";
	cin >> name;
	//chname = _getch();
	//while (chname != 13) {//character 13 is enter
	//	if (chname == '\b' && name.length() >= 1)//if user typed backspace 
	//	{
	//		cout << "\b \b";//rub the character behind the cursor.
	//		pass.pop_back();
	//	}
	//	else
	//	{
	//		pass.push_back(chname);
	//	}
	//	chpass = _getch();
	//}
	//cout << name;
	//
	//
	
	cout << "\npassword: ";
	chpass = _getch();
	while (chpass != 13) {//character 13 is enter
		if (chpass == '\b' && pass.length() >= 1)//if user typed backspace 
		{
			cout << "\b \b";//rub the character behind the cursor.
			pass.pop_back();
		}
		else
		{
			pass.push_back(chpass);
			cout << '*';
		}
		chpass = _getch();
	}
	cout << pass;

	switch (checkLogin(name,pass))
	{
	case 404: cout << "Login failed. Account not found"; break;
	case -1: cout << "Login failed. Wrong password"; break;
		break;
	}
}