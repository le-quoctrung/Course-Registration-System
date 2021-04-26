#pragma once
#include<iostream>
#include<string>
#include "time.h"

using namespace std;

struct TimeTable
{
	int** Week;
};

void CreateTable(TimeTable*& a);
void DeleteTable(TimeTable*& a);
void ParseTb(TimeTable*& tb, std::string day, std::string sess);
bool CmpTb(TimeTable* a, TimeTable* b);
void AddTb(TimeTable* source, TimeTable* add);
void RemoveTb(TimeTable* source, TimeTable* sub);
void DisplayTb(TimeTable* a);

//STUDENT
struct NodeStudent
{
	string ID, FirstName, LastName, SocialID;
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

void addStudent(ListStudent* nStudent,
	int no,
	std::string id,
	std::string firstname,
	std::string lastname,
	bool gender,
	std::string dob,
	std::string socialid);


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

void addClass(ListClass*& nClass, int no, std::string name);


//COURSE
struct NodeCourse
{
	string TeacherName, ID, name;
	date start, end;
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

void addCourse(ListCourse*& nCourse,
	std::string id,
	std::string name,
	std::string teacher,
	int credit,
	TimeTable* tb,
	int max);
void deleteCourse(ListCourse*& nCourse, std::string ID, std::string teacher);


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

void addSemester(ListSem*& nSem,
	int type,
	date start,
	date end);


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

void addYear(ListYear*& nYear);


struct Score {
	string No;
	string StudentID;
	string StudentFullName;
	string TotalMark;
	string FinalMark;
	string MidTermMark;
	string OtherMark;
	Score* next;
	Score* prev;
};
struct ScoreList {
	string CourseCode;
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
	List->head = List->tail = nullptr;
}

template<class T>
void deleteList(T*& List)
{
	T* Cur = List->head;
	T* next = nullptr;

	while (Cur != nullptr)
	{
		next = Cur->next;
		delete(Cur);
		Cur = next;
	}

	List->head = List->tail = nullptr;
}