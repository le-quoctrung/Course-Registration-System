#include "display.h"
#include"Console.h"
#include"file.h"
#include"Login_System.h"
#include"Tokenizer.h"

void loginDisplay()
{
	for (int i = 0; i < 6; i++)
	{
		Gotoxy(i, 3);
		std::cout << char(223);
	}
	for (int i = 0; i < 3; i++)
	{
		Gotoxy(5, i);
		std::cout << char(219);
	}
	Gotoxy(2, 1); std::cout << "X";
	/***********/
	Gotoxy(150, 14); std::cout << "USER NAME";
	Gotoxy(150, 19); std::cout << "PASSWORD";
	for (int i = 150; i < 190; i++)
	{
		Gotoxy(i, 15); 
		std::cout << char(205);
		Gotoxy(i, 17);
		std::cout << char(205);
		Gotoxy(i, 20);
		std::cout << char(205);
		Gotoxy(i, 22);
		std::cout << char(205);
	}
	/*for (int i = 16; i < 18; i++)
	{
		Gotoxy(150, i);
		std::cout << char(219);
		Gotoxy(189, i);
		std::cout << char(219);
	}
	for (int i = 21; i < 23; i++)
	{
		Gotoxy(150, i);
		std::cout << char(219);
		Gotoxy(189, i);
		std::cout << char(219);
	}*/
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
	Gotoxy(x + 28, y + 27); std::cout << "LOG IN";
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
	for (int i = x1 + 22; i <= x1 + 32; i++)
	{
		Gotoxy(i, y1 + 13);
		std::cout << char(223);
	}

	for (int i = x1 + 22; i <= x1 + 32; i++)
	{
		Gotoxy(i, y1 + 20);
		std::cout << char(219);
	}
	for (int j = x1 + 20; j <= x1 + 21; j++)
	{
		for (int i = y1 + 13; i < y1 + 21; i++)
		{
			Gotoxy(j, i);
			std::cout << char(219);
		}
	}
	/*mu*/
	for (int i = y1 + 13; i <= y1 + 20; i++)
	{
		Gotoxy(x1 + 37, i);
		std::cout << char(219);
		Gotoxy(x1 + 38, i);
		std::cout << char(219);
		
		Gotoxy(x1 + 57, i);
		std::cout << char(219);
		Gotoxy(x1 + 58, i);
		std::cout << char(219);

		Gotoxy(x1 + 63, i);
		std::cout << char(219);
		Gotoxy(x1 + 64, i);
		std::cout << char(219);

		Gotoxy(x1 + 78, i);
		std::cout << char(219);
		Gotoxy(x1 + 79, i);
		std::cout << char(219);
	}
	//Gotoxy(x1 + 39, y1 + 12); std::cout << "123456789012345678";

	for (int i = x1 + 38 + 8; i < x1 + 38 + 12; i++)
	{
		Gotoxy(i, y1 + 16);
		std::cout << char(219);
	}
	for (int i = x1 + 38 + 5; i < x1 + 38 + 8; i++)
	{
		Gotoxy(i, y1 + 15);
		std::cout << char(219);
	}
	for (int i = x1 + 38 + 12; i < x1 + 38 + 15; i++)
	{
		Gotoxy(i, y1 + 15);
		std::cout << char(219);
	}
	for (int i = x1 + 38 + 15; i < x1 + 38 + 17; i++)
	{
		Gotoxy(i, y1 + 14);
		std::cout << char(219);
	}
	for (int i = x1 + 38 + 17; i < x1 + 38 + 19; i++)
	{
		Gotoxy(i, y1 + 13);
		std::cout << char(219);
	}
	for (int i = x1 + 38 + 1; i < x1 + 38 + 3; i++)
	{
		Gotoxy(i, y1 + 13);
		std::cout << char(219);
	}
	for (int i = x1 + 38 + 3; i < x1 + 38 + 5; i++)
	{
		Gotoxy(i, y1 + 14);
		std::cout << char(219);
	}
	for (int i = x1 + 65; i < x1 + 78; i++)
	{
		Gotoxy(i, y1 + 20);
		std::cout << char(220);
	}
	/*s*/
	for (int i = x1 + 83; i < 106; i++)
	{
		Gotoxy(i, y1 + 13);
		std::cout << char(223);
		Gotoxy(i, y1 + 20);
		std::cout << char(220);
		Gotoxy(i, y1 + 16);
		std::cout << char(220);
	}
	for (int i = y1 + 13; i < y1 + 17; i++)
	{
		Gotoxy(x1 + 83, i);
		std::cout << char(219);
		Gotoxy(x1 + 84, i);
		std::cout << char(219);
	}
	for (int i = y1 + 17; i < y1 + 21; i++)
	{
		Gotoxy(105, i);
		std::cout << char(219);
		Gotoxy(104, i);
		std::cout << char(219);
	}
	
	/*USER LOGIN*/

}
void hcmusfame()
{
	for (int i = 0; i <= 210; i++)
	{
		Gotoxy(i, 10);
		std::cout << char(220);
	}
	for (int i = 0; i < 40; i++)
	{
		Gotoxy(i, 3);
		std::cout << char(223);
	}
	for (int i = 0; i <= 10; i++)
	{
		Gotoxy(40, i);
		std::cout << char(219);
		Gotoxy(41, i);
		std::cout << char(219);
		Gotoxy(210, i);
		std::cout << char(219);
	}
	for (int i = 0; i < 3; i++)
	{
		Gotoxy(5, i);
		std::cout << char(219);
		Gotoxy(23, i);
		std::cout << char(219);
	}
	Gotoxy(17, 7); std::cout << "HCMUS";
	Gotoxy(2, 1); std::cout << "X";
	Gotoxy(11, 1); std::cout << "LOG OUT";
	Gotoxy(30, 1); std::cout << "BACK";
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
		if (coord.Y < 3 && coord.X < 5)
		{
			Gotoxy(0, 50);
			exit(0);
		}
			
		if (coord.Y < 3 && coord.X < 23 && coord.X >5)
		{
			system("cls");
			loginDisplay();
			login();
		}
	
		/********YEAR********/
		if (coord.X > 40 && coord.X < 98 && coord.Y < 10) 
		{
		year:

			system("cls");
			hcmusfame();
			for (int i = 0; i <= 10; i++)
			{
				Gotoxy(127, i);
				std::cout << char(219);
			}
			Gotoxy(75, 5); std::cout << "CREATE YEAR";
			Gotoxy(165, 5); std::cout << "SEMESTER";
			/************************************/
			while (1) // remember to break out of while loop
			{
				coord = GetCursorClick();
				if (coord.Y < 3 && coord.X < 5)
				{
					Gotoxy(0, 50);
					exit(0);
				}
				if (coord.Y < 3 && coord.X < 23 && coord.X >5)
				{
					system("cls");
					loginDisplay();
					login();
				}
				/********HCMUS********/
				if ((coord.Y < 3 && coord.X < 40 && coord.X > 23) ||(coord.Y < 10 && coord.X < 40 && coord.Y >3))
				{
					goto home;
				}
				/*******CREATE YEAR******/
				if (coord.Y < 10 && coord.X > 41 && coord.X < 127) 
				{
					//create year functions here
					system("cls");
					hcmusfame();
					Gotoxy(120, 5); std::cout << "CREATE YEAR";
					Gotoxy(100, 29); std::cout << "START YEAR: ";
					Gotoxy(100, 32); std::cout << "NOTE: END YEAR WILL BE THE NEXT YEAR OF THE FIRST YEAR";
					for (int i = 122; i < 138; i++)
					{
						Gotoxy(i, 28); 
						std::cout << char(205);
						Gotoxy(i, 30);
						std::cout << char(205);
					}
					Gotoxy(123, 29);
					short startYear;
					std::cin >> startYear;
					while (1)
					{
						coord = GetCursorClick();
						if (coord.Y < 3 && coord.X < 5)
						{
							Gotoxy(0, 50);
							exit(0);
						}
						if (coord.Y < 3 && coord.X < 23 && coord.X >5)
						{
							system("cls");
							loginDisplay();
							login();
						}
						if (coord.X < 40 && coord.Y < 10 && coord.Y > 3)
							goto home;
						if (coord.X < 40 && coord.X > 23 && coord.Y < 3)
							goto year;
						if (coord.X > 40 && coord.Y < 10)
						{
							// create year function here 
							Gotoxy(100, 36); std::cout << "YEAR " << startYear <<" - "<<startYear +1<<" HAS BEEN CREATED";
							Sleep(1000);
							goto year;
						}
					}
					goto year;
				}
				
				/********SEMESTER********/
				else if (coord.X > 127 && coord.Y < 10) 
				{
				sem:

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
					Gotoxy(111, 5); std::cout << "CREATE COURSE REGISTATION SESSION";
					Gotoxy(167, 5);  std::cout << "CREATE AND ADD COURSE TO SEMESTER";
				
					while (1)
					{
						coord = GetCursorClick();
						if (coord.Y < 3 && coord.X < 5)
						{
							Gotoxy(0, 50);
							exit(0);
						}
						if (coord.Y < 3 && coord.X < 23 && coord.X >5)
						{
							system("cls");
							loginDisplay();
							login();
						}
						if (coord.Y < 3 && coord.X < 40 && coord.X > 23)
						{
							goto year;
						}
						
						/********HCMUS********/
						if (coord.Y < 10 && coord.X < 40 && coord.Y >3)
							goto home;

						/********CREATE SEMESTER********/
						if (coord.X > 40 && coord.X < 98 && coord.Y < 10)
						{
							system("cls");
							hcmusfame();
							Gotoxy(120, 5); std::cout << "CREATE SEM";
					
							Gotoxy(100, 29);
							std::cout << "SEMESTER (1 TO 3): ";
							for (int i = 132; i < 140; i++)
							{
								Gotoxy(i, 28);
								std::cout << char(205);
								Gotoxy(i, 30);
								std::cout << char(205);
							}
							Gotoxy(100, 33);
							std::cout << "YEAR THAT SEMESTER BELONG TO:  ";
							for (int i = 132; i < 140; i++)
							{
								Gotoxy(i, 32);
								std::cout << char(205);
								Gotoxy(i, 34);
								std::cout << char(205);
							}
							Gotoxy(134, 29);
							short sem;
							std::cin >> sem;
							while (sem > 3 || sem < 1)
							{
								Gotoxy(123, 27);
								std::cout << "ONLY SEMESTER 1 TO 3 IS ALLOWED";
								Sleep(1500);
								Gotoxy(123, 27);
								std::cout << "                               ";
								Gotoxy(134, 29);
								std::cout << "        ";
								Gotoxy(134, 29);
								std::cin >> sem;
							}
							Gotoxy(134, 33);
							short year;
							std::cin >> year;
							
							while (1)
							{
								coord = GetCursorClick();
								if (coord.Y < 3 && coord.X < 5)
								{
									Gotoxy(0, 50);
									exit(0);
								}
								if (coord.Y < 3 && coord.X < 23 && coord.X >5)
								{
									system("cls");
									loginDisplay();
									login();
								}
								if (coord.X < 40 && coord.Y < 10 && coord.Y > 3)
									goto home;
								if (coord.X < 40 && coord.X > 23 && coord.Y < 3)
									goto year;
								if (coord.X > 40 && coord.Y < 10)
								{
									// create year function here 
									std::cout << sem << " HAVE BEEN CREATED AND ADDED TO YEAR " << year;;
									goto sem;
								}
							}
							
							
						}

						/*********CREATE COURSE REGISTATION SESSION********/
						else if (coord.X > 98 && coord.X < 155 && coord.Y < 10)
						{
							system("cls");
							hcmusfame();
							Gotoxy(105, 5); std::cout << "CREATE COURSE REGISTATION SESSION";
							
							date start, end;
							Gotoxy(65, 20);
							std::cout << "START:   ";
							Gotoxy(80, 20); std::cout << "DAY:";
							Gotoxy(90, 20); std::cout << "MONTH:";
							Gotoxy(105, 20); std::cout << "YEAR:";
							
							Gotoxy(65, 23);
							std::cout << "END: ";
							Gotoxy(80, 23); std::cout << "DAY:";
							Gotoxy(90, 23); std::cout << "MONTH:";
							Gotoxy(105, 23); std::cout << "YEAR:";
							
						checkvalid:

							HienTroChuot();
							Gotoxy(86, 20); std::cin >> start.day;
							Gotoxy(98, 20); std::cin >> start.month;
							Gotoxy(111, 20); std::cin >> start.year;
							Gotoxy(86, 23); std::cin >> end.day;
							Gotoxy(98, 23); std::cin >> end.month;
							Gotoxy(111, 23); std::cin >> end.year;
							AnTroChuot();
							if ((!CheckValid(start) || !CheckValid(end)) || CmpDate(start,end))
							{
								Gotoxy(85, 27);
								std::cout << "INVAIL DATE";
								Gotoxy(86, 20); std::cout << "   ";
								Gotoxy(98, 20); std::cout << "   ";
								Gotoxy(111, 20); std::cout << "   ";
								Gotoxy(86, 23); std::cout << "   ";
								Gotoxy(98, 23); std::cout << "     ";
								Gotoxy(111, 23); std::cout << "     ";
								goto checkvalid;
							}
							while (1)
							{
								coord = GetCursorClick();
								if (coord.Y < 3 && coord.X < 5)
								{
									Gotoxy(0, 50);
									exit(0);
								}
								if (coord.Y < 3 && coord.X < 23 && coord.X >5)
								{
									system("cls");
									loginDisplay();
									login();
								}
								if (coord.X < 40 && coord.Y < 10 && coord.Y > 3)
									goto home;
								if (coord.X < 40 && coord.X > 23 && coord.Y < 3)
									goto year;
								if (coord.X > 40 && coord.Y < 10)
								{
				// create course registation session function here (use date start and end to control)				
								goto sem;
								}
							}
						}

						/************ADD COURSE TO SEMESTER************/
						else if (coord.X > 155 && coord.Y < 10)
						{
							system("cls");
							hcmusfame();
							Gotoxy(110, 5); std::cout << "ADD COURSE TO SEMESTER";

				//show list course here

							Gotoxy(80, 20);
							std::cout << "COURSE NAME:  ";
							for (int i = 100; i < 120; i++)
							{
								Gotoxy(i, 19);
								std::cout << char(205);
								Gotoxy(i, 21);
								std::cout << char(205);
							}
							Gotoxy(80, 24);
							std::cout << "SEMESTER (1 TO 3): ";
							for (int i = 100; i < 110; i++)
							{
								Gotoxy(i, 23);
								std::cout << char(205);
								Gotoxy(i, 25);
								std::cout << char(205);
							}
							Gotoxy(102, 20);
						
							std::string courseName;
							controlTyping(courseName, 20);
							
							Gotoxy(102, 24);
							HienTroChuot();
							int sem;
							std::cin >> sem;
							AnTroChuot();
							while (sem > 3 || sem < 1)
							{
								Gotoxy(103, 27);
								std::cout << "ONLY SEMESTER 1 TO 3 IS ALLOWED";
								Sleep(1500);
								Gotoxy(103, 26);
								std::cout << "                               ";
								Gotoxy(102, 24);
								std::cout << "        ";
								Gotoxy(102, 24);
								std::cin >> sem;
							}
							while (1)
							{
								coord = GetCursorClick();
								if (coord.Y < 3 && coord.X < 5)
								{
									Gotoxy(0, 50);
									exit(0);
								}
								if (coord.Y < 3 && coord.X < 23 && coord.X >5)
								{
									system("cls");
									loginDisplay();
									login();
								}
								if (coord.X < 40 && coord.Y < 10 && coord.Y > 3)
									goto home;
								if (coord.X < 40 && coord.X > 23 && coord.Y < 3)
									goto year;
								if (coord.X > 40 && coord.Y < 10)
								{
				// add course function here
									
									goto sem;
								}
							}
							
						}
					}			
					//break;
				}
				
				
			}	
			break;
		}
		
		/**********CLASS********/
		else if (coord.X > 98 && coord.X < 155 && coord.Y < 10) //class
		{
		Class:

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
				if (coord.Y < 3 && coord.X < 5)
				{
					Gotoxy(0, 50);
					exit(0);
				}
				if (coord.Y < 3 && coord.X < 23 && coord.X >5)
				{
					system("cls");
					loginDisplay();
					login();
				}
				/********HCMUS********/
				if ((coord.Y < 3 && coord.X < 40 && coord.X > 23) ||(coord.Y < 10 && coord.X < 40 && coord.Y >3))
				{
					goto home;
				}
			

				/**********CREATE CLASS*******/
				if (coord.X > 40 && coord.X < 98 && coord.Y < 10)
				{
				

					system("cls");
					hcmusfame();
					Gotoxy(123, 5); std::cout << "IMPORT FILE";
					Gotoxy(100, 25); std::cout << "CLASS NAME:";
					Gotoxy(100, 30); std::cout << "FILE NAME:";
					for (int i = 113; i < 130; i++)
					{
						Gotoxy(i, 24);
						std::cout << char(205);
						Gotoxy(i, 26);
						std::cout << char(205);
						Gotoxy(i, 29);
						std::cout << char(205);
						Gotoxy(i, 31);
						std::cout << char(205);
					}
				create:
					Gotoxy(114, 25); std::cout << "...           ";
					Gotoxy(114, 30); std::cout << "...           ";
					while (1)
					{
						coord = GetCursorClick();
						if (coord.Y < 3 && coord.X < 5)
						{
							Gotoxy(0, 50);
							exit(0);
						}
						if (coord.Y < 3 && coord.X < 23 && coord.X >5)
						{
							system("cls");
							loginDisplay();
							login();
						}
						if (coord.Y < 3 && coord.X < 40 && coord.X > 23)
							goto Class;
						if (coord.X < 40 && coord.Y < 10 && coord.Y >3)
							goto home;
						if(coord.X < 130 && coord.X >113 && coord.Y < 27 && coord.Y >23)
						{
							std::string fileName, className;

							Gotoxy(114, 25); std::cout << "    ";
							Gotoxy(114, 25);
							controlTyping(className, 10);

							Gotoxy(114, 30); std::cout << "    ";
							Gotoxy(114, 30);
							controlTyping(fileName, 20);
							while (1)
							{
								coord = GetCursorClick();
								if (coord.Y < 3 && coord.X < 5)
								{
									Gotoxy(0, 50);
									exit(0);
								}
								if (coord.Y < 3 && coord.X < 23 && coord.X >5)
								{
									system("cls");
									loginDisplay();
									login();
								}
								if (coord.Y < 3 && coord.X < 40 && coord.X > 23)
									goto Class;
								if (coord.X < 40 && coord.Y < 10 && coord.Y >3)
									goto home;
								if (coord.X > 40 && coord.Y < 10)
								{
									Gotoxy(104, 34);
									// import file function here 
									std::cout << "CREATED SUCCESSFULLY!";
									Gotoxy(90, 36);
									std::cout << fileName << ".cvs IMPORTED TO THE CLASS " << className;
									//std::cout << "                                                         ";
									Sleep(2500);
									goto Class;
								}
							}
						}
						if (coord.X > 40 && coord.Y < 10)
						{
							Gotoxy(104, 23);
							// import file function here 
							std::cout << "PLEASE ENTER CLASS NAME AND FILE NAME";
							Sleep(2000);
							Gotoxy(104, 28);
							std::cout << "                      ";
							goto create;
						}
					}
				}

				/*********ADD STUDENT TO CLASS********/
				else if (coord.X > 98 && coord.X < 155 && coord.Y < 10)
				{
					std::cout << "added";
					goto Class;
				}

				/*************VIEW SCORE************/
				else if (coord.X > 155 && coord.Y < 10)
				{
				scoreboard:
					system("cls");
					hcmusfame();
					Gotoxy(117, 5);
					std::cout << "PUBLIC THIS SCORE BOARD";

					// view scoreboard function here
			
					while (1)
					{
						coord = GetCursorClick();
						if (coord.Y < 3 && coord.X < 5)
						{
							Gotoxy(0, 50);
							exit(0);
						}
						if (coord.Y < 3 && coord.X < 23 && coord.X >5)
						{
							system("cls");
							loginDisplay();
							login();
						}
						if (coord.Y < 3 && coord.X < 40 && coord.X > 23)
						{
							goto Class;
						}
						/********PUBLIC SCORE BOARD******/
						if (coord.X > 41 && coord.Y < 10)
						{
							std::cout << "public";
							goto scoreboard;
						}

						/**********HCMUS********/
						if (coord.X < 40 && coord.Y < 10 && coord.Y >3)
							goto home;
					}
					//break;
				}
			}
			//break;
		}
		
		/********COURSE**********/
		else if (coord.X > 155 && coord.Y < 10) //course
		{
	course:

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
			if (coord.Y < 3 && coord.X < 5)
			{
				Gotoxy(0, 50);
				exit(0);
			}
			if (coord.Y < 3 && coord.X < 23 && coord.X >5)
			{
				system("cls");
				loginDisplay();
				login();
			}
		
			/********HCMUS********/
			if ((coord.Y < 10 && coord.X < 40 && coord.Y >3) || (coord.Y < 3 && coord.X < 40 && coord.X > 23))
				goto home;

			/*********VIEW LIST OF COURSE********/
			if (coord.X > 40 && coord.X < 98 && coord.Y < 10)
			{
			viewlist:

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
					if (coord.Y < 3 && coord.X < 5)
					{
						Gotoxy(0, 50);
						exit(0);
					}
					if (coord.Y < 3 && coord.X < 23 && coord.X >5)
					{
						system("cls");
						loginDisplay();
						login();
					}
					if (coord.Y < 3 && coord.X < 40 && coord.X > 23)
					{
						goto course;
					}
					/********HCMUS********/
					if (coord.Y < 10 && coord.X < 40 && coord.Y >3)
						goto home;

					/********IMPORT********/
					if (coord.X > 40 && coord.X < 98 && coord.Y < 10)
					{
						std::cout << "import";
						goto viewlist;
					}

					/*********EXPORT********/
					else if (coord.X > 98 && coord.X < 155 && coord.Y < 10)
					{
						std::cout << "export";
						goto viewlist;
					}

					/************VIEW COURSE SCORE************/
					else if (coord.X > 155 && coord.Y < 10)
					{
					update:

						system("cls");
						hcmusfame();
						Gotoxy(117, 5);
						std::cout << "UPDATE SCORE BOARD";
					
						while (1)
						{
							coord = GetCursorClick();
							if (coord.Y < 3 && coord.X < 5)
							{
								Gotoxy(0, 50);
								exit(0);
							}
							if (coord.Y < 3 && coord.X < 23 && coord.X >5)
							{
								system("cls");
								loginDisplay();
								login();
							}
							if (coord.Y < 3 && coord.X < 40 && coord.X > 23)
							{
								goto viewlist;
							}
							/********UPDATE SCORE BOARD******/
							if (coord.X > 41 && coord.Y < 10)
							{
								std::cout << "UPDATE";
								goto update;
							}

							/**********HCMUS********/
							if (coord.X < 40 && coord.Y < 10 && coord.Y >3)
								goto home;
						}
						//break;
					}
				}
				//break;
			}

			/*********UPDATE COURSE INFORMATION********/
			else if (coord.X > 98 && coord.X < 155 && coord.Y < 10)
			{
				std::cout << "update";
				goto course;
			}

			/*************DELETE COURSE***********/
			else if (coord.X > 155 && coord.Y < 10)
			{
				std::cout << "deleted";
				goto course;
			}
		}
			//break;
		}
	}
}
void home_student(std::string name) // vẽ giao diện sau khi login thành công
{
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
	Gotoxy(62, 5); std::cout << "ENROLLED COURSE";
	Gotoxy(120, 5); std::cout << "ENROLL COURSE";
	Gotoxy(176, 5);  std::cout << "VIEW SCORE BOARD";
	ShowStudentInfo(name);
	while (1)
	{
		COORD coord = GetCursorClick();
		if (coord.Y < 3 && coord.X < 5)
		{
			Gotoxy(0, 50);
			exit(0);
		}
		if (coord.Y < 3 && coord.X < 23 && coord.X >5)
		{
			system("cls");
			loginDisplay();
			login();
		}
		/**********ENROLLED COURSE**********/
		if (coord.Y < 10 && coord.X < 98 && coord.X > 40)
		{
		enrolled:

			system("cls");
			hcmusfame();
			Gotoxy(123, 5); std::cout << "REMOVE COURSE";
			while (1)
			{
				coord = GetCursorClick();
				if (coord.Y < 3 && coord.X < 5)
				{
					Gotoxy(0, 50);
					exit(0);
				}
				if (coord.Y < 3 && coord.X < 23 && coord.X >5)
				{
					system("cls");
					loginDisplay();
					login();
				}
				if ((coord.Y < 3 && coord.X < 40 && coord.X > 23) || (coord.Y < 10 && coord.X < 40 && coord.Y >3))
				{
					goto home;
				}
				if (coord.Y < 10 && coord.X>40)
				{
					std::cout << "remove";
					//do sth
					goto enrolled;
				}
			}
		}
		/**********ENROLL COURSE**********/
		else if (coord.Y < 10 && coord.X>98 && coord.X < 155)
		{
		enroll:

			system("cls");
			hcmusfame();
			Gotoxy(123, 5); std::cout << "ENROLL COURSE";
			while (1)
			{
				coord = GetCursorClick();
				if (coord.Y < 3 && coord.X < 5)
				{
					Gotoxy(0, 50);
					exit(0);
				}
				if (coord.Y < 3 && coord.X < 23 && coord.X >5)
				{
					system("cls");
					loginDisplay();
					login();
				}
				if ((coord.Y < 3 && coord.X < 40 && coord.X > 23) || (coord.Y < 10 && coord.X < 40 && coord.Y >3))
				{
					goto home;
				}
				if (coord.Y < 10 && coord.X>40)
				{
					std::cout << "eroll";
					//do sth
					goto enroll;
				}
			}
		}
		/*******8***VIEW SCOREBOARD***********/
		else if (coord.Y < 10 && coord.X>155)
		{
			system("cls");
			hcmusfame();
			Gotoxy(123, 5); std::cout << "SCORE BOARD";
			while (1)
			{
				coord = GetCursorClick();
				if (coord.Y < 3 && coord.X < 5)
				{
					Gotoxy(0, 50);
					exit(0);
				}
				if (coord.Y < 3 && coord.X < 23 && coord.X >5)
				{
					system("cls");
					loginDisplay();
					login();
				}
				if ((coord.Y < 3 && coord.X < 40 && coord.X > 23) || (coord.Y < 10 && coord.X < 40 && coord.Y >3))
				{
					goto home;
				}
			}
		}
	}
}
void ShowStudentInfo(std::string name)
{
	int x = 95, y = 20;
	std::ifstream file("allStudent.csv", std::ios::in);
	for (int i = 70; i <= 140; i++)
	{
		Gotoxy(i, 18);
		std::cout << char(205);
		Gotoxy(i, 38);
		std::cout << char(205);
	}
	for (int i = 19; i < 38; i++)
	{
		Gotoxy(69, i);
		std::cout << char(186);
		Gotoxy(141, i);
		std::cout << char(186);
	}
	Gotoxy(69, 18); std::cout << char(201);
	Gotoxy(69, 38); std::cout << char(200);
	Gotoxy(141, 38); std::cout << char(188);
	Gotoxy(141, 18); std::cout << char(187);
	Gotoxy(x, y); std::cout << "STUDENT INFORMATION";
	for (int i = x-1; i <= x + 19; i++)
	{
		Gotoxy(i, y + 1); std::cout << char(223);
	}
	
	if (file.is_open())
	{
		std::string check;
		std::vector<std::string> line;

		while (!file.eof())
		{
			std::getline(file, check);
			if (check == "") break;
			line = split(check, ",");
			
			if (name == line[1])
			{
				Gotoxy(x-10, y+5); std::cout <<  "FULL NAME:       " << line[2] << " " << line[3] << std::endl;
				Gotoxy(x-10, y+7); std::cout <<  "STUDENT ID:      " << line[1] << std::endl;
				Gotoxy(x-10, y+9); std::cout <<  "DAY OF BIRTH:    " << line[5] << std::endl;
				Gotoxy(x-10, y+11); std::cout << "GENDER:          " << line[4] << std::endl;
				Gotoxy(x-10, y+13); std::cout << "SOCAIL ID:       " << line[6] << std::endl;
			}
		}
		file.close();
	}
	
}