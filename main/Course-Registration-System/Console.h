#pragma once
#pragma once
#include<iostream>
#include<fstream>	
#include<Windows.h>
#include<string>
#include<conio.h>
#include<stdio.h>
#include<ctime>


using namespace std;


void Gotoxy(int x, int y);
void ResizeConsole(int width, int height);// default 300-80
void SetTextColor(int backgound_color/*default white*/, int text_color);
void HienTroChuot();
void AnTroChuot();
void FixConsoleWindow();
void DisableResizeWindow();
void DisableCtrButton(bool Close, bool Min, bool Max);	// 1 to active
void ShowScrollbar(bool Show);
void DisableSelection();

void Start(); // call all function need to run the program