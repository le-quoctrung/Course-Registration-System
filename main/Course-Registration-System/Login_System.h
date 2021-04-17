#ifndef _LOGIN_SYSTEM_H_
#define _LOGIN_SYSTEM_H_


#include <iostream>
#include <string>
#include <fstream>
#include<conio.h>

#include "school.h"
#include"Console.h"
#include"display.h"
#include "file.h"

struct User
{
	std::string _name;
	std::string _pass;
	bool type; 	//0 - student
				//1 - staff
};

/*	FUNCTIONS	*/
int checkLogin(std::string name, std::string pass);					//	checkLogin returns
																	//	-1	- password not match
																	//	0	- student
																	//	1	- staff
																	//	404 - file not found

void login();														//call first to run all login function
#endif // !_LOGIN_SYSTEM_H_