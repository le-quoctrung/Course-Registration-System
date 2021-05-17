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
    ListYear* nYear = nullptr;
    loginDisplay();
    login(nYear);


    
    //NodeStudent* phead = nullptr;
    //createStudent(phead);
    //importScoreBoard("score.txt", phead);

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

    ////Initialization
    //ListYear* nYear = nullptr;
    //createEmptyList(nYear);

    ////Exmaple Add Year
    //if(!AddYear(nYear)) return 0; //Rmb to uncomment CanAddYear() inside AddYear()

    ////Get current Year
    //OutputListYear(nYear);
    //int x;
    //std::cout << "\nEnter index: "; std::cin >> x;
    //NodeYear* CurYear = getNode(nYear->head, x);

    ////Example Add Semester and Courses
    //if (!AddSemester(CurYear->semesters, 1, GetDate(), ParseDate("1/6/2021"))) return 0; //Rmb to uncomment CanAddSem() inside AddSem()
    //ReadListToCourse("db\\hk1.txt", CurYear->semesters->tail->Courses);
    //if (!AddSemester(CurYear->semesters, 2, GetDate(), ParseDate("1/7/2021"))) return 0;
    //ReadListToCourse("db\\hk2.txt", CurYear->semesters->tail->Courses);
    //if (!AddSemester(CurYear->semesters, 3, GetDate(), ParseDate("1/8/2021"))) return 0;
    //ReadListToCourse("db\\hk3.txt", CurYear->semesters->tail->Courses);
    //OutputListSem(CurYear->semesters);

    ////Get current Semester
    //int y;
    //std::cout << "\nEnter index: "; std::cin >> y;
    //NodeSem* CurSem = getNode(CurYear->semesters->head, y);
    //OutputSem(CurSem);
    //system("pause");
    //    
    ////Example for adding Class
    //if (!AddClass(CurYear->classes, getSize(nYear->head), "20CLC")) return 0;
    //ReadListStudentToClass("allStudent.csv", CurYear->classes->head);

    ////From username in login system, find the student's Node
    //NodeStudent* LoginStudent = FindStudent(CurYear->classes, "19127555");
    //OutputStudent(LoginStudent);
    //system("pause");

    ////Enrolling the logged in Student
    //Enroll(CurSem->Courses,LoginStudent);

    ////Check the course class
    //OutputListCourse(CurSem->Courses);

    //WriteAll("Test1.bin", nYear);

    ////Deallocating
    //DeleteListYear(nYear);

    //ListYear* Year = nullptr;
    //ReadAll("Test1.bin", Year);
    //OutputListYear(Year);
    //system("pause");
    //system("CLS");
    //OutputListClass(Year->head->classes);
    //system("pause");
    //system("CLS");
    //OutputListStudents(Year->head->classes->head->Students);
    //system("pause");
    //system("CLS");
    //OutputListSem(Year->head->semesters);
    //system("pause");
    //system("CLS");
    //OutputListCourse(Year->head->semesters->head->Courses);

    return 0;
}