#include "display.h"
#include"Console.h"


void home()
{
	int x = 30, y = 5;
	Gotoxy(1, 3);
	cout << "HOME";
	Gotoxy(x, y);
	cout << "log in";
	Gotoxy(x - 10, y + 3);
	cout << "username: ";
	Gotoxy(x - 10, y + 5);
	cout << "password: ";
	Gotoxy(x, y + 8);
}