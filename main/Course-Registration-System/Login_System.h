#ifndef _LOGIN_SYSTEM_H_
#define _LOGIN_SYSTEM_H_

#include <iostream>
#include <string>
#include <fstream>

struct User
{
	std::string _name;
	std::string _pass;
	bool type; 	//0 - student
				//1 - staff
};

/*	FUNCTIONS	*/
void registering(std::string name, std::string pass, int type);		//Create a text file "[name].txt" containing username, password and type of the user

bool checkFile(std::string name);
int checkLogin(std::string name, std::string pass);					//	checkLogin returns
																	//	-2	- file corrupted
																	//	-1	- password not match
																	//	0	- student
																	//	1	- staff
																	//	404 - file not found

User viewProfile(std::string path);									//Returns User data type, containing information from the file
void changePass(User _user, std::string pass);						//Call registering for rewriting and adding new password


#endif // !_LOGIN_SYSTEM_H_