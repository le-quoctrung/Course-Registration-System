#pragma once
#include<iostream>
#include<string>
#include "time.h"

using namespace std;

struct Student
{
	string ID, FirstName, LastName, SocialID, DOB;
	int No;
	bool gender;

	Student* next;
};

struct Course
{
	string TeacherName, ID, name;
	int credit;
	int max;
	string session; 

	Course* next;
};

struct Sem
{
	date start, end;
	Course* Courses;
	int type;

	//Node
	Sem* next;
};

struct Class
{
	Student* Students;

	//Node
	Class* next;
};

struct Year
{
	Class* classAPCS;
	Class* classCLC;
	Class* classVP;
	Sem* semesters;

	date startYear;
	date endYear;

	Year* next;
};

int createYear(Year*& nYear);			// createYear return:
										// -1 - Invalid date
										// 0 - Not September
										// 1 - Created successfully

int createSemester(Year* nYear);

void createClass(Class*& nClass);

void createCourse(Course*& nCourse, string TeacherName, string ID, string name,string session,
	int credit, int max );
void viewList(Course* nCourse);
void updateCourse(Course*& nCourse, string oldId, string newId);
void deCourse(Course*& nCourse, string deID);

void addStudent(Class* nClass,
				int no,
				std::string id,
				std::string firstname,
				std::string lastname,
				bool gender,
				std::string socialid,
				std::string dob);

template<class T>
int getSize(T* pHead)
{
	if (pHead == nullptr) return 0;
	int count = 1;
	while (pHead->next != nullptr)
	{
		count++;
		pHead = pHead->next;
	}
	return count;
}