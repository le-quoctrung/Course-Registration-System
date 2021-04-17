#include "file.h"

bool checkGender(std::string a)
{
	if (a == "Nu") return 0;
	else if (a == "Nam") return 1;
}

void Read_List_to_Class(string name, Class* nClass)
{
	ifstream file(name);

	if (file.is_open())
	{
		string tmp;
		vector<string> read;

		while (!file.eof())
		{
			if (!std::getline(file, tmp)) return;
			read = split(tmp, ",");

			addStudent(nClass,					// Add into what class
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

void CreateStudentAccounts(Class* nClass)
{
	std::ofstream write("db\\students.txt", std::ios::app);
	if (write.is_open())
	{
		while (nClass->Students != nullptr)
		{
			write << nClass->Students->ID << "," << nClass->Students->DOB.year 
												<< nClass->Students->DOB.month
												<< nClass->Students->DOB.day << std::endl;
			nClass->Students = nClass->Students->next;
		}
		write.close();
	}
}

void Output_Student(Student* pHead)
{
	Student* pCur = pHead;
	while (pCur != nullptr)
	{
		cout << pCur->No << " " << pCur->ID << " " << pCur->LastName << " " << pCur->gender << " " << displayDate(pCur->DOB) << " " << pCur->SocialID << endl;
		pCur = pCur->next;
	}
}

void WriteFile(string name, Student* A, int n)
{
	fstream fout;
}

void Read_a_Course(string file, Course*& C)
{
	ifstream fin(file, ios::in);
	while (fin.is_open()) {
		string line;
		vector<string>read;

		fin >> line;
		read = split(line, ",");

		C->ID = read[0];
		C->name = read[1];
		C->TeacherName = read[2];
		C->credit = stoi(read[3]);
		C->max = stoi(read[4]);
		fin.close();
	}
}