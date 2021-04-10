#include "file.h"

void ReadFile(string name, student*& pHead)
{
	fstream fin;
	fin.open(name);
	student* pCur = new student;
	pHead = pCur;
	string tmp;
	vector<string> read;
	while (fin.eof())
	{
		fin >> tmp;
		read = split(tmp, ",");
		pCur->No = stoi(read[0]);
		pCur->ID = read[1];
		pCur->FirstName = read[2];
		pCur->LastName = read[3];
		pCur->gender = stoi(read[4]);
		pCur->DOB = read[5];
		pCur->SocialID = read[6];
		pCur->pNext = new student;
		pCur = pCur->pNext;
	}
	fin.close();
	
}
void Output(student* pHead)
{
	/*for (int i = 0; i < n; i++)
	{
		cout << A[i].No << " " << " " << A[i].ID << " " << A[i].FirstName << " " << A[i].LastName << " " << A[i].gender << " " << A[i].DOB << " " << A[i].SocialID << endl;
	}*/
	student* pCur = pHead;
	while (pCur)
	{
		cout << pCur->No << " " << pCur->ID << " " << pCur->LastName << " " << pCur->gender << " " << pCur->DOB << " " << pCur->SocialID << endl;
		pCur = pCur->pNext;
	}
}

void WriteFile(string name, student* A, int n)
{
	fstream fout;
}

void readfile(string file, course*& C)
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