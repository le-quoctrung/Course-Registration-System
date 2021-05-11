#pragma once
#include<iostream>
#include<string>
#include "time.h"



struct TimeTable
{
	int** Week;
};

void CreateTable(TimeTable*& a);
void DeleteTable(TimeTable*& a);
void ParseTb(TimeTable*& tb, std::string day, std::string sess);
bool CmpTb(TimeTable* a, TimeTable* b);
void CopyTb(TimeTable* source, TimeTable* copyfrom);
void AddTb(TimeTable* source, TimeTable* add);
void RemoveTb(TimeTable* source, TimeTable* sub);
void DisplayTb(TimeTable* a);

//STUDENT
struct NodeStudent
{
	std::string ID, FirstName, LastName, SocialID;
	int No;
	bool gender;
	date DOB;
	TimeTable tb;

	//Node
	NodeStudent* next;
};
struct ListStudent
{
	NodeStudent* head;
	NodeStudent* tail;
};

void AddStudent(ListStudent* nStudent,
	int no,
	std::string id,
	std::string firstname,
	std::string lastname,
	bool gender,
	std::string dob,
	std::string socialid);
void DeleteListStudent(ListStudent*& nStudent);

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

void AddClass(ListClass*& nClass, int no, std::string name);
void DeleteListClass(ListClass*& nClass);

//COURSE
struct NodeCourse
{
	std::string TeacherName, ID, name;
	//date start, end; //Khong co date start va end
	int credit;
	int max = 50;
	TimeTable* tb;

	//Node
	NodeCourse* next;
	NodeCourse* prev;
};
struct ListCourse
{
	NodeCourse* head;
	NodeCourse* tail;
};

void AddCourse(ListCourse*& nCourse,
	std::string id,
	std::string name,
	std::string teacher,
	int credit,
	TimeTable* tb,
	int max);
void DeleteListCourse(ListCourse*& nCourse);

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

void AddSemester(ListSem*& nSem,
	int type,
	date start,
	date end);
void DeleteListSem(ListSem*& nSem);

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

void AddYear(ListYear*& nYear);
void DeleteListYear(ListYear*& nYear);

struct Score {
	std::string No, StudentID, StudentFullName, TotalMark, FinalMark, MidTermMark, OtherMark;

	Score* next, * prev;
	
};
struct ScoreList {
	std::string CourseCode;
	Score* Head;
};

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
	if (!List)
	{
		List = new T;
	}
	List->head = List->tail = nullptr;
}