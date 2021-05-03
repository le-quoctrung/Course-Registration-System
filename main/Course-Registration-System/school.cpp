#include "school.h"

void CreateTable(TimeTable*& a)
{
	a->Week = new int* [4](); //S1 S2 S3 S4 = row

	for (int i = 0; i < 4; i++)
	{
		a->Week[i] = new int[6](); //MON TUE WED THU FRI SAT = col
	}
}
void DeleteTable(TimeTable*& a)
{
	for (int i = 0; i < 4; i++)
	{
		delete[] a->Week[i];
	}

	delete[] a->Week;
}

//TIME TABLE STRUCT
void ParseTb(TimeTable*& tb, std::string day, std::string sess)
{
	int row = -1, col = -1;

	if (sess == "S1") row = 0;
	if (sess == "S2") row = 1;
	if (sess == "S3") row = 2;
	if (sess == "S4") row = 3;

	if (day == "MON") col = 0;
	if (day == "TUE") col = 1;
	if (day == "WED") col = 2;
	if (day == "THU") col = 3;
	if (day == "FRI") col = 4;
	if (day == "SAT") col = 5;

	if (row == -1 || col == -1)
		return;
	else
		tb->Week[row][col] = 1;
}

bool CmpTb(TimeTable* a, TimeTable* b)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if ((a->Week[i][j] == b->Week[i][j]) && (a->Week[i][j] == 1)) //if a[i][j] == b[i][j] == 1 means already exists tb
				return false;
		}
	}

	return true;
}

void CopyTb(TimeTable* source, TimeTable* copyfrom)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			source->Week[i][j] = copyfrom->Week[i][j];
		}
	}
}

void AddTb(TimeTable* source, TimeTable* add)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (add->Week[i][j])
				source->Week[i][j] = 1;
		}
	}
}

void RemoveTb(TimeTable* source, TimeTable* sub)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j <6 ; j++)
		{
			if ((source->Week[i][j] == sub->Week[i][j]) && (source->Week[i][j] == 1)) //if a[i][j] == b[i][j] == 1 removes
				source->Week[i][j] = 0;
		}
	}
}

void DisplayTb(TimeTable* a)
{
	std::cout << "\t" << "MON" << "\t" << "TUE" << "\t" << "WED" << "\t" << "THUR" << "\t" << "FRI" << "\t" << "SAT" << "\n";
	for (int row = 0; row < 4; row++)
	{
		switch (row)
		{
		case 0: {std::cout << "S1" << "\t"; break; }
		case 1: {std::cout << "S2" << "\t"; break; }
		case 2: {std::cout << "S3" << "\t"; break; }
		case 3: {std::cout << "S4" << "\t"; break; }
		}
		for (int col = 0; col < 6; col++)
		{
			if (a->Week[row][col] == 0) std::cout << "  \t";
			else std::cout << " X\t";
		}
		std::cout << "\n";
	}
}

//SCHOOL STRUCT
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

void addCourse(ListCourse*& nCourse, std::string id, std::string name, std::string teacher, int credit, TimeTable* tb, int max)
{
	if (!nCourse) return;

	NodeCourse* newCourse = new NodeCourse;
	newCourse->tb = new TimeTable;
	CreateTable(newCourse->tb);
	newCourse->ID = id;
	newCourse->name = name;
	newCourse->TeacherName = teacher;
	newCourse->credit = credit;
	CopyTb(newCourse->tb, tb);
	newCourse->max = max;

	newCourse->next = nullptr;
	newCourse->prev = nullptr;

	if (!nCourse->head)
	{
		nCourse->head = nCourse->tail = newCourse;
		return;
	}

	nCourse->tail->next = newCourse;
	newCourse->prev = nCourse->tail;
	nCourse->tail = newCourse;
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
void Create_a_Course_registration_session(ListCourse& List,NodeCourse*nCourse) {
	cout << "input the date start: " << endl;
	cin >> nCourse->start.day;
	cin >> nCourse->start.month;
	cin >> nCourse->start.year;
	cout <<"the date start this course:"<< nCourse->start.day << "-" << nCourse->start.month << "-" << nCourse->start.year << endl;
	cout << "input the date end:"<<endl;
	cin >> nCourse->end.day;
	cin >> nCourse->end.month;
	cin >> nCourse->end.year;
	cout <<"the date end this course:"<< nCourse->end.day << "-" << nCourse->end.month << "-" << nCourse->end.year << endl;
}

void DeleteListStudent(ListStudent*& nStudent)
{
	if (!nStudent) return;

	NodeStudent* pCur = nStudent->head->next;
	NodeStudent* next = nullptr;
	while (pCur != nullptr)
	{
		next = pCur->next;
		delete pCur;
		pCur = next;
	}
	delete nStudent->head;
	nStudent->head = nStudent->tail = nullptr;
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

//ViewScoreBoard 
void ViewScoreBoard( ScoreList listSc,ListStudent listSt) {
	string input;
	cout << "input your ID: ";
	getline(cin, input);
	for (Score* cur = listSc.Head; cur != nullptr; cur = cur->next) {
		if (cur->StudentID == input) {
			system("cls");
			cout << "ScoreBoard" << "\n" << endl;
			cout << "StudentID: " << cur->StudentID << endl;
			cout << "Student FullName: " << cur->StudentFullName << endl;
			cout << "MidTerm Mark: " << cur->MidTermMark << endl;
			cout << "Final Mark: " << cur->FinalMark << endl;
			cout << "Other Mark: " << cur->OtherMark << endl;
			cout << "Total Mark: " << cur->TotalMark << endl;
		}
	}
}
