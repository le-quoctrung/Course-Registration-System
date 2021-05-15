#include "school.h"

void CreateTable(TimeTable*& a)
{
	if (a == nullptr) a = new TimeTable;
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
			if (a->Week[row][col] == 0) std::cout << " \t";
			else std::cout << " X\t";
		}
		std::cout << "\n";
	}
}

//SCHOOL STRUCT
bool CanAddYear(ListYear* nYear, date today)
{
	NodeYear* pCur = nYear->head;

	if (today.year < nYear->tail->endYear.year) return false; //Smaller than the lastest Node

	while (pCur)
	{
		if (CmpDate(pCur->startYear, today) == 0)	//Existed
			return false;
		pCur = pCur->next;
	}

	if (today.month != 10 && today.day < nYear->tail->endYear.day) return false;

	return true;
}

bool AddYear(ListYear*& nYear)
{
	if (!nYear) return false;
	date today = GetDate();
	//if (!CanAddYear(nYear, today)) return false;

	//info
	NodeYear* newYear = new NodeYear;
	newYear->classes = nullptr;
	newYear->semesters = nullptr;
	createEmptyList(newYear->classes);
	createEmptyList(newYear->semesters);

	newYear->startYear.year = today.year;
	newYear->startYear.month = today.month;
	newYear->startYear.day = today.day;

	//School year ends in the next year
	//with each semsester is 3 months
	newYear->endYear.year = newYear->startYear.year + 1;
	newYear->endYear.month = newYear->startYear.month + 3;
	newYear->endYear.day = newYear->startYear.day;

	newYear->next = nullptr;

	//empty head? make new head
	if (!nYear->head)
	{
		nYear->head = nYear->tail = newYear;
		return true;
	}

	nYear->tail->next = newYear;
	nYear->tail = newYear;
	return true;
}

void DeleteListYear(ListYear*& nYear)
{
	if (!nYear) return;

	NodeYear* pCur = nYear->head->next;
	NodeYear* next = nullptr;

	while (pCur)
	{
		next = pCur->next;
		DeleteListClass(pCur->classes);
		DeleteListSem(pCur->semesters);
		delete pCur;
		pCur = next;
	}

	delete nYear->head;
	nYear->head = nYear->tail = nullptr;
}

void OutputYear(NodeYear* nYear)
{
	std::cout << "School Year: " << nYear->startYear.year << "-" << nYear->endYear.year;
	OutputListSem(nYear->semesters);
	std::cout << "\n";
	OutputListClass(nYear->classes);
}

void OutputListYear(ListYear* nYear)
{
	if (!nYear) return;
	NodeYear* pCur = nYear->head;
	int count = 1;
	while (pCur)
	{
		std::cout << count++ << ". ";
		OutputYear(pCur);
		pCur = pCur->next;
	}
}

bool CanAddSem(ListSem* nSem, int type, date start, date end)
{
	switch (type)
	{
	case 1: {if (start.month != 10) return false; break; }  //first sem start at d/10/20xx
	case 2: {if (start.month != 1) return false; break; }	//second sem start at d/1/20xy
	case 3: {if (start.month != 5) return false; break; }	//third sem start at  d/5/20xy
	}

	NodeSem* pCur = nSem->head;
	if (getSize(pCur) == 3) return false; // 3 Semesters already
	if (CmpDate(nSem->tail->end, start) == 1) return false; //Conflicted dates
	while (pCur)
	{
		if (pCur->type == type) return false;	//Existed Semester
		pCur = pCur->next;
	}

	return true;
}

bool AddSemester(ListSem*& nSem, int type, date start, date end)
{
	if (!nSem) return false;
	
	//if (!CanAddSem(nSem, type, start, end)) return false;

	//info
	NodeSem* newSem = new NodeSem;
	newSem->type = type;
	CopyDate(newSem->start, start);
	CopyDate(newSem->end, end);
	newSem->Courses = nullptr;
	createEmptyList(newSem->Courses);
	newSem->next = nullptr;

	//empty head? make new head
	if (!nSem->head)
	{
		nSem->head = nSem->tail = newSem;
		return true;
	}

	nSem->tail->next = newSem;
	nSem->tail = newSem;
	return true;
}

void DeleteListSem(ListSem*& nSem)
{
	if (!nSem) return;

	NodeSem* pCur = nSem->head->next;
	NodeSem* next = nullptr;

	while (pCur)
	{
		next = pCur->next;
		DeleteListCourse(pCur->Courses);
		delete pCur;
		pCur = next;
	}

	delete nSem->head;
	nSem->head = nSem->tail = nullptr;
}

void OutputSem(NodeSem* nSem)
{
	std::cout << "Type: " << nSem->type << "\t"
		<< "Start Date: " << DisplayDate(nSem->start) << "\t"
		<< "End Date: " << DisplayDate(nSem->end) << "\n"
		<< "Course in Semester: \n\n"; OutputHeaderListCourse(nSem->Courses);
	std::cout << "\n";
}

void OutputListSem(ListSem* nSem)
{
	if (!nSem) return;
	NodeSem* pCur = nSem->head;
	int count = 1;
	while (pCur)
	{
		std::cout << count++ << ". ";
		std::cout << "Type: " << pCur->type << "\t"
			<< "Start Date: " << DisplayDate(pCur->start) << "\t"
			<< "End Date: " << DisplayDate(pCur->end) << "\n";
		pCur = pCur->next;
	}
}

bool AddCourse(ListCourse*& nCourse, std::string id, std::string name, std::string teacher, int credit, TimeTable* tb, int max)
{
	if (!nCourse) return false;

	NodeCourse* newCourse = new NodeCourse;
	newCourse->tb = new TimeTable;
	CreateTable(newCourse->tb);
	newCourse->ID = id;
	newCourse->name = name;
	newCourse->TeacherName = teacher;
	newCourse->credit = credit;
	CopyTb(newCourse->tb, tb);
	newCourse->max = max;
	newCourse->cClass = nullptr;
	createEmptyList(newCourse->cClass); //Course class

	newCourse->next = nullptr;
	newCourse->prev = nullptr;

	if (!nCourse->head)
	{
		nCourse->head = nCourse->tail = newCourse;
		return true;
	}

	nCourse->tail->next = newCourse;
	newCourse->prev = nCourse->tail;
	nCourse->tail = newCourse;
	return true;
}

void DeleteListCourse(ListCourse*& nCourse)
{
	if (!nCourse) return;

	NodeCourse* pCur = nCourse->head->next;
	NodeCourse* next = nullptr;

	while (pCur)
	{
		next = pCur->next;
		DeleteTable(pCur->tb);
		delete pCur;
		pCur = next;
	}

	delete nCourse->head;
	nCourse->head = nCourse->tail = nullptr;
}

bool AddClass(ListClass*& nClass, int no, std::string name)
{
	if (!nClass) return false;

	//info
	NodeClass* newClass = new NodeClass;
	newClass->no = no;
	newClass->name = name;
	newClass->Students = nullptr;
	createEmptyList(newClass->Students);

	newClass->next = nullptr;

	//empty head? make new head
	if (!nClass->head)
	{
		nClass->head = nClass->tail = newClass;
		return true;
	}

	nClass->tail->next = newClass;
	nClass->tail = newClass;
	return true;
}

void DeleteListClass(ListClass*& nClass)
{
	if (!nClass) return;

	NodeClass* pCur = nClass->head->next;
	NodeClass* next = nullptr;

	while (pCur)
	{
		next = pCur->next;
		DeleteListStudent(pCur->Students);
		delete pCur;
		pCur = next;
	}

	delete nClass->head;
	nClass->head = nClass->tail = nullptr;
}

void OutputClass(NodeClass* nClass)
{
	std::cout << nClass->name
		<< nClass->no << " \n";
	OutputListStudents(nClass->Students);
	std::cout << "\n";
}

void OutputListClass(ListClass* nClass)
{
	if (!nClass) return;
	
	NodeClass* pCur = nClass->head;
	int count = 1;
	while (pCur != nullptr)
	{
		std::cout << count++ <<". ";
		std::cout << pCur->name << pCur->no << "\n";
		pCur = pCur->next;
	}
}

NodeStudent* FindStudent(ListClass* nClass, std::string ID)
{
	if (!nClass) return nullptr;

	NodeClass* Class = nClass->head;
	while (Class)
	{
		NodeStudent* pCur = Class->Students->head;
		while (pCur)
		{
			if (pCur->ID == ID) return pCur;
			pCur = pCur->next;
		}
		Class = Class->next;
	}
	return nullptr; //Not found!
}

bool AddStudent(ListStudent* nStudent, int no, std::string id, std::string firstname, std::string lastname, bool gender, std::string dob, std::string socialid)
{
	if (!nStudent) return false;

	//info
	NodeStudent* newStudent = new NodeStudent;
	newStudent->No = no;
	newStudent->ID = id;
	newStudent->FirstName = firstname;
	newStudent->LastName = lastname;
	newStudent->gender = gender;
	CopyDate(newStudent->DOB, ParseDate(dob));
	newStudent->SocialID = socialid;
	newStudent->tb = nullptr;
	CreateTable(newStudent->tb);

	newStudent->next = nullptr;

	//empty head? make new head
	if (nStudent->head == nullptr)
	{
		nStudent->head = nStudent->tail = newStudent;
		return true;
	}

	nStudent->tail->next = newStudent;
	nStudent->tail = newStudent;
	return true;
}

void DeleteListStudent(ListStudent*& nStudent)
{
	if (!nStudent) return;

	NodeStudent* pCur = nStudent->head->next;
	NodeStudent* next = nullptr;

	while (pCur)
	{
		next = pCur->next;
		delete pCur;
		pCur = next;
	}

	delete nStudent->head;
	nStudent->head = nStudent->tail = nullptr;
}

void OutputListStudents(ListStudent* nStudent)
{
	if (!nStudent) return;

	NodeStudent* pCur = nStudent->head;
	int count = 1;
	while (pCur != nullptr)
	{
		std::cout << count++;
		OutputStudent(pCur);
		pCur = pCur->next;
	}
}

std::string getGender(bool a)
{
	if (a == 0) return "Nu";
	else if (a == 1) return "Nam";
	return "Null";
}

void OutputStudent(NodeStudent* nStudent)
{
	std::cout << nStudent->No << "  "
		<< nStudent->ID << "  "
		<< nStudent->FirstName << "  "
		<< nStudent->LastName << "  "
		<< getGender(nStudent->gender) << "  "
		<< DisplayDate(nStudent->DOB) << "  "
		<< nStudent->SocialID << "\n";
}

void OutputCourse(NodeCourse* nCourse)
{
	std::cout << "ID: " << nCourse->ID << "\n"
		<< "Course Name: " << nCourse->name << "\n"
		<< "Course Teacer: " << nCourse->TeacherName << "\n"
		<< "Credit: " << nCourse->credit << "\n"
		<< "Max atendee: " << getSize(nCourse->cClass->head) << "/" << nCourse->max << "\n\n";

	DisplayTb(nCourse->tb);
	std::cout << "\n\n";
	OutputListStudents(nCourse->cClass);
	nCourse = nCourse->next;
}

void OutputListCourse(ListCourse* nCourse)
{
	if (!nCourse) return;

	NodeCourse* pCur = nCourse->head;
	while (pCur != nullptr)
	{
		system("CLS");
		OutputCourse(pCur);
		std::cout << "\n\n\n<--Press A\t\tPress S to exit\t\tPress D-->";

	catch_exception:
		if (!_kbhit())
		{
			char x = _getch();
			if (x == 'a' || x == 'A')
			{
				//if (n > 1)n--;
				if (pCur->prev)
					pCur = pCur->prev;
				else
				{
					std::cout << "\n\n\t\tThis is head of a list";
					goto catch_exception;
				}
			}
			else if (x == 'd' || x == 'D')
			{
				//if (n < max)n++;
				if (pCur->next)
					pCur = pCur->next;
				else
				{
					std::cout << "\n\n\t\tThis is tail of a list";
					goto catch_exception;
				}
			}
			else if (x == 's' || x == 'S')
				return;
			else goto catch_exception;
		}
	}
}

void OutputHeaderListCourse(ListCourse* nCourse)
{
	if (!nCourse) return;
	NodeCourse* pCur = nCourse->head;
	int count = 1;
	while (pCur)
	{
		std::cout << count++ << " .";
		std::cout << "ID: " << pCur->ID << "  "
			<< "Course Name: " << pCur->name << "  "
			<< "Course Teacer: " << pCur->TeacherName <<  "  "
			<< "Credit: " << pCur->credit <<  "  "
			<< "Max atendee: " << getSize(pCur->cClass->head) << "/" << pCur->max << "\n";
		pCur = pCur->next;
	}
}

void Enroll(ListCourse* nCourse, NodeStudent* nStudent)
{
	if (!nCourse) return;

	NodeCourse* pCur = nCourse->head;
	while (pCur != nullptr)
	{
		system("CLS");
		OutputCourse(pCur);
		std::cout << "\n\n---------STUDENT'S TIME TABLE---------\n\n";
		DisplayTb(nStudent->tb);
		std::cout << "\n\n\n<--Press A\t\tPress S to exit\t\tPress D-->";
		std::cout << "\n----->Press R to enroll";
	catch_exception:
		if (!_kbhit())
		{
			char x = _getch();
			if (x == 'a' || x == 'A')
			{
				//if (n > 1)n--;
				if (pCur->prev)
					pCur = pCur->prev;
				else
				{
					std::cout << "\n\n\t\tThis is head of a list";
					goto catch_exception;
				}
			}
			else if (x == 'd' || x == 'D')
			{
				//if (n < max)n++;
				if (pCur->next)
					pCur = pCur->next;
				else
				{
					std::cout << "\n\n\t\tThis is tail of a list";
					goto catch_exception;
				}
			}
			else if (x == 's' || x == 'S')
				return;
			else if (x == 'r' || x == 'R') {

				if (CmpTb(nStudent->tb, pCur->tb))
				{
					//Check if course reached max capacity
					//Get the current size of class to compare with capacity
					if (getSize(pCur->cClass->head) == pCur->max)
					{
						std::cout << "Course is full!";
					}
					else //Enroll 
					{
						AddStudent(pCur->cClass,			//Add into cClass (Course class)
							getSize(pCur->cClass->head) + 1,//Add No as the size of the class
							nStudent->ID,					//Student infos
							nStudent->FirstName,
							nStudent->LastName,
							nStudent->gender,
							DisplayDate(nStudent->DOB),
							nStudent->SocialID);
						AddTb(nStudent->tb, pCur->tb);	//Add in student timetable
					}
					
					std::cout << "\n\n\t\tEnrolled! ";
				}
				else std::cout << "\n\n\t\tConflicted session(s)! ";
				goto catch_exception;
			}
			else goto catch_exception;
			}	
	}
}

//void enrollanddisplay(ListCourse* nCourse,NodeStudent*student) {
//
//	ListCourse* eCourse;
//	ListStudent* eStudent;
//	//int n = 1;
//	if (!nCourse) return;
//
//	NodeCourse* pCur = nCourse->head;
//	while (pCur != nullptr)
//	{
//		system("CLS");
//		OutputCourse(pCur);
//		std::cout << "\n\n\n<--Press A\t\tPress S to exit\t\tPress D-->";
//		std::cout << "\n----->Press R to enroll";
//	catch_exception:
//		if (!_kbhit())
//		{
//			char x = _getch();
//			if (x == 'a' || x == 'A')
//			{
//				//if (n > 1)n--;
//				if (pCur->prev)
//					pCur = pCur->prev;
//				else
//				{
//					std::cout << "\n\n\t\tThis is head of a list";
//					goto catch_exception;
//				}
//			}
//			else if (x == 'd' || x == 'D')
//			{
//				//if (n < max)n++;
//				if (pCur->next)
//					pCur = pCur->next;
//				else
//				{
//					std::cout << "\n\n\t\tThis is tail of a list";
//					goto catch_exception;
//				}
//			}
//			else if (x == 's' || x == 'S')
//				return;
//			else if (x == 'r' || x == 'R') {
//				TimeTable* tb;
//				std::string  DOB;
//				std::cout << "\n\n\t\tEnrolled ";
//				AddCourse(eCourse, pCur->ID, pCur->name, pCur->TeacherName, pCur->credit, tb, pCur->max);
//				AddStudent(eStudent, student->No, student->ID, student->FirstName, student->LastName, student->gender,DOB, student->SocialID);
//				
//
//				goto catch_exception;
//			}
//			else goto catch_exception;
//		}
//
//	}
//	
//}
//void displayEnrollCourse(ListCourse* nCourse, NodeStudent* student) {
//	ListCourse* eCourse;
//	
//	enrollanddisplay(nCourse, student);
//	OutputListCourse(eCourse);
//
//}
//void displayEnrollCourse(ListCourse* nCourse, NodeStudent* student) {
//	ListStudent* eStudent;
//	enrollanddisplay(nCourse, student);
//	OutputListStudents(eStudent);
//}

//void displayEnrollCourse(ListCourse* nCourse, ListCourse* eCourse, NodeStudent* enStudent) {
//	NodeCourse* EnrollCourse = new NodeCourse;
//	Enroll(nCourse, enStudent);
//	eCourse->head = EnrollCourse;
//	OutputListCourse(eCourse);
//}
//void viewListStudentinaCourse(ListCourse* nCourse, ListStudent* nStudent, NodeStudent* enStudent) {
//	Enroll(nCourse, enStudent);
//	nStudent->head = enStudent;
//	OutputListStudents(nStudent);
//}

//ViewScoreBoard 
// 
// error function so i comment it 
// 
//void ViewScoreBoard( ScoreList listSc,ListStudent listSt) {
//	std::string input;
//	std::cout << "input your ID: ";
//	std::getline(std::cin, input);
//	for (Score* cur = listSc.Head; cur != nullptr; cur = cur->next) {
//		if (cur->StudentID == input) {
//			system("cls");
//			std::cout << "ScoreBoard" << "\n" << std::endl;
//			std::cout << "StudentID: " << cur->StudentID << std::endl;
//			std::cout << "Student FullName: " << cur->StudentFullName << std::endl;
//			std::cout << "MidTerm Mark: " << cur->MidTermMark << std::endl;
//			std::cout << "Final Mark: " << cur->FinalMark << std::endl;
//			std::cout << "Other Mark: " << cur->OtherMark << std::endl;
//			std::cout << "Total Mark: " << cur->TotalMark << std::endl;
//		}
//	}
//

void ViewScoreBoard( ListScore listSc,ListStudent listSt) {
	std::string input;
	std::cout << "input your ID: ";
	std::getline(std::cin, input);
	for (NodeScore* cur = listSc.head; cur != nullptr; cur = cur->next) {
		if (cur->ID == input) {
			system("cls");
			std::cout << "ScoreBoard" << "\n" << std::endl;
			std::cout << "StudentID: " << cur->ID << std::endl;
			std::cout << "Student FullName: " << cur->FirstName<<" "<<cur->LastName << std::endl;
			std::cout << "MidTerm Mark: " << cur->MidtermMark << std::endl;
			std::cout << "Final Mark: " << cur->Finalmark << std::endl;
			std::cout << "Other Mark: " << cur->Othermark << std::endl;
			std::cout << "Total Mark: " << cur->TotalMark << std::endl;
		}
	}
}

//Incorrect function purpose
//void Create_a_Course_registration_session(ListCourse& List,NodeCourse*nCourse) {
//	cout << "input the date start: " << endl;
//	cin >> nCourse->start.day;
//	cin >> nCourse->start.month;
//	cin >> nCourse->start.year;
//	cout <<"the date start this course:"<< nCourse->start.day << "-" << nCourse->start.month << "-" << nCourse->start.year << endl;
//	cout << "input the date end:"<<endl;
//	cin >> nCourse->end.day;
//	cin >> nCourse->end.month;
//	cin >> nCourse->end.year;
//	cout <<"the date end this course:"<< nCourse->end.day << "-" << nCourse->end.month << "-" << nCourse->end.year << endl;
//}
