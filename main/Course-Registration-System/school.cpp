#include "time.h"
#include "school.h"

void createYear(Year*& nYear)
{
	Year* newYear = new Year;
	newYear->classAPCS = nullptr;
	newYear->classCLC = nullptr;
	newYear->classVP = nullptr;
	newYear->semesters = nullptr;

	if (nYear == nullptr) newYear->next = nullptr;
	else newYear->next = nYear;
	nYear = newYear;
}

void createClass(Class*& nClass)
{
	Class* newClass = new Class;
	newClass->Students = nullptr;
	newClass->next = nullptr;

	if (!nClass)
	{
		nClass = newClass;
		return;
	}

	Class* tmp = nClass;

	while (tmp->next != nullptr)
		tmp = tmp->next;

	tmp->next = newClass;
}

void createCourse(course* &nCourse)
{
	course* newCourse = new course;
	newCourse->max = 50;
	newCourse->session = nullptr;
	newCourse->next = nCourse;
	nCourse = newCourse;
}

void addStudent(Class* nClass)
{

}
