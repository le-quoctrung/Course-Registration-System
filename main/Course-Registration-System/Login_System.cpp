#include "Login_System.h"

void login()
{
	std::string name = "", pass = "";
	char chpass, chname;
	int x = 152;
	HienTroChuot();
	Gotoxy(x, 16);
	chname = _getch();
	while (chname != ENTER)
	{
		if (name.length() > 10 && chname != '\b') chname = '\0';
		else if (chname == '\b' && name.length() >= 1)//if user typed backspace 
		{
			std::cout << "\b \b";//rub the character behind the cursor.
			name.pop_back();
		}
		else if (chname == '\b' && name.length() == 0) chname = '\0';
		else
		{
			name.push_back(chname);
			std::cout << chname;
		}
		chname = _getch();
	}

	Gotoxy(x, 21);
	chpass = _getch();
	while (chpass != ENTER) //character 13 is enter
	{
		if (pass.length() > 10 && chpass != '\b') chpass = '\0';
		else if (chpass == '\b' && pass.length() >= 1)//if user typed backspace 
		{
			std::cout << "\b \b";//rub the character behind the cursor.
			pass.pop_back();
		}
		else if (chpass == '\b' && pass.length() == 0) chpass = '\0';
		else
		{
			pass.push_back(chpass);
			std::cout << '*';
		}	
		chpass = _getch();
	}
	//system("cls");
	COORD coord;

	ListYear* nYear = nullptr;
	std::ifstream checkPath("data.bin", std::ios::binary);
	if (checkPath)
	{
		if (checkPath.is_open())
			ReadAll("data.bin", nYear);
	}
	else createEmptyList(nYear);

	while (1)
	{
		coord = GetCursorClick();
		if (coord.X < 5 && coord.Y < 3)
		{
			Gotoxy(0, 50);
			exit(0);
		}
		else if (coord.X < 200 && coord.X > 140 && coord.Y < 38 && coord.Y > 35)
		{
			switch (CheckLogin(name, pass))
			{
			case 404:
			{
				//home();
				Gotoxy(155, 40);
				std::cout << "                                            ";
				Gotoxy(155, 40);
				std::cout << "Login failed. Account not found!";
				Sleep(1500);
				Gotoxy(x, 16); std::cout << "              ";
				Gotoxy(x, 21); std::cout << "              ";
				login();
				
			}
			case -1:
			{
				//home();
				Gotoxy(148, 40);
				std::cout << "Login failed. Username and Password missmatch!";
				Sleep(1500);
				Gotoxy(x, 16); std::cout << "              ";
				Gotoxy(x, 21); std::cout << "              ";
				login();
				
			}
			case 1:
			{
				system("cls");
				Gotoxy(87, 23);
				std::cout << "WELCOME BACK STAFF! HAVE A NICE WEEK!";
				Sleep(2000);
				system("cls");
				home_staff(nYear);
				
			}
			case 0:
			{
				system("cls");
				Gotoxy(90, 23);
				std::cout << "WELCOME BACK TO HELL STUDENT!";
				Sleep(1500);
				system("cls");
				home_student(nYear,name);
				//ShowStudentInfo(name);
				
			}
			}
			break;
		}
	}
}