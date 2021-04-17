#include "Login_System.h"

int checkLogin(std::string name, std::string pass)
{
	if (!checkFile(name)) return 404;

	std::ifstream file("db\\students.txt", std::ios::in);
	if (file.is_open())
	{
		std::string check;
		std::vector<std::string> line;

		while (!file.eof())
		{
			std::getline(file, check);

			line = split(check, ",");

			if (name == line[0])
			{
				//check password
				if (pass != line[1])
				{
					return -1;
				}
				else return 0;
			}
		}
		file.close();
	}

	file.open("db\\staffs.txt", std::ios::in);
	if (file.is_open())
	{
		std::string check;
		std::vector<std::string> line;

		while (!file.eof())
		{
			std::getline(file, check);

			line = split(check, ",");

			if (name == line[0])
			{
				//check password
				if (pass != line[1])
				{
					return -1;
				}
				else return 1;
			}
		}
		file.close();
	}

	return 404;
}

void login()
{
	string name="", pass = "";
	char chpass, chname;
	
	Gotoxy(80, 13);
	chname = _getch();
	while (chname != 13) {//character 13 is enter
		if (name.length() > 7 && chname != '\b') chname = '\0';
		else if (chname == '\b' && name.length() >= 1)//if user typed backspace 
		{
			cout << "\b \b";//rub the character behind the cursor.
			name.pop_back();
		}
		else if (chname == '\b' && name.length() == 0) chname = '\0';
		else
		{
			name.push_back(chname);
			cout << chname;
		}
		chname = _getch();
	}	

	Gotoxy(80, 15);
	chpass = _getch();
	while (chpass != 13) {//character 13 is enter
		if (pass.length() > 16 && chpass != '\b') chpass = '\0';
		else if (chpass == '\b' && pass.length() >= 1)//if user typed backspace 
		{
			cout << "\b \b";//rub the character behind the cursor.
			pass.pop_back();
		}
		else if (chpass == '\b' && pass.length() == 0) chpass = '\0';
		else
		{
			pass.push_back(chpass);
			cout << '*';
		}
		chpass = _getch();
	}
	system("cls");
	switch (checkLogin(name,pass))
	{
	case 404: home(); Gotoxy(80, 17); cout << "Login failed. Account not found"; break;
	case -1: home(); Gotoxy(80, 17); cout << "Login failed. Wrong password"; break;
	case 1: break;
	case -2: break;
	case 0: break;
		break;
	}
}