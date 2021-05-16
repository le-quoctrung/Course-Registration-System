#pragma once
#include<iostream>
#include<fstream>
#include"Console.h"
#include<vector>
#include "school.h"
#include "Login_System.h"

void loginDisplay();
void home_staff(ListYear* nYear);
void home_student(ListYear* nYear, std::string name);
void hcmusfame();
void ShowStudentInfo(std::string name);