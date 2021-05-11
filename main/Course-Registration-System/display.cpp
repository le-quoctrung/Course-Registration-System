#include "display.h"
#include"Console.h"
#include"file.h"

void home()
{
	/***********LOGIN BOX***********/

	int  x = 140, y = 10;


	for (int i = x + 1; i < x + 60; i++)
	{
		Gotoxy(i, y);
		std::cout << char(223);
	}
	for (int i = y; i < y + 34; i++)
	{
		Gotoxy(x, i);
		std::cout << char(219);
	}
	for (int i = x + 1; i < x + 60; i++)
	{
		Gotoxy(i, y + 33);
		std::cout << char(220);
	}
	for (int i = y; i < y + 34; i++)
	{
		Gotoxy(x + 60, i);
		std::cout << char(219);
	}
	/***************LOGO****************/

	int x1 = 10, y1 = 16;
	/*F*/
	for (int i = x1 + 2; i < x1 + 12; i++)
	{
		Gotoxy(i, y1);
		std::cout << char(223);
	}

	for (int i = x1 + 2; i < x1 + 10; i++)
	{
		Gotoxy(i, y1 + 3);
		std::cout << char(223);
	}
	for (int j = x1; j <= x1 + 1; j++)
	{
		for (int i = y1; i < y1 + 7; i++)
		{
			Gotoxy(j, i);
			std::cout << char(219);
		}
	}
	/*I*/

	for (int j = x1 + 17; j <= x1 + 18; j++)
	{
		for (int i = y1; i < y1 + 7; i++)
		{
			Gotoxy(j, i);
			std::cout << char(219);
		}
	}
	/*T*/
	for (int i = x1 + 24; i <= x1 + 41; i++)
	{
		Gotoxy(i, y1);
		std::cout << char(223);
	}

	for (int j = x1 + 32; j <= x1 + 33; j++)
	{
		for (int i = y1; i < y1 + 7; i++)
		{
			Gotoxy(j, i);
			std::cout << char(219);
		}
	}
	/*H*/
	for (int i = x1; i < x1 + 14; i++)
	{
		Gotoxy(i, y1 + 17);
		std::cout << char(223);
	}
	for (int j = x1; j <= x1 + 1; j++)
	{
		for (int i = y1 + 13; i < y1 + 21; i++)
		{
			Gotoxy(j, i);
			std::cout << char(219);
		}
	}

	for (int j = x1 + 14; j <= x1 + 15; j++)

	{
		for (int i = y1 + 13; i < y1 + 21; i++)
		{
			Gotoxy(j, i);
			std::cout << char(219);
		}
	}
	/*C*/
	for (int i = x1 + 21; i <= x1 + 31; i++)
	{
		Gotoxy(i, y1 + 13);
		std::cout << char(223);
	}

	for (int i = x1 + 21; i <= x1 + 31; i++)
	{
		Gotoxy(i, y1 + 20);
		std::cout << char(220);
	}
	for (int j = x1 + 19; j <= x1 + 20; j++)
	{
		for (int i = y1 + 13; i < y1 + 21; i++)
		{
			Gotoxy(j, i);
			std::cout << char(219);
		}
	}
	/*m*/

	/*USER LOGIN*/

}

void ShowStudentInfo(std::string name, std::string pass)
{
	int x = 100, y = 10;
	std::ifstream file(pathStudentAccounts, std::ios::in);
	if (file.is_open())
	{
		std::string check;
		std::vector<std::string> line;

		while (!file.eof())
		{
			std::getline(file, check);

			line = split(check, ",");
			
			if (name == line[1])
			{
				Gotoxy(x, y); std::cout << "FULL NAME: " << line[2] << " " << line[3] << std::endl;
				Gotoxy(x, y+1); std::cout << "STUDENT ID:  " << line[1] << std::endl;
				Gotoxy(x, y+2); std::cout << "DAY OF BIRTH: " << line[5] << std::endl;
				Gotoxy(x, y+3); std::cout << "GENDER: " << line[4] << std::endl;
				Gotoxy(x, y+4); std::cout << "SOCAIL ID: " << line[6] << std::endl;
			}
		}
		file.close();
	}
	
}