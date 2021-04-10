#pragma once
#include<iostream>
#include<string>

using namespace std;

struct date
{
	int year, month, day;
};
struct student
{
	string ID, FirstName, LastName, SocialID;
	int No;
	string DOB;
	bool gender;
	student* pNext;
};
struct day
{
	int sessions;
};
struct course
{
	string TeacherName, ID, name;
	date start, end;
	int credit;
	student* pStudent;
	int max = 50;
	day Day;
};
struct sem
{
	date start, end;
	course* pCourse;
	int type;
};
struct Class
{
	student* pStudents;
};
struct year
{
	sem Sem[3];
	Class* classes;
};