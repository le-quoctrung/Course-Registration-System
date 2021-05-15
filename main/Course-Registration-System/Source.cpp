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
    

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                                                                                                         //
    //  This is an example for                                                                                                 //
    //  +Creating a year                                                                                                       //
    //  +Use getNode to get indices in a list          PLEASE                                                                  //
    //  +Finding NodeStudent function                  DO NOT DELETE ALL OF THE EXAMPLES                                       //
    //  +Enrolling system                              IMPORTANT FOR THE PROJECT! Thank you :> glhf                            //
    //  Please comment this later                                                                                              //
    //                                                                                                                         //
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Initialization
    ListYear* nYear = nullptr;
    createEmptyList(nYear);

    //Exmaple Add Year
    if(!AddYear(nYear)) return 0; //Rmb to uncomment CanAddYear() inside AddYear()

    //Get current Year
    OutputListYear(nYear);
    int x;
    std::cout << "\nEnter index: "; std::cin >> x;
    NodeYear* CurYear = getNode(nYear->head, x);

    //Example Add Semester and Courses
    if (!AddSemester(CurYear->semesters, 1, GetDate(), ParseDate("1/6/2021"))) return 0; //Rmb to uncomment CanAddSem() inside AddSem()
    ReadListToCourse("db\\hk1.txt", CurYear->semesters->tail->Courses);
    if (!AddSemester(CurYear->semesters, 2, GetDate(), ParseDate("1/7/2021"))) return 0;
    ReadListToCourse("db\\hk2.txt", CurYear->semesters->tail->Courses);
    if (!AddSemester(CurYear->semesters, 3, GetDate(), ParseDate("1/8/2021"))) return 0;
    ReadListToCourse("db\\hk3.txt", CurYear->semesters->tail->Courses);
    OutputListSem(CurYear->semesters);

    //Get current Semester
    int y;
    std::cout << "\nEnter index: "; std::cin >> y;
    NodeSem* CurSem = getNode(CurYear->semesters->head, y);
    OutputSem(CurSem);
    system("pause");
        
    //Example for adding Class
    if (!AddClass(CurYear->classes, getSize(nYear->head), "20CLC")) return 0;
    ReadListStudentToClass("allStudent.csv", CurYear->classes->head);

    //From username in login system, find the student's Node
    NodeStudent* LoginStudent = FindStudent(CurYear->classes, "19127555");
    OutputStudent(LoginStudent);
    system("pause");

    //Enrolling the logged in Student
    Enroll(CurSem->Courses,LoginStudent);

    //Check the course class
    OutputListCourse(CurSem->Courses);

    WriteAll("Test1.bin", nYear);

    //Deallocating
    DeleteListYear(nYear);

    ListYear* Year = nullptr;
    ReadAll("Test1.bin", Year);
    OutputListYear(Year);
    system("pause");
    system("CLS");
    OutputListClass(Year->head->classes);
    system("pause");
    system("CLS");
    OutputListStudents(Year->head->classes->head->Students);
    system("pause");
    system("CLS");
    OutputListSem(Year->head->semesters);
    system("pause");
    system("CLS");
    OutputListCourse(Year->head->semesters->head->Courses);

    return 0;
}