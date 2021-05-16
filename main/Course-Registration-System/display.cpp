#include "display.h"

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

void home_staff(ListYear* nYear, NodeStudent* phead)
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
	createStudent(phead);
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

	Gotoxy(0, 15); OutputListYear(nYear);

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
			Gotoxy(0,15); OutputListYear(nYear);
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
					Gotoxy(90, 29); std::cout << "START YEAR DATE (dd/mm/yyyy): ";
					Gotoxy(90, 32); std::cout << "NOTE: END YEAR DATE WILL BE 11 MONTHS AWAY FROM START YEAR DATE";
					Gotoxy(0,15); OutputListYear(nYear);
					for (int i = 122; i < 138; i++)
					{
						Gotoxy(i, 28);
						std::cout << char(205);
						Gotoxy(i, 30);
						std::cout << char(205);
					}
					Gotoxy(125, 29);
					std::cout << "...";
				
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
						if (coord.X < 138 && coord.X>122 && coord.Y < 31 && coord.Y>27)
						{
							Gotoxy(125, 29);
							std::cout << "   ";
							std::string startYearDate;
							controlTyping(startYearDate, 20);
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
									if (!CanAddYear(nYear, ParseDate(startYearDate)))
									{
										Gotoxy(100, 34); std::cout << "INVALID DATE!";
										Sleep(1000);
										goto home;
									}
									if (!AddYear(nYear, startYearDate))
									{
										Gotoxy(100, 34); std::cout << "CAN'T CREATE YEAR";
										Sleep(1000);
										goto home;
									}

									Gotoxy(100, 34); std::cout << "YEAR " << nYear->head->startYear.year << " - " << nYear->head->endYear.year << " HAS BEEN CREATED";
									WriteAll("data.bin", nYear);
									Sleep(1000);
									goto year;
								}
							}
						}
						
					}
					goto year;
				}
				
				/********SEMESTER********/
				else 
				if (coord.X > 127 && coord.Y < 10) 
				{
					if (nYear->head == nullptr) { std::cout << "NONE SCHOOL YEAR IS AVAILABLE!"; Sleep(1000); goto home; }
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
					Gotoxy(0, 15); OutputListYear(nYear);
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
							Gotoxy(0,15); OutputListYear(nYear);
							short sem;
							short yearIndex;
							std::string start, end, nsem, nyear;
							Gotoxy(100, 29);
							std::cout << "SEMESTER (1 TO 3): ";
							for (int i = 132; i < 140; i++)
							{
								Gotoxy(i, 28);
								std::cout << char(205);
								Gotoxy(i, 30);
								std::cout << char(205);
							}
							Gotoxy(134, 29); std::cout << "...";
							Gotoxy(100, 33);
							std::cout << "START DATE (dd/mm/yyyy): ";
							for (int i = 132; i < 140; i++)
							{
								Gotoxy(i, 32);
								std::cout << char(205);
								Gotoxy(i, 34);
								std::cout << char(205);
							}
							Gotoxy(134, 33); std::cout << "...";
							Gotoxy(100, 37);
							std::cout << "END DATE (dd/mm/yyyy): ";
							for (int i = 132; i < 140; i++)
							{
								Gotoxy(i, 36);
								std::cout << char(205);
								Gotoxy(i, 38);
								std::cout << char(205);
							}
							Gotoxy(134, 37); std::cout << "...";
							Gotoxy(100, 41);
							std::cout << "YEAR THAT SEMESTER BELONG TO:  ";
							for (int i = 132; i < 140; i++)
							{
								Gotoxy(i, 40);
								std::cout << char(205);
								Gotoxy(i, 42);
								std::cout << char(205);
							}
							Gotoxy(134, 41); std::cout << "...";
							
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
								if (coord.Y < 31 && coord.Y >27 && coord.X < 140 && coord.X>132)
								{
									Gotoxy(134, 29); std::cout << "   ";
									Gotoxy(134, 29); controlTyping(nsem, 20);
									Gotoxy(134, 33); std::cout << "   ";
									Gotoxy(134, 33); controlTyping(start, 20);
									Gotoxy(134, 37); std::cout << "   ";
									Gotoxy(134, 37); controlTyping(end, 20);
									Gotoxy(134, 41); std::cout << "   ";
									Gotoxy(134, 41); controlTyping(nyear, 20);
									sem = std::stoi(nsem);
									yearIndex = std::stoi(nyear);
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
											NodeYear* CurYear = getNode(nYear->head, yearIndex);
											if (CurYear == nullptr) { std::cout << "INDEX NOT FOUND!"; goto sem; }
											if (CmpDate(ParseDate(end), ParseDate(start)) == -1)
											{
												std::cout << "END DATE CAN'T BE SOONER THAN START DATE";
												Sleep(2000);
												goto sem;
											}
											else if (CmpDate(ParseDate(start), CurYear->startYear) == -1)
											{
												std::cout << "SEMESTER CAN'T BE SOONER THAN SCHOOL YEAR";
												Sleep(2000);
												goto sem;
											}
											else if (!CanAddSem(CurYear->semesters, sem, ParseDate(start), ParseDate(end)))
											{
												std::cout << "EXISTED SEMESTER OR CONFLICTED/INVALID DATE, CAN'T ADD SEMESTER!";
												Sleep(2000);
												goto sem;
											}

											AddSemester(CurYear->semesters, sem, ParseDate(start), ParseDate(end));
											std::cout << "SEMESTER " << sem << " IS ADDED TO YEAR " << CurYear->startYear.year << " - " << CurYear->endYear.year;
											WriteAll("data.bin", nYear);
											Sleep(2000);
											goto sem;
										}
									}
								}
								
							}
						}					

						/*********CREATE COURSE REGISTATION SESSION********/
						else if (coord.X > 98 && coord.X < 155 && coord.Y < 10)
						{
							system("cls");
							hcmusfame();
							Gotoxy(105, 5); std::cout << "CREATE COURSE REGISTATION SESSION";
							Gotoxy(0, 15); OutputListYear(nYear);

							date start, end;
							int yearIndex;

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
							Gotoxy(80, 30);
							std::cout << "YEAR THAT SEMESTER BELONG TO:  ";

						checkvalid:

							HienTroChuot();
							Gotoxy(86, 20); std::cin >> start.day;
							Gotoxy(98, 20); std::cin >> start.month;
							Gotoxy(111, 20); std::cin >> start.year;
							Gotoxy(86, 23); std::cin >> end.day;
							Gotoxy(98, 23); std::cin >> end.month;
							Gotoxy(111, 23); std::cin >> end.year;
							Gotoxy(111, 30); std::cin >> yearIndex;
							NodeYear* CurYear = getNode(nYear->head, yearIndex);
							if (CurYear == nullptr) { std::cout << "INDEX NOT FOUND!"; goto checkvalid; }
							AnTroChuot();

							if (!CheckValid(start) ||
								!CheckValid(end) ||
								CmpDate(end, start) <= 0 ||
								CmpDate(start, CurYear->semesters->tail->start) == -1 ||
								CmpDate(end, CurYear->semesters->tail->end) == 1)
							{
								Gotoxy(85, 27);
								std::cout << "INVALID DATE";
								Gotoxy(86, 20); std::cout << "     ";
								Gotoxy(98, 20); std::cout << "     ";
								Gotoxy(111, 20); std::cout << "        ";
								Gotoxy(86, 23); std::cout << "     ";
								Gotoxy(98, 23); std::cout << "      ";
								Gotoxy(111, 23); std::cout << "          ";
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

									std::cout << "COURSE REGISTRATION SESSION STARTED IN SEMESTER " <<CurYear->semesters->tail->type 
										<< " OF YEAR " << CurYear->startYear.year << " - " << CurYear->endYear.year;
									CopyDate(CurYear->semesters->tail->sessStart, start);
									CopyDate(CurYear->semesters->tail->sessEnd, end);
									WriteAll("data.bin", nYear);
									Sleep(2000);
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
							Gotoxy(0, 15); OutputListYear(nYear);

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
		if (nYear->head == nullptr) { Gotoxy(100, 34); std::cout << "NONE SCHOOL YEAR IS AVAILABLE!"; Sleep(1000); goto home; }
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
			Gotoxy(0, 15); OutputListYear(nYear);
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
					std::string fileName, type, no;
					std::stringstream className;

					system("cls");
					hcmusfame();
					Gotoxy(123, 5); std::cout << "IMPORT FILE";
					Gotoxy(100, 25); std::cout << "CLASS NO:";
					Gotoxy(100, 30); std::cout << "CLASS TYPE:";
					Gotoxy(100, 35); std::cout << "FILE NAME:";
					Gotoxy(0, 15); OutputListYear(nYear);
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
						Gotoxy(i, 34);
						std::cout << char(205);
						Gotoxy(i, 36);
						std::cout << char(205);
					}
				create:
					Gotoxy(114, 25); std::cout << "...           ";
					Gotoxy(114, 30); std::cout << "...           ";
					Gotoxy(114, 35); std::cout << "...           ";
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
						if (coord.X < 130 && coord.X >113 && coord.Y < 27 && coord.Y >23)
						{

							Gotoxy(114, 25); std::cout << "    ";
							Gotoxy(114, 25);
							controlTyping(no, 5);

							Gotoxy(114, 30); std::cout << "    ";
							Gotoxy(114, 30);
							controlTyping(type, 10);

							Gotoxy(114, 35); std::cout << "    ";
							Gotoxy(114, 35);
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
									Gotoxy(104, 40);
									className << std::to_string(nYear->tail->startYear.year).substr(2, 2) << type;
									// import file function here 
									std::ifstream check(fileName);
									if (!check)
									{
										std::cout << "CAN'T OPEN FILE";
										Sleep(2000);
										goto Class;
									}

									if (!AddClass(nYear->tail->classes, std::stoi(no), className.str()))
									{
										std::cout << "CAN'T ADD CLASS";
										Sleep(2000);
										goto Class;
									}

									std::cout << "CREATED SUCCESSFULLY!";
									Gotoxy(90, 45);
									ReadListStudentToClass(fileName, nYear->tail->classes->tail);
									std::cout << fileName << " WAS IMPORTED TO THE CLASS " << className.str() << no;
									//std::cout << "                                                         ";
									OutputClass(nYear->tail->classes->tail);
									Sleep(3500);
									goto Class;
								}
							}
						}
						//what's this for
						//if (coord.X > 40 && coord.Y < 10)
						//{
						//	Gotoxy(104, 23);
						//	// import file function here 
						//	std::cout << "PLEASE ENTER CLASS NAME AND FILE NAME";
						//	Sleep(2000);
						//	Gotoxy(104, 28);
						//	std::cout << "                      ";
						//	goto create;
						//}
					}
				}

				/*********ADD STUDENT TO CLASS********/
				else if (coord.X > 98 && coord.X < 155 && coord.Y < 10)
				{
					if (nYear->tail->classes->head == nullptr) { std::cout << "NONE CLASS IS AVAILABLE!"; Sleep(1000); goto Class; }
					std::cout << "added";
					goto Class;
				}

				/*************VIEW SCORE************/
				else if (coord.X > 155 && coord.Y < 10)
				{
					if (nYear->tail->classes->head == nullptr) { std::cout << "NONE CLASS IS AVAILABLE!"; Sleep(1000); goto Class; }
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
		if (nYear->head == nullptr) { Gotoxy(100, 34); std::cout << "NONE SCHOOL YEAR IS AVAILABLE!"; Sleep(1000); goto home; }
	
		std::string yearIndex;
	precourse:

		Gotoxy(100, 29); std::cout << "YEAR INDEX:";
		for (int i = 122; i < 128; i++)
		{
			Gotoxy(i, 28);
			std::cout << char(205);
			Gotoxy(i, 30);
			std::cout << char(205);
		}
		Gotoxy(122, 29);
		controlTyping(yearIndex, 2);
		NodeYear* CurYear = getNode(nYear->head, std::stoi(yearIndex));
		if (CurYear == nullptr) { std::cout << "INDEX NOT FOUND!"; goto precourse; }
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
		Gotoxy(120, 5); std::cout << "CREATE COURSE";
		Gotoxy(177, 5);  std::cout << "MODIFY COURSE";
		Gotoxy(0, 15); OutputListYear(nYear);
		
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
				Gotoxy(0, 15); OutputHeaderListCourse(CurYear->semesters->tail->Courses);

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

			/*********CREATE COURSE INFORMATION********/
			else if (coord.X > 98 && coord.X < 155 && coord.Y < 10)
			{
			system("cls");
			hcmusfame();
			Gotoxy(123, 5); std::cout << "IMPORT FILE";
			Gotoxy(0, 15); OutputSem(CurYear->semesters->tail);
			Gotoxy(100, 30); std::cout << "FILE NAME:";
			for (int i = 113; i < 130; i++)
			{
				
				Gotoxy(i, 29);
				std::cout << char(205);
				Gotoxy(i, 31);
				std::cout << char(205);
			}
		createcourse:
		
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
					goto course;
				if (coord.X < 40 && coord.Y < 10 && coord.Y >3)
					goto home;
				if (coord.X < 130 && coord.X >113 && coord.Y < 32 && coord.Y > 28)
				{
					std::string fileName;

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
							std::ifstream check(fileName);
							if (!check)
							{
								std::cout << "CAN'T OPEN FILE";
								Sleep(2000);
								goto course;
							}

							ReadListToCourse(fileName,CurYear->semesters->tail->Courses);						
							std::cout << "CREATED SUCCESSFULLY!";
							Gotoxy(0, 40);
							OutputSem(CurYear->semesters->tail);															
							Sleep(2500);
							goto course;
						}
					}
				}
				if (coord.X > 40 && coord.Y < 10)
				{
					Gotoxy(104, 23);
					// import file function here 
					std::cout << "PLEASE IMPORT FILE TO CREATE COURSE";
					Sleep(2000);
					Gotoxy(104, 28);
					std::cout << "                                       ";
					goto createcourse;
				}
			}
			}

			/*************UPDATE AND DELETE COURSE***********/
			else if (coord.X > 155 && coord.Y < 10)
			{
				system("cls");
				hcmusfame();
				for (int i = 0; i <= 10; i++)
				{
					Gotoxy(127, i);
					std::cout << char(219);
				}
				Gotoxy(75, 5); std::cout << "UPDATE COURSE INFORMATION";
				Gotoxy(165, 5); std::cout << "DELETE COURSE";
				std::string courseID, teacherName;
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
					/*********DELETE************/
					if (coord.X > 127 && coord.Y < 10)
					{
					updatecourse:

						Gotoxy(30, 22); std::cout << "COURSE INFORMATION: ";
						Gotoxy(30, 25); std::cout << "COURSE ID:";
						Gotoxy(30, 30); std::cout << "TEACHER:";
						Gotoxy(0, 50); OutputHeaderListCourse(CurYear->semesters->tail->Courses);
						for (int i = 43; i < 60; i++)
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
						Gotoxy(44, 25); std::cout << "...           ";
						Gotoxy(44, 30); std::cout << "...           ";
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
								goto course;
							if (coord.X < 40 && coord.Y < 10 && coord.Y >3)
								goto home;
							if (coord.X < 60 && coord.X >43 && coord.Y < 27 && coord.Y >23)
							{
								std::string courseID, teacherName;

								Gotoxy(44, 25); std::cout << "    ";
								Gotoxy(44, 25);
								controlTyping(courseID, 10);

								Gotoxy(44, 30); std::cout << "    ";
								Gotoxy(44, 30);
								controlTyping(teacherName, 20);

								NodeCourse* find = FindCourse(CurYear->semesters->tail->Courses, courseID, teacherName);
								if (find == nullptr)
								{
									Gotoxy(25, 35);		
									std::cout << "CAN'T FIND COURSE WITH THE GIVEN INFOMATION!";
									Sleep(2000);
									goto updatecourse;
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
									if (coord.Y < 3 && coord.X < 40 && coord.X > 23)
										goto course;
									if (coord.X < 40 && coord.Y < 10 && coord.Y >3)
										goto home;
									if (coord.X > 127 && coord.Y < 10)
									{
										Gotoxy(104, 34);
										DeleteCourse(CurYear->semesters->tail->Courses, courseID, teacherName);
										std::cout << "DELETE SUCCESSFULLY!";
										Sleep(2500);
										goto course;
									}
								}
							}
							
						}
					}
					/*********UPDATE************/
					if (coord.Y < 10 && coord.X > 41 && coord.X < 127)
					{
						Gotoxy(30, 22); std::cout << "CURRENT COURSE INFORMATION (for searching): ";
						Gotoxy(30, 25); std::cout << "COURSE ID:";
						Gotoxy(30, 30); std::cout << "TEACHER:";

						Gotoxy(110, 22); std::cout << "NEW COURSE INFORMATION: ";
						Gotoxy(110, 27); std::cout << "COURSE ID:";
						Gotoxy(110, 31); std::cout << "COURSE NAME:";
						Gotoxy(110, 35); std::cout << "TEACHER NAME:";
						Gotoxy(110, 39); std::cout << "NUMBER OF CREDITS:";
						Gotoxy(110, 43); std::cout << "DAY OF WEEK       1:        2:";
						Gotoxy(110, 47); std::cout << "SESSION OF DAY    1:        2:";
						Gotoxy(110, 51); std::cout << "MAX: ";

						for (int i = 43; i < 60; i++)
						{
							std::cout << char(205);
							Gotoxy(i, 24);
							std::cout << char(205);
							Gotoxy(i, 26);
							std::cout << char(205);
							Gotoxy(i, 29);
							std::cout << char(205);
							Gotoxy(i, 31);
							std::cout << char(205);
						}

						Gotoxy(44, 25); std::cout << "...           ";
						Gotoxy(44, 30); std::cout << "...           ";
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
								goto course;
							if (coord.X < 40 && coord.Y < 10 && coord.Y >3)
								goto home;
							if (coord.X < 60 && coord.X >43 && coord.Y < 27 && coord.Y >23)
							{
								std::string courseID, teacherName;
								std::string nCourseID, nTeacherName, nCourseName, credit, max, DOW1, DOW2, Session1, Session2;
								Gotoxy(44, 25); std::cout << "    ";
								Gotoxy(44, 25);
								controlTyping(courseID, 10);

								Gotoxy(44, 30); std::cout << "    ";
								Gotoxy(44, 30);
								controlTyping(teacherName, 30);

								Gotoxy(0, 35);
								NodeCourse* find = FindCourse(CurYear->semesters->tail->Courses, courseID, teacherName);
								if (find == nullptr)
								{
									Gotoxy(25, 35);
									std::cout << "CAN'T FIND COURSE WITH THE GIVEN INFOMATION!";
									Sleep(2000);
									std::cout << "                                            ";
									goto updatecourse;
								}
								OutputCourse(find);

								Gotoxy(130, 27);
								controlTyping(nCourseID, 30);
								Gotoxy(130, 31);
								controlTyping(nCourseName, 30);
								Gotoxy(130, 35);
								controlTyping(nTeacherName, 30);
								Gotoxy(130, 39);
								controlTyping(credit, 30);
								Gotoxy(130, 43);
								controlTyping(DOW1, 30);
								Gotoxy(140, 43);
								controlTyping(DOW2, 30);
								Gotoxy(130, 47);
								controlTyping(Session1, 30);
								Gotoxy(140, 47);
								controlTyping(Session2, 30);
								Gotoxy(130, 51);
								controlTyping(max, 30);

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
										goto course;
									if (coord.X < 40 && coord.Y < 10 && coord.Y >3)
										goto home;
									if (coord.X > 40 && coord.X < 127 && coord.Y < 10)
									{
										Gotoxy(104, 34);
										UpdateCourse(find, nCourseID, nCourseName, nTeacherName, std::stoi(credit), std::stoi(max), DOW1, Session1, DOW2, Session2);
										std::cout << "UPDATE SUCCESSFULLY!";
										Gotoxy(0, 50);
										OutputCourse(FindCourse(CurYear->semesters->tail->Courses, nCourseID, nTeacherName));
										Sleep(2500);
										goto course;
									}
								}
							}

						}
					}
				}
			}
		}
			//break;
		}
	}
}
void home_student(ListYear* nYear, std::string name) // vẽ giao diện sau khi login thành công
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
			Gotoxy(50, 14); std::wcout << "COURSE-NUMBER YOU WANT TO REMOVE: ";
		//show list course here
			for (int i = 90; i < 100; i++)
			{
				Gotoxy(i, 13);
				std::cout << char(205);
				Gotoxy(i, 15);
				std::cout << char(205);
			}
			Gotoxy(93, 14);
			std::cout << "...";

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
				if (coord.X < 100 && coord.X >90 && coord.Y > 13 && coord.Y < 15)
				{
					Gotoxy(92, 14);
					std::cout << "    ";
					Gotoxy(93, 14);
					std::string remove;
					controlTyping(remove, 2);
					int n = std::stoi(remove);
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
							std::cout << "erolled";
				//remove course function here
							goto enrolled;
						}
					}
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
			Gotoxy(50, 14); std::wcout << "COURSE-NUMBER YOU WANT TO ENROLL:  ";
		//show list course here
			for (int i = 88; i < 100; i++)
			{
				Gotoxy(i, 13);
				std::cout << char(205);
				Gotoxy(i, 15);
				std::cout << char(205);
			}
			Gotoxy(92, 14);
			std::cout << "...";

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
				if (coord.X < 100 && coord.X >88 && coord.Y > 13 && coord.Y < 15)
				{
					Gotoxy(92, 14);
					std::cout << "    ";
					Gotoxy(93, 14);
					std::string course;
					controlTyping(course, 2);
					int n = std::stoi(course);
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
							std::cout << "erolled";
				//add course function here
							goto enroll;
						}
					}
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
void showScoreBoard(std::string courseName, std::string fileName)
{
	std::ifstream file(fileName, std::ios::in);
	if (file.is_open())
	{
		std::string check;
		std::vector<std::string> line;

		while (!file.eof())
		{
			std::getline(file, check);
			if (check == "") break;
			line = split(check, ",");
			
			
		}
		file.close();
	}
}
void importScoreBoard(std::string fileName, NodeStudent* pHead)
{
	std::ifstream file("scoreboard.txt", std::ios::in);
	//NodeScore* pCur = nullptr;
	NodeStudent* Cur = pHead;
	//test
	/*while (pHead)
	{
		std::cout << pHead->ID << " " << pHead->LastName;
		pHead = pHead->next;
	}*/
	if (file.is_open())
	{
		std::cout << 999;
		std::string check;
		std::vector<std::string> line;

		while (!file.eof())
		{
			std::getline(file, check);
			if (check == "") break;
			line = split(check, ",");

			if (Cur->ID == line[1])	
			{
				float total = std::stof(line[3]);
				float final = std::stof(line[4]);
				float mid = std::stof(line[5]);
				float other = std::stof(line[6]);
					
				//pCur = new NodeScore;
				Cur->profile = new NodeScore;
				Cur->profile->TotalMark = total;
				Cur->profile->Finalmark = final;
				Cur->profile->MidtermMark = mid;
				Cur->profile->Othermark = other;
			}
			Cur = Cur->next;
		}
		file.close();
	}
	else
		std::cout << 888;

	//test output
	Cur = pHead;
	while (Cur)
	{
		std::cout << Cur->ID << " " << Cur->profile->TotalMark << " " << Cur->profile->Finalmark << Cur->profile->MidtermMark << Cur->profile->Othermark << std::endl;
		Cur = Cur->next;
	}
}
void createStudent(NodeStudent*& pHead)
{
	std::ifstream file("allStudent.csv", std::ios::in);
	NodeStudent* pCur = nullptr;
	if (file.is_open())
	{
		std::string check;
		std::vector<std::string> line;

		while (!file.eof())
		{
			std::getline(file, check);
			if (check == "") break;
			line = split(check, ",");
			if (pHead == nullptr)
			{
				pCur = new NodeStudent;
				pHead = pCur;
			}
			else
			{
				pCur->next = new NodeStudent;
				pCur = pCur->next;
			}
			pCur->FirstName = line[2];
			pCur->LastName = line[3];
			pCur->ID = line[1];
			pCur->next = nullptr;
		
		}
		file.close();
	}
	//test output
	pCur = pHead; 
	while (pCur)
	{
		std::cout << pCur->ID << " " << pCur->LastName << std::endl;
		pCur = pCur->next;
	}
	
}