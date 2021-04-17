
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
	Start();
	/*Class* APCS = nullptr;

	createClass(APCS);

	Read_List_to_Class("allStudent.csv", APCS);

	Output_Student(APCS->Students);*/
	
	POINT xypos;
	while (1) {
		GetCursorPos(&xypos);
		cout << xypos.x << " " << xypos.y << endl;
		
	}
	
	return 0;
}

