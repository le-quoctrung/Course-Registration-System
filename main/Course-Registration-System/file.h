#pragma once
#include<iostream>
#include"school.h"
#include<fstream>
#include<vector>
#include"Tokenizer.h"

using namespace std;

void Read_List_to_Class(string name, Class* nClass);
void Output_Student(Student* A);
void WriteFile(string name, Student* A, int n);
void Read_a_Course(string file, Course*& C);
