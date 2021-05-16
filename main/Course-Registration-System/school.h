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
int CountTb(TimeTable* a);

struct NodeScore
{
	int No;
	float TotalMark, Finalmark, MidtermMark, Othermark;
	std::string ID, LastName, FirstName;

	NodeScore* next, * prev;
};

struct ListScore
{
	NodeScore* head, * tail;
};

//STUDENT
struct NodeStudent
{
	std::string ID, FirstName, LastName, SocialID;
	int No;
	bool gender;
	date DOB;
	TimeTable* tb;


	//Node
	NodeStudent* next;
};
struct ListStudent
{
	NodeStudent* head;
	NodeStudent* tail;
};

bool AddStudent(ListStudent* nStudent,
	int no,
	std::string id,
	std::string firstname,
	std::string lastname,
	bool gender,
	std::string dob,
	std::string socialid);
void DeleteListStudent(ListStudent*& nStudent);
void OutputStudent(NodeStudent* nStudent);							// Output a node of student
void OutputListStudents(ListStudent* nStudent);						// Output a list of students of a Class

//COURSE
struct NodeCourse
{
	std::string TeacherName, ID, name;
	int credit;
	int max = 50;
	TimeTable* tb;
	ListStudent* cClass;

	//Node
	NodeCourse* next;
	NodeCourse* prev;
};
struct ListCourse
{
	NodeCourse* head;
	NodeCourse* tail;
};

bool AddCourse(ListCourse*& nCourse,
	std::string id,
	std::string name,
	std::string teacher,
	int credit,
	TimeTable* tb,
	int max);
void DeleteListCourse(ListCourse*& nCourse);
void OutputCourse(NodeCourse* nCourse);
void OutputListCourse(ListCourse* nCourse);
void OutputHeaderListCourse(ListCourse* nCourse); //Only show the course header
void Enroll(ListCourse* nCourse, NodeStudent* enStudent);
//void displayEnrollCourse(ListCourse* nCourse, ListCourse* eCourse, NodeStudent* enStudent);
//void viewListStudentinaCourse(ListCourse* nCourse, ListStudent* nStudent, NodeStudent* enStudent);
void ViewScoreBoard(ListScore listSc, ListStudent listSt);

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

bool AddClass(ListClass*& nClass, int no, std::string name);
void DeleteListClass(ListClass*& nClass);
void OutputClass(NodeClass* nClass);
void OutputListClass(ListClass* nClass);
NodeStudent* FindStudent(ListClass* nClass, std::string ID);

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

bool CanAddSem(ListSem* nSem, int type, date start, date end);
bool AddSemester(ListSem*& nSem,
	int type,
	date start,
	date end);
void DeleteListSem(ListSem*& nSem);
void OutputSem(NodeSem* nSem);
void OutputListSem(ListSem* nSem);

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

bool CanAddYear(ListYear* nYear, date today);
bool AddYear(ListYear*& nYear);
void DeleteListYear(ListYear*& nYear);
void OutputYear(NodeYear* nYear);
void OutputListYear(ListYear* nYear); //not found function definition

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
//struct courseScore
//{
//	int total, final, mid;
//	courseScore* nextCourse;
//};
//struct listScore
//{
//	courseScore* node;
//};
//struct student
//{	
//	listScore profile;	
//};