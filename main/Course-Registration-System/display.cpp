#include "display.h"
#include"Console.h"


void home()
{
	int x = 80, y = 10;
	Gotoxy(1, 3);
	cout << "HOME";
	Gotoxy(x, y);
	cout << "log in";
	Gotoxy(x - 10, y + 3);
	cout << "USERNAME: ";
	Gotoxy(x - 10, y + 5);
	cout << "PASSWORD: ";
	
}