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
	/*ListClass* classes = new ListClass;

	createEmptyList(classes);
	addClass(classes, 1, "CLC");
	ReadListToClass("allStudent.csv", getNode(classes->head, 1));
	OutputListStudents(getNode(classes->head, 1));
	CreateStudentAccounts(getNode(classes->head, 1));*/
	home();
	login();

	return 0;
}

