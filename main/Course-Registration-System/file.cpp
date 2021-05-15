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
	if (a == "Nu") return false;
	else if (a == "Nam") return true;
	return false;
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

void ExportCourseScoreBoard(NodeCourse* nCourse)
{
	std::string path = "Score_" + nCourse->ID + "_" + nCourse->name + "_" + nCourse->TeacherName + ".csv";
	NodeStudent* pCur = nCourse->cClass->head;

	std::ofstream fout(path);
	if (fout.is_open())
	{
		fout << "No,StudentID,FirstName,LastName,Total_Mark,Midterm_Mark,Other_Mark\n";
		while (pCur)
		{
			fout << pCur->No << ","
				<< pCur->ID << ","
				<< pCur->FirstName << ","
				<< pCur->LastName << ","
				<< ",,,\n";
			pCur = pCur->next;
		}
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
				read[3],						// First Name
				read[2],						// Last Name
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


void write_csv(std::string filename, std::vector<std::pair<std::string, std::vector<int>>> dataset) {
	std::ofstream myFile(filename);

	for (int j = 0; j < dataset.size(); ++j)
	{
		myFile << dataset.at(j).first;
		if (j != dataset.size() - 1) myFile << ","; 
	}
	myFile << "\n";

	
	for (int i = 0; i < dataset.at(0).second.size(); ++i)
	{
		for (int j = 0; j < dataset.size(); ++j)
		{
			myFile << dataset.at(j).second.at(i);
			if (j != dataset.size() - 1) myFile << ","; 
		}
		myFile << "\n";
	}

	
	myFile.close();
}
void writeScoreboard() {
	
	std::vector<int> vec1(10, 0);
	std::vector<int> vec2(10, 0);
	std::vector<int > vec3(10, 0);

	std::vector<int> vec4(10, 0);
	std::vector<int> vec5(10, 0);
	std::vector<int> vec6(10, 0);
	std::vector<int> vec7(10, 0);
	std::vector<std::pair<std::string, std::vector<int>>> vals = { {"NO", vec1}, {"ID", vec2}, {"FULL NAME", vec3}, {"MID MARK", vec4} ,{"FINAL MARK", vec5} ,{"OTHER MARK", vec6} ,{"TOTAL MARK", vec7} };
	write_csv("7_cols.csv", vals);
}

bool WriteAll(std::string path, ListYear* nYear)
{
	if (!nYear) return false;
	else if (!nYear->head) return false;

	std::ofstream fout(path, std::ios::binary);
	if (fout.is_open())
	{
		int numYear = getSize(nYear->head);
		int numSem, numCourse;
		int numClass, numStu;
		fout.write((char*)&numYear, sizeof(int));

		//Loop the ListYear to write each Year
		for (int i = 1; i <= numYear; i++)
		{
			//NodeYear info
			NodeYear* CurYear = getNode(nYear->head, i);
			numClass = getSize(CurYear->classes->head);
			numSem = getSize(CurYear->semesters->head);
			fout.write((char*)&numClass, sizeof(int));
			fout.write((char*)&numSem, sizeof(int));
			fout.write((char*)&CurYear->startYear, sizeof(date));
			fout.write((char*)&CurYear->endYear, sizeof(date));

			//Loop the ListClass to write each classes info	
			for (int classes = 1; classes <= numClass; classes++)
			{
				//NodeClass info
				NodeClass* CurClass = getNode(CurYear->classes->head, classes);
				fout.write((char*)&CurClass->no, sizeof(int));
				fout.write((char*)&CurClass->name, sizeof(std::string));

				//For each class, write student info
				numStu = getSize(CurClass->Students->head);
				fout.write((char*)&numStu,sizeof(int));
				for (int stu = 1; stu <= numStu; stu++)
				{
					//NodeStudent info
					NodeStudent* CurStu = getNode(CurClass->Students->head, stu);
					fout.write((char*)&CurStu->No, sizeof(int));
					fout.write((char*)&CurStu->ID, sizeof(std::string));
					fout.write((char*)&CurStu->FirstName, sizeof(std::string));
					size_t strsize = CurStu->LastName.size();
					fout.write((char*)&strsize, sizeof(size_t));
					fout.write(CurStu->LastName.c_str(), strsize);
					fout.write((char*)&CurStu->gender, sizeof(bool));
					fout.write((char*)&CurStu->DOB, sizeof(date));
					fout.write((char*)&CurStu->SocialID, sizeof(std::string));
					//Table
					int numTb = CountTb(CurStu->tb);
					fout.write((char*)&numTb, sizeof(int));
					for (int row = 0; row < 4; row++)
						for (int col = 0; col < 6; col++)
						{
							if (CurStu->tb->Week[row][col] == 1)
							{
								fout.write((char*)&row, sizeof(int));
								fout.write((char*)&col, sizeof(int));
							}
						}
				}
			}

			//Loop the ListSem to write each semester info			
			for (int sem = 1; sem <= numSem; sem++)
			{
				//NodeSem info
				NodeSem* CurSem = getNode(CurYear->semesters->head, sem);
				fout.write((char*)&CurSem->type, sizeof(int));
				fout.write((char*)&CurSem->start, sizeof(date));
				fout.write((char*)&CurSem->end, sizeof(date));

				//For each semester, write courses info
				numCourse = getSize(CurSem->Courses->head);
				fout.write((char*)&numCourse, sizeof(int));
				for (int course = 1; course <= numCourse; course++)
				{
					//NodeCourse info
					NodeCourse* CurCourse = getNode(CurSem->Courses->head, course);
					fout.write((char*)&CurCourse->ID, sizeof(std::string));
					fout.write((char*)&CurCourse->name, sizeof(std::string));
					fout.write((char*)&CurCourse->TeacherName, sizeof(std::string));
					fout.write((char*)&CurCourse->credit, sizeof(int));
					fout.write((char*)&CurCourse->max, sizeof(int));
					//Table
					int numTb = CountTb(CurCourse->tb);
					fout.write((char*)&numTb, sizeof(int));
					for (int row = 0; row < 4; row++)
						for (int col = 0; col < 6; col++)
						{
							if (CurCourse->tb->Week[row][col] == 1)
							{
								fout.write((char*)&row, sizeof(int));
								fout.write((char*)&col, sizeof(int));
							}
						}
					//Course class
					numStu = getSize(CurCourse->cClass->head);
					fout.write((char*)&numStu, sizeof(int));
					for (int stu = 1; stu <= numStu; stu++)
					{
						//NodeStudent info
						NodeStudent* CurStu = getNode(CurCourse->cClass->head, stu);
						fout.write((char*)&CurStu->No, sizeof(int));
						fout.write((char*)&CurStu->ID, sizeof(std::string));
						fout.write((char*)&CurStu->FirstName, sizeof(std::string));
						size_t strsize = CurStu->LastName.size();
						fout.write((char*)&strsize, sizeof(size_t));
						fout.write(CurStu->LastName.c_str(), strsize);
						fout.write((char*)&CurStu->gender, sizeof(bool));
						fout.write((char*)&CurStu->DOB, sizeof(date));
						fout.write((char*)&CurStu->SocialID, sizeof(std::string));
					}
				}
			}

		}
		fout.close();
	}
	return true;
}

bool ReadAll(std::string path, ListYear*& nYear)
{
	if (nYear != nullptr) DeleteListYear(nYear); //overwrite	
	createEmptyList(nYear);

	std::ifstream fin(path, std::ios::binary);
	if (fin.is_open())
	{
		//Year Info
		int numYear;
		int numSem, numCourse;
		int numClass, numStu;

		//Class Info
		int no;
		std::string name;

		//Student Info
		int stuNo;
		bool gender;
		date DOB;
		std::string stuID, FirstName, LastName, SocialID;
		TimeTable* tb = nullptr;

		//Sem Info
		int type;
		date start, end;

		//Course Info
		std::string ID, cName, TeacherName;
		int max, credit;

		//TimeTable Info
		int numTb, row, col;

		fin.read((char*)&numYear, sizeof(int));
		for (int i = 0; i < numYear; i++)
		{
			AddYear(nYear);
			//Year Info
			fin.read((char*)&numClass, sizeof(int));
			fin.read((char*)&numSem, sizeof(int));
			fin.read((char*)&nYear->tail->startYear, sizeof(date));
			fin.read((char*)&nYear->tail->endYear, sizeof(date));

			for (int classes = 0; classes < numClass; classes++)
			{

				fin.read((char*)&no, sizeof(int));
				fin.read((char*)&name, sizeof(std::string));
				fin.read((char*)&numStu, sizeof(int));
				AddClass(nYear->tail->classes, no, name);
				
				for (int stu = 0; stu < numStu; stu++)
				{		
					CreateTable(tb);
					//Student Info
					fin.read((char*)&stuNo, sizeof(int));
					fin.read((char*)&stuID, sizeof(std::string));
					fin.read((char*)&FirstName, sizeof(std::string));
					size_t strsize = 0;
					fin.read((char*)&strsize, sizeof(size_t));
					char* temp = new char[strsize + 1];
					fin.read(temp, strsize);
					temp[strsize] = '\0';
					LastName = temp;
					delete[]temp;
					fin.read((char*)&gender, sizeof(bool));
					fin.read((char*)&DOB, sizeof(date));
					fin.read((char*)&SocialID, sizeof(std::string));
					//Table
					fin.read((char*)&numTb, sizeof(int));
					for (int j = 0; j < numTb; j++)
					{
						fin.read((char*)&row, sizeof(int));
						fin.read((char*)&col, sizeof(int));
						tb->Week[row][col] = 1;
					}

					AddStudent(nYear->tail->classes->tail->Students, stuNo, stuID, FirstName, LastName, gender, DisplayDate(DOB), SocialID);
					CopyTb(nYear->tail->classes->tail->Students->tail->tb, tb);
					DeleteTable(tb);
				}
			}

			for (int sem = 0; sem < numSem; sem++)
			{
				fin.read((char*)&type, sizeof(int));
				fin.read((char*)&start, sizeof(date));
				fin.read((char*)&end, sizeof(date));
				AddSemester(nYear->tail->semesters, type, start, end);

				fin.read((char*)&numCourse, sizeof(int));
				for (int course = 1; course <= numCourse; course++)
				{
					tb = nullptr;
					CreateTable(tb);

					fin.read((char*)&ID, sizeof(std::string));
					fin.read((char*)&cName, sizeof(std::string));
					fin.read((char*)&TeacherName, sizeof(std::string));
					fin.read((char*)&credit, sizeof(int));
					fin.read((char*)&max, sizeof(int));
					//Table
					fin.read((char*)&numTb, sizeof(int));
					for (int j = 0; j < numTb; j++)
					{
						fin.read((char*)&row, sizeof(int));
						fin.read((char*)&col, sizeof(int));
						tb->Week[row][col] = 1;
					}
					AddCourse(nYear->tail->semesters->tail->Courses, ID, cName, TeacherName, credit, tb, max);
					//Course class
					fin.read((char*)&numStu, sizeof(int));
					for (int stu = 1; stu <= numStu; stu++)
					{
						//Student Info
						fin.read((char*)&stuNo, sizeof(int));
						fin.read((char*)&stuID, sizeof(std::string));
						fin.read((char*)&FirstName, sizeof(std::string));
						size_t strsize = 0;
						fin.read((char*)&strsize, sizeof(size_t));
						char* temp = new char[strsize + 1];
						fin.read(temp, strsize);
						temp[strsize] = '\0';
						LastName = temp;
						delete[]temp;
						fin.read((char*)&gender, sizeof(bool));
						fin.read((char*)&DOB, sizeof(date));
						fin.read((char*)&SocialID, sizeof(std::string));
						AddStudent(nYear->tail->semesters->tail->Courses->tail->cClass, stuNo, stuID, FirstName, LastName, gender, DisplayDate(DOB), SocialID);
					}
					DeleteTable(tb);
				}
			}
		}
		fin.close();
	}
	return true;
}