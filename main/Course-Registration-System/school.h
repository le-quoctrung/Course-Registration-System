#pragma once
#include<iostream>
#include<string>
#include "time.h"

using namespace std;

struct date
{
	int year, month, day;
};

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

	Year* next;
};

void createYear(Year*& nYear);

void createClass(Class*& nClass);

void createCourse(Course*& nCourse);
void viewList(Course*& nCourse);
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