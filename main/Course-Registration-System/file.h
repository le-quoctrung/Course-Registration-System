#pragma once
#include<iostream>
#include"school.h"
#include<fstream>
#include<vector>
#include"Tokenizer.h"
using namespace std;
void ReadFile(string name, student*& A, int& n);
void Output(student* A, int n);
void WriteFile(string name, student* A, int n);
