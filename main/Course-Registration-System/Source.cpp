

#include "Login_System.h"
#include "Console.h"
#include "time.h"
#include "Tokenizer.h"
#include "school.h"
#include "file.h"
#include "display.h"
#define xPos 307/42
#define yPos 863/53


int main()
{
	Start();
<<<<<<< HEAD
    home();
	/*return 0;
 
        cout << "click anywhere in console window to write - hello world -\n\n\n\n\n\n\n\n\n\n\n\n\n"
            "Press Ctrl+C to Exit";

        HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
        HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
        INPUT_RECORD InputRecord;
        DWORD Events;
        COORD coord;
        CONSOLE_CURSOR_INFO cci;
        cci.dwSize = 25;
        cci.bVisible = FALSE;
        SetConsoleCursorInfo(hout, &cci);
        SetConsoleMode(hin, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);


        while (1)
        {

            ReadConsoleInput(hin, &InputRecord, 1, &Events);

            if (InputRecord.EventType == MOUSE_EVENT)
            {
                if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
                {
                    coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
                    coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
                    SetConsoleCursorPosition(hout, coord);
                    SetConsoleTextAttribute(hout, rand() % 7 + 9);
                    
                    cout << "Hello world";

                }
            }
            FlushConsoleInputBuffer(hin);
        }*/
        return 0;

  
=======
	/*Class* APCS = nullptr;

	createClass(APCS);

	Read_List_to_Class("allStudent.csv", APCS);

	Output_Student(APCS->Students);*/
	
	/*POINT xypos;
	while (1) {
		GetCursorPos(&xypos);
		cout << xypos.x << endl << xypos.y;
		system("cls");
	}*/
	
	date today = getDate();

	std::cout << displayDate(today);

	return 0;
>>>>>>> 5c6990a42d1ca5518654f8a327321a19cc38e4ce
}

