#pragma once
#include<iostream>
#include<string>

using namespace std;

struct date
{
	int year, month, day;
};

struct student
{
	string ID, FirstName, LastName, SocialID;
	int No;
	string DOB;
	bool gender;
	student* pNext;
};

struct course
{
	string TeacherName, ID, name;
	date start, end;
	int credit;
	int max = 50;
	bool** session;
};

struct Sem
{
	date start, end;
	course* Courses;
	int type;

	//Node
	Sem* next;
};

struct Class
{
	student* Students;

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

void addStudent(Class* nClass);

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