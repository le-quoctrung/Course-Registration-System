#include "school.h"

int createYear(Year*& nYear)
{
	nYear->startYear.month = GetMonth();
	nYear->startYear.day = GetDay();

	if (nYear->startYear.day < 1 || nYear->startYear.day > 31)
	{
		return -1;
	}
	else if (nYear->startYear.month == 9)
	{
		if (nYear->startYear.day > 30) return -1;
	}
	else return 0;

	Year* newYear = new Year;
	newYear->classAPCS = nullptr;
	newYear->classCLC = nullptr;
	newYear->classVP = nullptr;
	newYear->semesters = nullptr;

	newYear->startYear.year = GetYear();
	newYear->endYear.year = GetYear() + 1;
	newYear->endYear.month = newYear->startYear.month + 12;
	newYear->endYear.day = newYear->startYear.day + 365;

	if (nYear == nullptr)
	{
		newYear->next = nullptr;
		nYear = newYear;
	}
	else newYear->next = nYear;
	nYear = newYear;

	return 1;
}

int createSemester()
{




	return 1;
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

void viewList(Course*& nCourse) {
	while (nCourse != nullptr) {
		cout << nCourse->credit << endl;
		cout << nCourse->ID << endl;
		cout << nCourse->name << endl;
		cout << nCourse->TeacherName << endl;
		cout << nCourse->session << endl;
		nCourse = nCourse->next;
	}
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
