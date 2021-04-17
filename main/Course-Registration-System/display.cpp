#include "display.h"
#include"Console.h"


void home()
{
	/***********LOGIN BOX***********/

	int  x = 140, y = 10;
	//Gotoxy(x, y); cout << char(219);
	//Gotoxy(x + 60, y); cout << char(219);
	//Gotoxy(x + 60, y + 33); cout << char(219);
	//Gotoxy(x, y+33); cout << char(219);
	for (int i = x+1; i < x + 60; i++)
	{
		Gotoxy(i, y);
		cout << char(223);
	}
	for (int i = y; i < y + 34; i++)
	{
		Gotoxy(x, i);
		cout << char(219);
	}
	for (int i = x+1; i < x + 60; i++)
	{
		Gotoxy(i, y + 33);
		cout << char(220);
	}
	for (int i = y; i < y + 34; i++)
	{
		Gotoxy(x + 60, i);
		cout << char(219);
	}
	/***************LOGO****************/
	
	int x1 = 10, y1 = 16;
	/*F*/
	for (int i = x1 + 2; i < x1 + 14; i++)
	{
		Gotoxy(i, y1);
		cout << char(223);
	}
	for (int i = x1+2; i < x1 + 12; i++)
	{
		Gotoxy(i, y1 + 4);
		cout << char(223);
	}
	for (int j = x1; j <= x1 + 1; j++)
	{
		for (int i = y1; i < y1 + 8; i++)
		{
			Gotoxy(j, i);
			cout << char(219);
		}
	}
	/*I*/
	
	for (int j = x1+19; j <= x1 + 20; j++)
	{
		for (int i = y1; i < y1 + 8; i++)
		{
			Gotoxy(j, i);
			cout << char(219);
		}
	}
	/*T*/
	for (int i = x1 + 25; i <= x1 + 44; i++)
	{
		Gotoxy(i, y1);
		cout << char(223);
	}
	for (int j = x1+34; j <= x1 + 35; j++)
	{
		for (int i = y1; i < y1 + 8; i++)
		{
			Gotoxy(j, i);
			cout << char(219);
		}
	}
	/*H*/
	for (int i = x1; i < x1 + 16; i++)
	{
		Gotoxy(i, y1 + 19);
		cout << char(223);
	}
	for (int j = x1 ; j <= x1 + 1; j++)
	{
		for (int i = y1+13; i < y1 + 25; i++)
		{
			Gotoxy(j, i);
			cout << char(219);
		}
	}
	for (int j = x1+16; j <= x1 + 17; j++)
	{
		for (int i = y1 + 13; i < y1 + 25; i++)
		{
			Gotoxy(j, i);
			cout << char(219);
		}
	}
	
}