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
void updateCourse(Course*&nCourse,string oldId,string newId){
	int pos = 0;
	if (nCourse == nullptr) {
		cout << "The list hasn't been initialized!";
	}
	Course* cCourse = nCourse;
	while (cCourse->next != nullptr) {
		if (cCourse->ID == oldId) {
			cCourse->ID == newId;
			cout << oldId << " has been found at position " << pos << " , replaced with " << newId << " \n";
			return;
		}
		cCourse = cCourse->next;
		pos++;
	}
	cout << oldId << " does not exist int the list!";
}
void deCourse(Course*&nCourse,string deID) {
	for (Course* p = nCourse; p != nullptr; p = p->next) {
		if (p->ID == deID) {
			Course* q = new Course;
			q = p;
			p = q->next;
			delete q;
		}
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
