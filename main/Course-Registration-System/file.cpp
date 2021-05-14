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
	return -1;
}

int CheckLogin(std::string name, std::string pass)
{
	if (!CheckFile(pathStudentAccounts)
		&& !CheckFile(pathStaffAccounts)) return 404;
	//if (name == "admin" && pass == "admin") return 1;

	std::ifstream file(pathStudentAccounts, std::ios::in);
	if (file.is_open())
	{
		std::string check;
		std::vector<std::string> line;

		while (!file.eof())
		{
			std::getline(file, check);
			if (check == "") break;
			line = split(check, ",");

			if (name == line[0])
			{
				//check password
				if (pass == line[1]) return 0;
				else return -1;
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
			if (check == "") break;
			line = split(check, ",");

			if (name == line[0])
			{
				// password
				if (pass != line[1])
				{
					return -1;
				}
				else return 1;
			}
		}
		file.close();
	}
	
	return 404;
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
	std::ifstream file(path, std::ios::in);
	if (file.is_open())
	{
		std::string tmp;
		std::vector<std::string> read;

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

void ReadListStudentToClass(std::string path, NodeClass* nClass)
{
	if (!nClass) return;
	std::ifstream file(path, std::ios::in);

	if (file.is_open())
	{
		std::string tmp;
		std::vector<std::string> read;

		while (!file.eof())
		{
			if (!std::getline(file, tmp)) return;
			read = split(tmp, ",");

			AddStudent(nClass->Students,		// Add into what class
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

void ReadListToCourse(std::string path, ListCourse* nCourse)
{
	std::ifstream file(path, std::ios::in);
	if (file.is_open())
	{
		std::string tmp;
		std::vector<std::string> read;

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

			AddCourse(nCourse, 
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

void Enroll(ListCourse* nCourse,NodeCourse*EnrollCourse)
{
	//int n = 1;
	if (!nCourse) return;
     EnrollCourse = new NodeCourse;

	NodeCourse* pCur = nCourse->head;
	while (pCur != nullptr)
	{
		system("CLS");
		OutputCourse(pCur);
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
				std::cout << "\n\n\t\tEnrolled ";
				EnrollCourse = pCur;
				goto catch_exception;
			}
			else goto catch_exception;
		}
	}
}

void displayEnrollCourse(ListCourse* nCourse, NodeCourse* EnrollCourse, ListCourse* eCourse) {
	
	Enroll(nCourse, EnrollCourse);
	eCourse->head = EnrollCourse;
	OutputListCourse(eCourse);
}

NodeCourse* FindCourse(ListCourse* nCourse, std::string ID, std::string teacher)
{
	if (!nCourse) return nullptr;

	NodeCourse* pCur = nCourse->head;
	while (pCur != nullptr)
	{
		if (pCur->ID == ID && pCur->TeacherName == teacher)
			return pCur;
		pCur = pCur->next;
	}

	return nullptr;
}

void UpdateCourse(ListCourse*& nCourse, std::string ID, std::string teacher)
{
	if (!nCourse) return;

	NodeCourse* pCur = FindCourse(nCourse, ID, teacher);
	if (!pCur) return;
	OutputCourse(pCur);
	std::string str, str2;
	int n;
	TimeTable* tmp = new TimeTable;
	CreateTable(tmp);
	CopyTb(pCur->tb, tmp); //Reset table
	std::cout << "ID (string): "; std::cin >> str; pCur->ID = str;
	std::cout << "Name (string): "; std::cin >> str; pCur->name = str;
	std::cout << "Teacher (string): "; std::cin >> str; pCur->TeacherName = str;
	std::cout << "Credit (int): "; std::cin >> n; pCur->credit = n;
	std::cout << "Max Antendee (int): "; std::cin >> n; pCur->max = n;

	//HANDLE EXCEPTIONS
	do
	{
		std::cout << "First class - Day [MON, TUE, WED, THU, FRI, SAT]: "; std::cin >> str;
	} while (str != "MON" && str != "TUE" && str != "WED" && str !="THU" && str !="FRI" && str != "SAT");
	do
	{
		std::cout << "First class - Period [S1, S2, S3, S4]: "; std::cin >> str2;
	} while (str2 != "S1" && str2 != "S2" && str2 != "S3" && str2 != "S4");
	ParseTb(pCur->tb, str, str2);

	//HANDLE EXCEPTIONS
	do
	{
		std::cout << "Second class - Day [MON, TUE, WED, THU, FRI, SAT]: "; std::cin >> str;
	} while (str != "MON" && str != "TUE" && str != "WED" && str != "THU" && str != "FRI" && str != "SAT");
	do
	{
		std::cout << "Second class - Period [S1, S2, S3, S4]: "; std::cin >> str2;
	} while (str2 != "S1" && str2 != "S2" && str2 != "S3" && str2 != "S4");
	ParseTb(pCur->tb, str, str2);

	DeleteTable(tmp);
	std::cout << "\n\n";
	OutputCourse(pCur); //Debug
}

void DeleteCourse(ListCourse*& nCourse, std::string ID, std::string teacher)
{
	if (!nCourse) return;

	NodeCourse* pCur = FindCourse(nCourse, ID, teacher);
	if (!pCur) return;
	OutputCourse(pCur);
	std::string x;
	std::cout << "\n\nDELETE THIS COURSE? Y/N"; std::cin >> x;

	if (x == "Y" || x == "y")
	{
		//head
		if (pCur->prev == nullptr)
		{
			pCur->next->prev = nullptr;
			nCourse->head = pCur->next;
		}
		//tail
		else if (pCur->next == nullptr)
		{
			pCur->prev->next = nullptr;
			nCourse->tail = pCur->prev;
		}
		else
		{
			pCur->prev->next = pCur->next;
			pCur->next->prev = pCur->prev;
		}
		delete(pCur);
	}
	else if (x == "N" || x == "n")
		return;
}

//Export List Student to file Csv
