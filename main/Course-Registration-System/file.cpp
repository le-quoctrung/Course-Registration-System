#include "file.h"

bool is_digits(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i])) return false;
	}
	return true;
}

bool CheckFile(std::string path)
{
	std::ifstream check(path);
	if (check.is_open())
	{
		check.close();
		return true;
	}
	return false;
}

bool checkGender(std::string a)
{
	if (a == "Nu") return 0;
	else if (a == "Nam") return 1;
}

std::string getGender(bool a)
{
	if (a == 0) return "Nu";
	else if (a == 1) return "Nam";
}

int CheckLogin(std::string name, std::string pass)
{
	if (!CheckFile(pathStudentAccounts)
		&& !CheckFile(pathStaffAccounts)) return 404;

	std::ifstream file(pathStudentAccounts, std::ios::in);
	if (file.is_open())
	{
		std::string check;
		std::vector<std::string> line;

		while (!file.eof())
		{
			std::getline(file, check);

			line = split(check, ",");

			if (name == line[1])
			{
				//check password
				if (pass != line[6]) return -1;
				else return 0;
			}
		}
		file.close();
	}

	file.open(pathStaffAccounts, std::ios::in);
	if (file.is_open())
	{
		std::string check;
		std::vector<std::string> line;

		while (!file.eof())
		{
			std::getline(file, check);

			line = split(check, ",");

			if (name == line[0])
			{
				//check password
				if (pass != line[1])
				{
					return -1;
				}
				else return 1;
			}
		}
		file.close();
	}
}

void ReadListStudentToClass(std::string path, NodeClass* nClass)
{
	if (!nClass) return;
	ifstream file(path, std::ios::in);

	if (file.is_open())
	{
		string tmp;
		vector<string> read;

		while (!file.eof())
		{
			if (!std::getline(file, tmp)) return;
			read = split(tmp, ",");

			addStudent(nClass->Students,		// Add into what class
				stoi(read[0]),					// No
				read[1],						// ID
				read[2],						// First Name
				read[3],						// Last Name
				checkGender(read[4]),			// Gender (0 - female; 1 - male)
				read[5],						// Date of birth
				read[6]							// Social ID
			);
		}
		file.close();
	}
}

void OutputListStudents(NodeClass* nClass)
{
	if (!nClass) return;

	NodeStudent* pCur = nClass->Students->head;
	while (pCur != nullptr)
	{
		std::cout << pCur->No << " "
			<< pCur->ID << " "
			<< pCur->FirstName << " "
			<< pCur->LastName << " "
			<< getGender(pCur->gender) << " "
			<< displayDate(pCur->DOB) << " "
			<< pCur->SocialID << std::endl;

		pCur = pCur->next;
	}
}

void CreateStudentAccounts(NodeClass* nClass)
{
	if (!nClass) return;

	std::ofstream write(pathStudentAccounts, std::ios::app);
	if (write.is_open())
	{
		NodeStudent* pCur = nClass->Students->head;
		while (pCur != nullptr)
		{
			write << pCur->ID << ","
				<< pCur->DOB.year
				<< pCur->DOB.month
				<< pCur->DOB.day << std::endl;

			pCur = pCur->next;
		}
		write.close();
	}
}

void addAccount(ListAccount*& list, std::string name, std::string pass)
{
	if (!list) return;

	NodeAccount* newAcc = new NodeAccount;
	newAcc->password = pass;
	newAcc->username = name;
	newAcc->next = nullptr;

	//empty head? make new head
	if (!list->head)
	{
		list->head = list->tail = newAcc;
		return;
	}

	list->tail->next = newAcc;
	list->tail = newAcc;
}

void deleteListAccount(ListAccount*& list)
{
	NodeAccount* cur = list->head;
	NodeAccount* tmp = nullptr;

	while (!cur)
	{
		tmp = cur->next;
		delete(cur);
		cur = tmp;
	}

	list->head = nullptr;
	list->tail = nullptr;
}

int ChangePassword(std::string name, std::string pass, std::string newPass)
{
	int type = CheckLogin(name, pass);
	if (type == 404 || type == -1) return 0;


	std::string path = "";
	switch (is_digits(name))
	{
	case 1: {path = pathStudentAccounts; break; }
	case 0: {path = pathStaffAccounts; break; }
	}


	ListAccount* list = new ListAccount;
	createEmptyList(list);

	//READ DATABASE
	ifstream file(path, std::ios::in);
	if (file.is_open())
	{
		string tmp;
		vector<string> read;

		while (!file.eof())
		{
			if (!std::getline(file, tmp)) break;
			read = split(tmp, ",");

			addAccount(list, read[0], read[1]);
		}
		file.close();
	}

	//CHANGE PASSWORD
	NodeAccount* pCur = list->head;

	//find usename
	while (pCur != nullptr)
	{
		if (pCur->username == name) break;
		pCur = pCur->next;
	}
	if (pCur == nullptr) return 0;
	pCur->password = newPass;


	//WRITE BACK ONTO DATABASE
	std::ofstream write(path, std::ios::out);
	pCur = list->head;
	if (write.is_open())
	{
		while (pCur != nullptr)
		{
			write << pCur->username << "," << pCur->password << std::endl;
			pCur = pCur->next;
		}

		write.close();
	}

	delete list;
}

void ReadListToCourse(std::string path, ListCourse* nCourse)
{
	ifstream file(path, std::ios::in);
	if (file.is_open())
	{
		string tmp;
		vector<string> read;

		while (!file.eof())
		{
			if (!std::getline(file, tmp)) return;
			read = split(tmp, ",");
			int max = 50;
			TimeTable* tb = new TimeTable;
			CreateTable(tb);

			if (read[4] != "") max = std::stoi(read[4]);
			ParseTb(tb, read[5], read[6]);	//First session
			ParseTb(tb, read[7], read[8]);	//Second session

			addCourse(nCourse, 
				read[0], 
				read[1], 
				read[2], 
				std::stoi(read[3]), 
				tb,
				max);

			DeleteTable(tb);
		}

		file.close();
	}
}

void OutputListCourse(ListCourse* nCourse)
{
	if (!nCourse) return;

	NodeCourse* pCur = nCourse->head;
	while (pCur != nullptr)
	{
		system("CLS");
		std::cout << pCur->ID << "\n"
			<< pCur->name << "\n"
			<< pCur->TeacherName << "\n"
			<< pCur->credit << "\n"
			<< pCur->max << "\n\n";

		DisplayTb(pCur->tb);

		std::cout << "\n\n\n<--Press A\t\tPress S to exit\t\tPress D-->";

	catch_exception:
		if (!_kbhit())
		{
			char x = _getch();
			if (x == 'a' || x == 'A')
			{
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
				if (pCur->next)
					pCur = pCur->next;
				else
				{
					std::cout << "\n\n\t\tThis is tail of a list";
					goto catch_exception;
				}
			}
			else if (x == 's' || x == 'S')
				break;
			else goto catch_exception;
		}
	}
}
void viewListofCourse( ListCourse* list,NodeCourse*cCourse) {
	createEmptyList(list);
	while (cCourse != nullptr) {
		ReadListToCourse("courses.csv", list);
		OutputListCourse(list);
		cCourse = cCourse->next;
	}
}

////fix this
//void updateCourse(Course*& nCourse, string ID, string Teachername) {
//	if (nCourse == nullptr) {
//		cout << "The list hasn't been initialized!";
//	}
//	Course* cCourse = nCourse;
//	while (cCourse != nullptr) {
//		if (cCourse->ID == ID && cCourse->TeacherName == Teachername) {
//
//			return;
//		}
//		cCourse = cCourse->next;
//
//	}
//
//}

////fix this
//void exportList(Student*& stu, Course* course1) {
//	while (stu != nullptr) {
//		if (stu->course->ID == course1->ID) {
//			cout << stu->No << " " << endl;
//			cout << stu->ID << " " << endl;
//			cout << stu->FirstName << " " << endl;
//			cout << stu->LastName << " " << endl;
//			cout << stu->gender << " " << endl;
//			cout << stu->DOB << " " << endl;
//			cout << stu->SocialID << " " << endl;
//
//		}
//		stu = stu->next;
//	}
//}