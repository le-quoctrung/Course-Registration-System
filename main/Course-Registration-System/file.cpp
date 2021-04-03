#include "file.h"
void ReadFile(string name, student*& A, int& n)
{
	fstream fin;
	fin.open(name);
	while (fin.is_open())
	{
		string tmp;
		fin >> n;
		vector<string> read;

		A = new student[n];
		for (int i = 0; i < n; i++)
		{
			fin >> tmp;
			read = split(tmp, ",");
			A[i].No = stoi(read[0]);
			A[i].ID = read[1];
			A[i].FirstName = read[2];

			A[i].LastName = read[3];
			A[i].gender = stoi(read[4]);
			A[i].DOB = read[5];
			A[i].SocialID = read[6];
		}
		fin.close();

	}

}
void Output(student* A, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i].No << " " << " " << A[i].ID << " " << A[i].FirstName << " " << A[i].LastName << " " << A[i].gender << " " << A[i].DOB << " " << A[i].SocialID << endl;
	}
}
void WriteFile(string name, student* A, int n)
{
	fstream fout;

}