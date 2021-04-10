#pragma once
#include<iostream>
#include"school.h"
#include<fstream>
#include<vector>
#include"Tokenizer.h"
using namespace std;
void ReadFile(string name, student*& A);
void Output(student* A);
void WriteFile(string name, student* A, int n);
