#pragma once
#pragma once
#include<iostream>
#include<fstream>	
#include<Windows.h>
#include<string>
#include<conio.h>
#include<stdio.h>
#include<ctime>

#define xPos 307/42
#define yPos 863/53





void Gotoxy(int x, int y); // x max 210, y max 53 in fullscreen mode  //x*307/42 and y*863/53
void ResizeConsole(int width, int height);// default 300-80
void SetTextColor(int backgound_color/*default white*/, int text_color);
void HienTroChuot();
void AnTroChuot();
void FixConsoleWindow();
void DisableResizeWindow();
void DisableCtrButton(bool Close, bool Min, bool Max);	// 1 to active
void ShowScrollbar(bool Show);
void DisableSelection();
void full_screen();
bool CheckCursorClick(short xPos1, short xPos2, short yPos1, short yPOs2); // max xPos 1535, max yPos 863
COORD GetCursorClick();
void Start(); // call all function need to run the program