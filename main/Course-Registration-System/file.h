#pragma once
#ifndef _FILE_H_
#define _FILE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include "Tokenizer.h"
#include "school.h"


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

//CLASS STUDENT
void ReadListStudentToClass(std::string path, NodeClass* nClass);	// Read from .csv and parse students to Class
void CreateStudentAccounts(NodeClass* nClass);						// From an available Class, make accounts
																	// with username is [ID] and password is [DOB (yyyymmdd)]

//COURSE 
void ReadListToCourse(std::string path, ListCourse* nCourse);
void Enroll(ListCourse* nCourse, NodeCourse* EnrollCourse);
void displayEnrollCourse(ListCourse* nCourse, NodeCourse* EnrollCourse, ListCourse* eCourse);
NodeCourse* FindCourse(ListCourse* nCourse, std::string ID, std::string teacher);
void UpdateCourse(ListCourse*& nCourse, std::string ID, std::string teacher);
void DeleteCourse(ListCourse*& nCourse, std::string ID, std::string teacher);
void ExportCourseScoreBoard(NodeCourse* nCourse);
void UpdateCourseScoreBoard();
void ImportCourseScoreBoard();
void write_csv(std::string filename, std::vector<std::pair<std::string, std::vector<int>>> dataset);
void writeScoreboard();

#endif // !_FILE_H_