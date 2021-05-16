#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<conio.h>

#define TAB 09
#define ENTER 13

void controlTyping(std::string& name, short limit);
std::vector<std::string> split(std::string haystack, std::string needle);