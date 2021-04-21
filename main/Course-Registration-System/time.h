#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<ctime>
#include<iostream>
#include <sstream>
#include "Tokenizer.h"
#include <vector>

using namespace std;

struct date
{
	int year, month, day;
};

date getDate();
std::string displayDate(date d);
date parseDate(std::string str);
void copyDate(date& a, date b);

bool checkValid(date d);

int GetDay();
int GetMonth();
int GetYear();