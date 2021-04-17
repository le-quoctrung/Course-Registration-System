#include "school.h"

int createYear(Year*& nYear)
{
	date today = getDate();

	if (today.day < 1 || today.day > 31)
	{
		return -1;
	}
	else if (today.month == 9)
	{
		if (today.day > 30) return -1;
	}
	else return 0;

	Year* newYear = new Year;
	newYear->classAPCS = nullptr;
	newYear->classCLC = nullptr;
	newYear->classVP = nullptr;
	newYear->semesters = nullptr;

	newYear->startYear.year = today.year;
	newYear->startYear.month = today.month;
	newYear->startYear.day = today.day;

	//School year ends in the next year after exactly 12 months
	//with each semsester is 3 months
	newYear->endYear.year = newYear->startYear.year + 1;
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

void createCourse(Course* &nCourse, string TeacherName,string ID, string name,
int credit,int max = 50)
{
	Course* newCourse = new Course;
	newCourse->max = max;
	newCourse->ID = ID;
	newCourse->TeacherName = TeacherName;
	newCourse->name = name;
	newCourse->credit = credit;
	newCourse->next = nCourse;
	nCourse = newCourse;
}
//<<<<<<< HEAD
//=======

//>>>>>>> 76ec897d18d5a6eeee4552c6cc98d4d9af468734
void viewList(Course* nCourse) {
	while (nCourse != nullptr) {
		cout << nCourse->credit << endl;
		cout << nCourse->ID << endl;
		cout << nCourse->name << endl;
		cout << nCourse->TeacherName << endl;
	
		cout << nCourse->max << endl << endl;

		
		nCourse = nCourse->next;
	}
	cout << endl;
}
void updateCourse(Course*&nCourse,string ID,string Teachername){
	if (nCourse == nullptr) {
		cout << "The list hasn't been initialized!";
	}
	Course* cCourse = nCourse;
	while (cCourse != nullptr) {
		if (cCourse->ID == ID&&cCourse->TeacherName==Teachername) {

			return;
		}
		cCourse = cCourse->next;
	
	}
	
}
void deCourse(Course*&nCourse,string deID,string Teachername) {
	for (Course* p = nCourse; p != nullptr; p = p->next) {
		if (p->ID == deID &&p->TeacherName==Teachername) {
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
