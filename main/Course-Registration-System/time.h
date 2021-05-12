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
int CmpDate(date a, date b);
void CopyDate(date& a, date b);
bool CheckValid(date d);

int GetDay();
int GetMonth();
int GetYear();