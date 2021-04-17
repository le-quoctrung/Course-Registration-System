#ifndef _LOGIN_SYSTEM_H_
#define _LOGIN_SYSTEM_H_


#include <iostream>
#include <string>
#include <fstream>
#include "school.h"

#include<conio.h>
#include"Console.h"
#include"display.h"

struct User
{
	std::string _name;
	std::string _pass;
	bool type; 	//0 - student
				//1 - staff
};

/*	FUNCTIONS	*/
bool checkFile(std::string name);
int checkLogin(std::string name, std::string pass);					//	checkLogin returns
																	//	-1	- password not match
																	//	0	- student
																	//	1	- staff
																	//	404 - file not found

User viewProfile(std::string path);									//Returns User data type, containing information from the file
void changePass(std::string name, std::string pass);				//Call registering for rewriting and adding new password

void login();														//call first to run all login function
#endif // !_LOGIN_SYSTEM_H_