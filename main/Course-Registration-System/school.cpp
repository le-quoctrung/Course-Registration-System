#include "school.h"

void addYear(ListYear*& nYear)
{
	if (!nYear) return;
	date today = getDate();

	//info
	NodeYear* newYear = new NodeYear;
	newYear->classes = new ListClass;
	newYear->semesters = new ListSem;
	createEmptyList(newYear->classes);
	createEmptyList(newYear->semesters);

	newYear->startYear.year = today.year;
	newYear->startYear.month = today.month;
	newYear->startYear.day = today.day;

	//School year ends in the next year after e
	//with each semsester is 3 months
	newYear->endYear.year = newYear->startYear.year;
	newYear->endYear.month = newYear->startYear.month;
	newYear->endYear.day = newYear->startYear.day;

	newYear->next = nullptr;

	//empty head? make new head
	if (!nYear->head)
	{
		nYear->head = newYear;
		return;
	}

	nYear->tail->next = newYear;
	nYear->tail = newYear;
}

void addSemester(ListSem*& nSem, int type, date start, date end)
{
	if (!nSem) return;
	
	//info
	NodeSem* newSem = new NodeSem;
	newSem->type = 1;
	copyDate(newSem->start, start);
	copyDate(newSem->end, end);
	newSem->Courses = new ListCourse;
	createEmptyList(newSem->Courses);
	newSem->next = nullptr;

	//empty head? make new head
	if (!nSem)
	{
		nSem->head = newSem;
		return;
	}

	nSem->tail->next = newSem;
	nSem->tail = newSem;
}

void addClass(ListClass*& nClass, int no, std::string name)
{
	if (!nClass) return;

	//info
	NodeClass* newClass = new NodeClass;
	newClass->no = no;
	newClass->name = name;
	newClass->Students = new ListStudent;
	createEmptyList(newClass->Students);
	
	newClass->next = nullptr;

	//empty head? make new head
	if (!nClass->head)
	{
		nClass->head = nClass->tail = newClass;
		return;
	}

	nClass->tail->next = newClass;
	nClass->tail = newClass;
}

void addStudent(ListStudent* nStudent, int no, std::string id, std::string firstname, std::string lastname, bool gender, std::string dob, std::string socialid)
{
	if (!nStudent) return;

	//info
	NodeStudent* newStudent = new NodeStudent;
	newStudent->No = no;
	newStudent->ID = id;
	newStudent->FirstName = firstname;
	newStudent->LastName = lastname;
	newStudent->gender = gender;
	copyDate(newStudent->DOB, parseDate(dob));
	newStudent->SocialID = socialid;

	newStudent->next = nullptr;

	//empty head? make new head
	if (nStudent->head == nullptr)
	{
		nStudent->head = nStudent->tail = newStudent;
		return;
	}

	nStudent->tail->next = newStudent;
	nStudent->tail = newStudent;
}