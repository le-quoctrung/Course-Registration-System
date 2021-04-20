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
		while (!fin.eof()) {
			fin >> line;
			read = split(line, ",");
			
			createCourse(C, read[1], read[0], read[2], read[4], stoi(read[3]),stoi(read[5]));
			
		}

			fin.close();
		
	}
}
void EditStu(Student student[], int index)
{
	string stuid, ID, Last_name, First_name, Dob;
	bool gender;
	cout << "Enter the student's ID you want to change: ";
	cin >> stuid;
	ofstream out;
	out.open("allStudent.csv", std::ofstream::trunc);
	if (!out)
	{
		cout << "Error!\n";
	}
	else
	{
		for (int i = 0; i < index; i++)
		{
			if (student[i].ID == stuid)
			{
				cout << "1. Change ID\n" << "2. Change last name\n" << "3. Change first name\n" << "4. Change gender\n" << "5. Change DoB\n";
				int e;
				cin >> e;
				switch (e)
				{
				case 1:
					cout << "New ID: ";
					cin >> ID;
					student[i].ID = ID;
					break;
				case 2:
					cout << "New last name: ";
					cin >> Last_name;
					student[i].LastName = Last_name;
					break;
				case 3:
					cout << "New first name: ";
					cin >> First_name;
					student[i].FirstName = First_name;
					break;
				case 4:
					cout << "New gender: ";
					cin >> gender;
						student[i].gender = gender;
					break;
				case 5:
					cout << "New dob: ";
					cin >> Dob;
					student[i].DOB = Dob;
					break;
				}

			}
		}
		out << "No,Student ID,Lastname,Firstname,Gender,DoB\n";
		for (int i = 0; i < index; i++)
		{
			out << student[i].No << ",";
			out << student[i].ID << ",";
			out << student[i].LastName << ",";
			out << student[i].FirstName << ",";
			out << student[i].gender << ",";
			out << student[i].DOB << endl;
		}
		out.close();
	}
}
void writeFileinaCourse(Student*&stu,Course*course1) {
	ofstream fout;
	fout.open("studentACourse.txt", ios::out);
	exportList(stu, course1);
	fout.close();
}