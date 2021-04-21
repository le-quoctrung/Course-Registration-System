#pragma once
#include<iostream>
#include<string>
#include "time.h"

using namespace std;

//STUDENT
struct NodeStudent
{
	string ID, FirstName, LastName, SocialID;
	int No;
	bool gender;
	date DOB;

	//Node
	NodeStudent* next;
};
struct ListStudent
{
	NodeStudent* head;
	NodeStudent* tail;
};


//CLASS
struct NodeClass
{
	ListStudent* Students;
	int no;
	std::string name;

	//Node
	NodeClass* next;
};
struct ListClass
{
	NodeClass* head;
	NodeClass* tail;
};


//COURSE
struct NodeCourse
{
	string TeacherName, ID, name;
	date start, end;
	int credit;
	int max = 50;
	bool** session;

	//Node
	NodeCourse* next;
};
struct ListCourse
{
	NodeCourse* head;
	NodeCourse* tail;
};


//SEMESTER
struct NodeSem
{
	date start, end;
	ListCourse* Courses;
	int type;

	//Node
	NodeSem* next;
};
struct ListSem
{
	NodeSem* head;
	NodeSem* tail;
};


//YEAR
struct NodeYear
{
	ListClass* classes;
	ListSem* semesters;

	date startYear;
	date endYear;

	//Node
	NodeYear* next;
};

struct ListYear
{
	NodeYear* head;
	NodeYear* tail;
};

//FUNCTIONS FOR SCHOOL.H
void addYear(ListYear*& nYear);

void addSemester(ListSem*& nSem,
	int type,
	date start,
	date end);

void addClass(ListClass*& nClass, int no, std::string name);

void addStudent(ListStudent* nStudent,
	int no,
	std::string id,
	std::string firstname,
	std::string lastname,
	bool gender,
	std::string dob,
	std::string socialid);

void deleteCourse(ListCourse*& nCourse, std::string ID, std::string teacher);

//FUNCTIONS FOR LIST
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
T* getNode(T* pHead, int n)
{
	if (n > getSize(pHead)) return nullptr;

	for (int i = 0; i < n - 1; i++)
	{
		pHead = pHead->next;
	}

	return pHead;
}

//MAKE EMPTY LIST FROM POINTER CLASS <T>
template<class T>
void createEmptyList(T*& List)
{
	List->head = List->tail = nullptr;
}