#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<ctime>
#include<iostream>
using namespace std;

struct date
{
	int year, month, day;
};

date getDate();
void displayDate(date* d);

int GetDay();
int GetMonth();
int GetYear();