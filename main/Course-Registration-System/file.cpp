#include "file.h"

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

void ReadListToClass(std::string name, NodeClass* nClass)
{
	if (!nClass) return;
	ifstream file(name);

	if (file.is_open())
	{
		string tmp;
		vector<string> read;

		while (!file.eof())
		{
			if (!std::getline(file, tmp)) return;
			read = split(tmp, ",");

			addStudent(nClass->Students,		// Add into what class
						stoi(read[0]),			// No
						read[1],				// ID
						read[2],				// First Name
						read[3],				// Last Name
						checkGender(read[4]),	// Gender (0 - female; 1 - male)
						read[5],				// Date of birth
						read[6]					// Social ID
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
			write <<   pCur->ID << "," 
					<< pCur->DOB.year
					<< pCur->DOB.month
					<< pCur->DOB.day << std::endl;

			pCur = pCur->next;
		}
		write.close();
	}
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

			if (name == line[0])
			{
				//check password
				if (pass != line[1])
				{
					return -1;
				}
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

	switch (type)
	{
	case 0:
	{
		ListAccount* list = new ListAccount;
		createEmptyList(list);

		//READ DATABASE
		ifstream file(name);
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

		//WRITE BACK ONTO DATABASE
		delete list;
		break;
	}
	case 1:
	{
		break;
	}
	}
}

//void Read_List_to_Class(string name, Class* nClass)
//{
//	ifstream file(name);
//
//	if (file.is_open())
//	{
//		string tmp;
//		vector<string> read;
//
//		while (!file.eof())
//		{
//			if (!std::getline(file, tmp)) return;
//			read = split(tmp, ",");
//
//			addStudent(nClass,					// Add into what class
//						stoi(read[0]),			// No
//						read[1],				// ID
//						read[2],				// First Name
//						read[3],				// Last Name
//						checkGender(read[4]),	// Gender (0 - female; 1 - male)
//						read[5],				// Date of birth
//						read[6]					// Social ID
//			);
//		}
//		file.close();
//	}
//}
//
//void CreateStudentAccounts(Class* nClass)
//{
//	std::ofstream write("db\\students.txt", std::ios::app);
//	if (write.is_open())
//	{
//		while (nClass->Students != nullptr)
//		{
//			write << nClass->Students->ID << "," << nClass->Students->DOB.year 
//												<< nClass->Students->DOB.month
//												<< nClass->Students->DOB.day << std::endl;
//			nClass->Students = nClass->Students->next;
//		}
//		write.close();
//	}
//}
//
//void Output_Student(Student* pHead)
//{
//	Student* pCur = pHead;
//	while (pCur != nullptr)
//	{
//		cout << pCur->No << " " << pCur->ID << " " << pCur->LastName << " " << pCur->gender << " " << displayDate(pCur->DOB) << " " << pCur->SocialID << endl;
//		pCur = pCur->next;
//	}
//}
//
//void WriteFile(string name, Student* A, int n)
//{
//	fstream fout;
//}
//
//void Read_a_Course(string file, Course*& C)
//{
//	ifstream fin(file, ios::in);
//	while (fin.is_open()) {
//		string line;
//		vector<string>read;
//
//		fin >> line;
//		read = split(line, ",");
//
//		C->ID = read[0];
//		C->name = read[1];
//		C->TeacherName = read[2];
//		C->credit = stoi(read[3]);
//		C->max = stoi(read[4]);
//		fin.close();
//	}
//}