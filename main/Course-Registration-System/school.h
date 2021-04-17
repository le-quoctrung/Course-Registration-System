#pragma once
#include<iostream>
#include<string>
#include "time.h"

using namespace std;

struct Student
{
	string ID, FirstName, LastName, SocialID;
	int No;
	bool gender;
	date DOB;

	Student* next;
};

struct Course
{
	string TeacherName, ID, name;
	date start, end;
	int credit;
	int max = 50;
	bool** session;

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

int createSemester(Year* nYear,			// createSemester return:
					int type,			// -2 - Invalid type
					date start,			// -1 - Invalid date compare to semester
					date end);			//  0 - Year already have that semester or Invalid semester
										//  1 - Created successfully				
					
void createClass(Class*& nClass);

void createCourse(Course*& nCourse);

void addStudent(Class* nClass,
				int no,
				std::string id,
				std::string firstname,
				std::string lastname,
				bool gender,
				std::string dob,
				std::string social);

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

template<class T>
T getNode(T* pHead, int n)
{
	if (n > getSize(pHead)) return nullptr;

	for (int i = 0; i < n; i++)
	{
		pHead = pHead->next;
	}

	return pHead;
}