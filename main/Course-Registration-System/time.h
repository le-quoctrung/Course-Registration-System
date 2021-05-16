#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<ctime>
#include<iostream>
#include <sstream>
#include "Tokenizer.h"
#include <vector>


struct date
{
	int year, month, day;
};

date GetDate();
std::string DisplayDate(date d);
date ParseDate(std::string str);

// 1	- means a is later on
// 0	- means equal
// -1	- means a is sooner on
int CmpDate(date a, date b);

void CopyDate(date& a, date b);
bool CheckValid(date d);

int GetDay();
int GetMonth();
int GetYear();