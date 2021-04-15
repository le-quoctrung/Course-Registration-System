#include "school.h"

void createYear(Year*& nYear)
{
	Year* newYear = new Year;
	newYear->classAPCS = nullptr;
	newYear->classCLC = nullptr;
	newYear->classVP = nullptr;
	newYear->semesters = nullptr;

	if (nYear == nullptr)
	{
		newYear->next = nullptr;
		nYear = newYear;
	}
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

void createCourse(Course* &nCourse)
{
	Course* newCourse = new Course;
	newCourse->max = 50;
	newCourse->session = nullptr;
	newCourse->next = nCourse;
	nCourse = newCourse;
}

void addStudent(Class* nClass, int no, std::string id, std::string firstname, std::string lastname, bool gender, std::string dob, std::string socialid )
{
	if (nClass == nullptr) return;

	Student* newStudent = new Student;

	newStudent->No = no;
	newStudent->ID = id;
	newStudent->FirstName = firstname;
	newStudent->LastName = lastname;
	newStudent->gender = gender;
	newStudent->DOB = dob;
	newStudent->SocialID = socialid;

	newStudent->next = nullptr;

	if (nClass->Students == nullptr)
	{
		nClass->Students = newStudent;
		return;
	}

	Student* tmp = nClass->Students;

	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
	}

	tmp->next = newStudent;
}
