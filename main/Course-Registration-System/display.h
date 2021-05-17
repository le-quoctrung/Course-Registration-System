#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Console.h"
#include "school.h"
#include "Login_System.h"

void loginDisplay();
void home_staff(ListYear*& nYear, NodeStudent*phead);
void home_student(ListYear* nYear, std::string name);
void hcmusfame();
void ShowStudentInfo(std::string name);
void createStudent(NodeStudent*& phead);
void importScoreBoard(std::string fileName, NodeStudent* pHead);