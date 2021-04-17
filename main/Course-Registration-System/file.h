#pragma once
#ifndef _FILE_H_
#define _FILE_H_

#include <iostream>
#include <fstream>
#include <vector>

#include "Tokenizer.h"
#include "school.h"

using namespace std;

const std::string pathStudentAccounts = "db\\students.txt";
const std::string pathStaffAccounts = "db\\staffs.txt";

/*STRUCT TEMPORARY LIST FOR CHANGING PASSWORD*/
struct NodeAccount
{
	std::string username;
	std::string password;

	NodeAccount* next;
};
struct ListAccount
{
	NodeAccount* head;
	NodeAccount* tail;
};

void addAccount(ListAccount*& list);
void deleteListAccount(ListAccount*& list);

/*FUNCTIONS*/
bool CheckFile(std::string name);

void ReadListToClass(std::string name, NodeClass* nClass);	// Read from .csv and parse students to Class
void OutputListStudents(NodeClass* nClass);					// Output a list of students of a Class

void CreateStudentAccounts(NodeClass* nClass);				// From an available Class, make accounts
															// with username is [ID] and password is [DOB (yyyymmdd)]

int CheckLogin(std::string name, std::string pass);	//	CheckLogin returns
													//	-1	- password not match
													//	0	- student
													//	1	- staff
													//	404 - file not found

int ChangePassword(std::string name, std::string pass, std::string newPass);	// ChangePassword returns
																				// 0 - failed to get account
																				// 1 - changed sucessfully

#endif // !_FILE_H_