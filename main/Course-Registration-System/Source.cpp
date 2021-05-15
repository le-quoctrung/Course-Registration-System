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
login:
    loginDisplay();
    login();
   
    
    /*POINT CursorPos;
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
                GetCursorPos(&CursorPos);
                std::cout << CursorPos.x << " " << CursorPos.y;
            }
        }
    }
    return 0;*/
    //std::cout << "click anywhere in console window to write - hello world -\n\n\n\n\n\n\n\n\n\n\n\n\n"
    //    "Press Ctrl+C to Exit";
    //POINT cursorPos;
    //HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    //HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
    //INPUT_RECORD InputRecord;
    //DWORD Events;
    //COORD coord;
    //CONSOLE_CURSOR_INFO cci;
    //cci.dwSize = 25;
    //cci.bVisible = FALSE;
    //SetConsoleCursorInfo(hout, &cci);
    //SetConsoleMode(hin, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);


    //while (1)
    //{
    //    index:
    //    ReadConsoleInput(hin, &InputRecord, 1, &Events);

    //    if (InputRecord.EventType == MOUSE_EVENT)
    //    {
    //        if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
    //        {
    //            coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
    //            coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
    //            SetConsoleCursorPosition(hout, coord);
    //            //SetConsoleTextAttribute(hout, rand() % 7 + 9);
    //            GetCursorPos(&cursorPos);
    //            std::cout << coord.X << " " << coord.Y << std::endl << cursorPos.x << " " << cursorPos.y;
    //             
    //        }
    //    }
    //    FlushConsoleInputBuffer(hin);
    //}
    writeScoreboard();
    return 0;
}
