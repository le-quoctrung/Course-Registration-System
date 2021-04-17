#pragma once
#ifndef _FILE_H_
#define _FILE_H_

#include <iostream>
#include <fstream>
#include <vector>

#include "Tokenizer.h"
#include "school.h"

using namespace std;

bool checkFile(std::string name);

void Read_List_to_Class(std::string name, NodeClass* nClass);		// Read from .csv and parse students to Class
void Output_List_Students(NodeClass* nClass);						// Output a list of students of a Class
void CreateStudentAccounts(NodeClass* nClass);						// From an available Class, make accounts
																	// with username is [ID] and password is [DOB (yyyymmdd)]

void ChangePassword(std::string name, std::string pass);			// Copy from the database and change it on runtime and write back
																	// onto the database

#endif // !_FILE_H_