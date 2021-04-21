#include "Login_System.h"

void login()
{
	string name = "", pass = "";
	char chpass, chname;

	Gotoxy(80, 13);
	chname = _getch();
	while (chname != 13) {//character 13 is enter
		if (name.length() > 50 && chname != '\b') chname = '\0';
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
	switch (CheckLogin(name, pass))
	{
	case 404:
	{
		home();
		Gotoxy(80, 17);
		cout << "Login failed. Account not found!";
		break;
	}
	case -1:
	{
		home();
		Gotoxy(80, 17);
		cout << "Login failed. Username and Password missmatch!";
		break;
	}
	case 1:
	{
		Gotoxy(60, 17);
		std::cout << "WELCOME BACK HCMUS STAFF! HAVE A NICE WEEK!";
		break;
	}
	case 0:
	{
		Gotoxy(60, 17);
		std::cout << "WELCOME BACK TO HELL STUDENT!";
		break;
	}
	}
}