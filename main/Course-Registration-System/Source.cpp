
#include <iostream>
#include "Login_System.h"
#include "Console.h"
#include "time.h"
#include "Tokenizer.h"
#include "school.h"
#include "file.h"
#include "display.h"



int main()
{
	Course* C = nullptr;
//	Start();
//	/*Class* APCS = nullptr;
//
//	createClass(APCS);
//
//	Read_List_to_Class("allStudent.csv", APCS);
//
//	Output_Student(APCS->Students);*/
//	
//	/*POINT xypos;
//	while (1) {
//		GetCursorPos(&xypos);
//<<<<<<< HEAD
//		cout << xypos.x << " " << xypos.y << endl;
//		
//	}
//=======
//		cout << xypos.x << endl << xypos.y;
//		system("cls");
//	}*/
////>>>>>>> 76ec897d18d5a6eeee4552c6cc98d4d9af468734
//	
//	date today = getDate();
//
//	/std::cout << displayDate(today);
//
//	return;
	Read_a_Course("Text1.txt", C);
	viewList(C);

}

