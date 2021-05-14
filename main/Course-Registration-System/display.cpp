#include "display.h"
#include"Console.h"
#include"file.h"

void loginDisplay()
{
	/***********LOGIN BOX***********/

	int  x = 140, y = 10;


	for (int i = x + 1; i < x + 60; i++)
	{
		Gotoxy(i, y);
		std::cout << char(223);
	}
	for (int i = y; i < y + 34; i++)
	{
		Gotoxy(x, i);
		std::cout << char(219);
	}
	for (int i = x + 1; i < x + 60; i++)
	{
		Gotoxy(i, y + 33);
		std::cout << char(220);
	}
	for (int i = y; i < y + 34; i++)
	{
		Gotoxy(x + 60, i);
		std::cout << char(219);
	}
	/*******login button*******/
	for (int i = x + 1; i < x + 60; i++)
	{
		Gotoxy(i, y + 25);
		std::cout << char(220);
	}
	for (int i = x + 1; i < x + 60; i++)
	{
		Gotoxy(i, y + 28);
		std::cout << char(220);
	}
	Gotoxy(x + 27, y + 27); std::cout << "LOGIN";
	/***************LOGO****************/

	int x1 = 10, y1 = 16;
	/*F*/
	for (int i = x1 + 2; i < x1 + 12; i++)
	{
		Gotoxy(i, y1);
		std::cout << char(223);
	}

	for (int i = x1 + 2; i < x1 + 10; i++)
	{
		Gotoxy(i, y1 + 3);
		std::cout << char(223);
	}
	for (int j = x1; j <= x1 + 1; j++)
	{
		for (int i = y1; i < y1 + 7; i++)
		{
			Gotoxy(j, i);
			std::cout << char(219);
		}
	}
	/*I*/

	for (int j = x1 + 17; j <= x1 + 18; j++)
	{
		for (int i = y1; i < y1 + 7; i++)
		{
			Gotoxy(j, i);
			std::cout << char(219);
		}
	}
	/*T*/
	for (int i = x1 + 24; i <= x1 + 41; i++)
	{
		Gotoxy(i, y1);
		std::cout << char(223);
	}

	for (int j = x1 + 32; j <= x1 + 33; j++)
	{
		for (int i = y1; i < y1 + 7; i++)
		{
			Gotoxy(j, i);
			std::cout << char(219);
		}
	}
	/*H*/
	for (int i = x1; i < x1 + 14; i++)
	{
		Gotoxy(i, y1 + 17);
		std::cout << char(223);
	}
	for (int j = x1; j <= x1 + 1; j++)
	{
		for (int i = y1 + 13; i < y1 + 21; i++)
		{
			Gotoxy(j, i);
			std::cout << char(219);
		}
	}

	for (int j = x1 + 14; j <= x1 + 15; j++)

	{
		for (int i = y1 + 13; i < y1 + 21; i++)
		{
			Gotoxy(j, i);
			std::cout << char(219);
		}
	}
	/*C*/
	for (int i = x1 + 21; i <= x1 + 31; i++)
	{
		Gotoxy(i, y1 + 13);
		std::cout << char(223);
	}

	for (int i = x1 + 21; i <= x1 + 31; i++)
	{
		Gotoxy(i, y1 + 20);
		std::cout << char(220);
	}
	for (int j = x1 + 19; j <= x1 + 20; j++)
	{
		for (int i = y1 + 13; i < y1 + 21; i++)
		{
			Gotoxy(j, i);
			std::cout << char(219);
		}
	}
	/*m*/



	/*USER LOGIN*/

}
void hcmusfame()
{
	for (int i = 0; i <= 210; i++)
	{
		Gotoxy(i, 10);
		std::cout << char(220);
	}
	for (int i = 0; i <= 10; i++)
	{
		Gotoxy(40, i);
		std::cout << char(219);
		Gotoxy(41, i);
		std::cout << char(219);
	}
	Gotoxy(10, 5); std::cout << "HCMUS";
}
void home_staff()
{
	/*
	At the beginning of a school year (often in September), an academic staff member will:
Create a school year (2020-2021, for example)
Create several classes for 1st year students. For example: class 20APCS1, class 20APCS2, class 20CLC1…, class 20CLC11, class 20VP…
Add new 1st year students to 1st-year classes.
For quick input, he/she can import a CSV file containing all students in a specific class to the system, instead of adding one by one: No, Student ID, First name, Last name, Gender, Date of Birth, Social ID.
He/she does not need to add 2nd year, 3rd year, or 4th-year students, because these students had been added in the previous years.

There are 3 semesters in a school year: Semester 1 (Fall), Semester 2 (Summer), and Semester 3 (Autumn).
	*/
	/*
	At the beginning of a semester, an academic staff member will:
Create a semester: 1, 2, or 3, school year, start date, end date. Choose the school year that the newly created semester belongs to. The created semester will be the current / the default semester for all the below actions.
Create a course registration session: start date, end date.
Add a course to this semester: course id, course name, teacher name, number of credits, the maximum number of students  in the course (default 50), day of the week, and the session that the course will be performed (MON / TUE / WED / THU / FRI / SAT, S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30)). A course will be taught in 2 sessions in a week.
View list of courses.
Update course information.
Delete a course.
	*/
	/*
	At the end of a semester, an academic staff member can:
Export list of students		 in a course to a CSV file
Import the scoreboard of a course. A scoreboard will have at least the following columns: No, Student ID, Student Full Name, Total Mark, Final Mark, Midterm Mark, Other Mark. (An academic staff member will export the list of students in a course, send the CSV file to the teacher, the teacher will enter student results in this file, send it back to the staff, and then the staff will import the scoreboard to the system)
View the scoreboard of a course.
Update a student result.
View the scoreboard of a class, including final marks of all courses in the semester, GPA in this semester, and the overall GPA
	*/
	//public sroceboard for student can view
home: 
	system("cls");
	hcmusfame();
	for (int i = 0; i <= 10; i++)
	{
		Gotoxy(98, i);
		std::cout << char(219);
		Gotoxy(155, i);
		std::cout << char(219);
	}
	Gotoxy(67, 5); std::cout << "YEAR";
	Gotoxy(124, 5); std::cout << "CLASS";
	Gotoxy(180, 5);  std::cout << "COURSE";

	while (1)// remember to break out of while loop
	{
		COORD coord = GetCursorClick();
		
		/********YEAR********/
		if (coord.X > 40 && coord.X < 98 && coord.Y < 10) 
		{
			system("cls");
			hcmusfame();
			for (int i = 0; i <= 10; i++)
			{
				Gotoxy(127, i);
				std::cout << char(219);
			}
			Gotoxy(75, 5); std::cout << "CREATE 1ST-YEAR";
			Gotoxy(165, 5); std::cout << "SEMESTER";
			/************************************/
			while (1) // remember to break out of while loop
			{
				coord = GetCursorClick();
				
				/*******CREATE YEAR******/
				if (coord.Y < 10 && coord.X > 41 && coord.X < 127) 
				{
					//create year functions here
					Gotoxy(100, 29); std::cout << "created year"; // for test case
					break;
				}
				
				/********SEMESTER********/
				else if (coord.X > 127 && coord.Y < 10) 
				{
					system("cls");
					hcmusfame();
					for (int i = 0; i <= 10; i++)
					{
						Gotoxy(98, i);
						std::cout << char(219);
						Gotoxy(155, i);
						std::cout << char(219);
					}
					Gotoxy(62, 5); std::cout << "CREATE SEMESTER";
					Gotoxy(110, 5); std::cout << "CREATE COURSE REGISTATION SESSION";
					Gotoxy(173, 5);  std::cout << "ADD COURSE TO SEMESTER";
					while (1)
					{
						coord = GetCursorClick();
						/********HCMUS********/
						if (coord.Y < 10 && coord.X < 40)
							goto home;

						/********CREATE SEMESTER********/
						if (coord.X > 40 && coord.X < 98 && coord.Y < 10)
						{
							std::cout << "CREATE SEMESTER";
							break;
						}

						/*********CREATE COURSE REGISTATION SESSION********/
						else if (coord.X > 98 && coord.X < 155 && coord.Y < 10)
						{
							std::cout << "CREATE COURSE REGISTATION SESSION";
							break;
						}

						/************ADD COURSE TO SEMESTER************/
						else if (coord.X > 155 && coord.Y < 10)
						{
							std::cout << "ADD COURSE TO SEMESTER";
							break;
						}
					}
					break;
				}
				
				/********HCMUS********/
				if (coord.Y < 10 && coord.X < 40)
					goto home;
			}	
			break;
		}
		
		/**********CLASS********/
		else if (coord.X > 98 && coord.X < 155 && coord.Y < 10) //class
		{
			system("cls");
			hcmusfame();
			for (int i = 0; i <= 10; i++)
			{
				Gotoxy(98, i);
				std::cout << char(219);
				Gotoxy(155, i);
				std::cout << char(219);
			}
			Gotoxy(64, 5); std::cout << "CREATE CLASS";
			Gotoxy(117, 5); std::cout << "ADD STUDENT TO CLASS";
			Gotoxy(180, 5);  std::cout << "VIEW SCORE";
			while (1)
			{
				coord = GetCursorClick();
				/********HCMUS********/
				if (coord.Y < 10 && coord.X < 40)
					goto home;

				/**********CREATE CLASS*******/
				if (coord.X > 40 && coord.X < 98 && coord.Y < 10)
				{
					std::cout << "create class";
					break;
				}

				/*********ADD STUDENT TO CLASS********/
				else if (coord.X > 98 && coord.X < 155 && coord.Y < 10)
				{
					std::cout << "added";
					break;
				}

				/*************VIEW SCORE************/
				else if (coord.X > 155 && coord.Y < 10)
				{
					system("cls");
					hcmusfame();
					Gotoxy(117, 5);
					std::cout << "PUBLIC THIS SCORE BOARD";

					// view scoreboard function here

					while (1)
					{
						coord = GetCursorClick();
						/********PUBLIC SCORE BOARD******/
						if (coord.X > 41 && coord.Y < 10)
						{
							std::cout << "public";
							break;
						}

						/**********HCMUS********/
						if (coord.X < 40 && coord.Y < 10)
							goto home;
					}
					break;
				}
			}
			break;
		}
		
		/********COURSE**********/
		else if (coord.X > 155 && coord.Y < 10) //course
		{
		system("cls");
		hcmusfame();
		for (int i = 0; i <= 10; i++)
		{
			Gotoxy(98, i);
			std::cout << char(219);
			Gotoxy(155, i);
			std::cout << char(219);
		}
		Gotoxy(62, 5); std::cout << "VIEW LIST OF COURSE";
		Gotoxy(115, 5); std::cout << "UPDATE COURSE INFORMATION";
		Gotoxy(180, 5);  std::cout << "DELETE COURSE";
		while (1)
		{
			coord = GetCursorClick();
			/********HCMUS********/
			if (coord.Y < 10 && coord.X < 40)
				goto home;

			/*********VIEW LIST OF COURSE********/
			if (coord.X > 40 && coord.X < 98 && coord.Y < 10)
			{
				system("cls");
				hcmusfame();
				for (int i = 0; i <= 10; i++)
				{
					Gotoxy(98, i);
					std::cout << char(219);
					Gotoxy(155, i);
					std::cout << char(219);
				}
				Gotoxy(66, 5); std::cout << "IMPORT";
				Gotoxy(124, 5); std::cout << "EXPORT";
				Gotoxy(178, 5);  std::cout << "VIEW COURSE SCORE";
				while (1)
				{
					coord = GetCursorClick();
					/********HCMUS********/
					if (coord.Y < 10 && coord.X < 40)
						goto home;

					/********IMPORT********/
					if (coord.X > 40 && coord.X < 98 && coord.Y < 10)
					{
						std::cout << "import";
						break;
					}

					/*********EXPORT********/
					else if (coord.X > 98 && coord.X < 155 && coord.Y < 10)
					{
						std::cout << "export";
						break;
					}

					/************VIEW COURSE SCORE************/
					else if (coord.X > 155 && coord.Y < 10)
					{
						system("cls");
						hcmusfame();
						Gotoxy(117, 5);
						std::cout << "UPDATE SCORE BOARD";

						
						while (1)
						{
							coord = GetCursorClick();
							/********UPDATE SCORE BOARD******/
							if (coord.X > 41 && coord.Y < 10)
							{
								std::cout << "UPDATE";
								break;
							}

							/**********HCMUS********/
							if (coord.X < 40 && coord.Y < 10)
								goto home;
						}
						break;
					}
				}
				break;
			}

			/*********UPDATE COURSE INFORMATION********/
			else if (coord.X > 98 && coord.X < 155 && coord.Y < 10)
			{
				std::cout << "update";
				break;
			}

			/*************DELETE COURSE***********/
			else if (coord.X > 155 && coord.Y < 10)
			{
				std::cout << "deleted";
				break;
			}
		}
			break;
		}
	}
}
void home_student() // vẽ giao diện sau khi login thành công
{
	int y = 10;
	for (int i = 0; i <= 210; i++)
	{
		Gotoxy(i, y);
		std::cout << char(220);
	}
}
void ShowStudentInfo(std::string name, std::string pass)
{
	int x = 100, y = 10;
	std::ifstream file(pathStudentAccounts, std::ios::in);
	if (file.is_open())
	{
		std::string check;
		std::vector<std::string> line;

		while (!file.eof())
		{
			std::getline(file, check);

			line = split(check, ",");
			
			if (name == line[1])
			{
				Gotoxy(x, y); std::cout << "FULL NAME: " << line[2] << " " << line[3] << std::endl;
				Gotoxy(x, y+1); std::cout << "STUDENT ID:  " << line[1] << std::endl;
				Gotoxy(x, y+2); std::cout << "DAY OF BIRTH: " << line[5] << std::endl;
				Gotoxy(x, y+3); std::cout << "GENDER: " << line[4] << std::endl;
				Gotoxy(x, y+4); std::cout << "SOCAIL ID: " << line[6] << std::endl;
			}
		}
		file.close();
	}
	
}