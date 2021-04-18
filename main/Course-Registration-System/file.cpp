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

			addStudent( nClass,					// Add into what class
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

void Output_Student(Student* pHead)
{
	/*for (int i = 0; i < n; i++)
	{
		cout << A[i].No << " " << " " << A[i].ID << " " << A[i].FirstName << " " << A[i].LastName << " " << A[i].gender << " " << A[i].DOB << " " << A[i].SocialID << endl;
	}*/
	Student* pCur = pHead;
	while (pCur)
	{
		cout << pCur->No << " " << pCur->ID << " " << pCur->LastName << " " << pCur->gender << " " << pCur->DOB << " " << pCur->SocialID << endl;
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