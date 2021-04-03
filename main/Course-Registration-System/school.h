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
};
struct day
{
	int sessions[4];
};
struct course
{
	string TeacherName, ID, name;
	date start, end;
	int credit;
	student* Students;
	int max = 50;
	day Day;
};
struct sem
{
	date start, end;
	course* Courses;
	int type;
};
struct Class
{
	student* Students;
};
struct year
{
	sem Sem[3];
	Class* classes;
};