#pragma once
#ifndef _FILE_H_
#define _FILE_H_

#include <iostream>
#include <fstream>
#include <vector>

#include "Tokenizer.h"
#include "school.h"

using namespace std;

const std::string pathStudentAccounts = "db\\allStudent.txt";
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

void addAccount(ListAccount*& list, std::string name, std::string pass);
void deleteListAccount(ListAccount*& list);
int ChangePassword(std::string name, std::string pass, std::string newPass);	// ChangePassword returns
																				// 0 - failed to get account
																				// 1 - changed sucessfully


/*FUNCTIONS*/
bool is_digits(std::string str);
bool CheckFile(std::string name);

int CheckLogin(std::string name, std::string pass);	//	CheckLogin returns
													//	-1	- password not match
													//	0	- student
													//	1	- staff
													//	404 - file not found

//STUDENT
void OutputStudent(NodeStudent* nStudent);
void OutputListStudents(ListStudent* nStudent);						// Output a list of students of a Class
void CreateStudentAccounts(NodeClass* nClass);						// From an available Class, make accounts
void ExportListStudent(ListStudent ListSt, ofstream f);																	// with username is [ID] and password is [DOB (yyyymmdd)]



//CLASS
void ReadListStudentToClass(std::string path, NodeClass* nClass);	// Read from .csv and parse students to Class
void OutputClass(NodeClass* nClass);
void OutputListClass(ListClass* nClass);

//COURSE 
void ReadListToCourse(std::string path, ListCourse* nCourse);
void OutputCourse(NodeCourse* nCourse);
void OutputListCourse(ListCourse* nCourse);
NodeCourse* FindCourse(ListCourse* nCourse, std::string ID, std::string teacher);
void UpdateCourse(ListCourse*& nCourse, string ID, string teacher);
void DeleteCourse(ListCourse*& nCourse, std::string ID, std::string teacher);
void viewListofCourse(ListCourse* list, NodeCourse* cCourse);
void deleteCourse(ListCourse*& nCourse, std::string ID, std::string teacher);

#endif // !_FILE_H_