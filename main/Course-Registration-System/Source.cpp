
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

	Read_a_Course("Text1.txt", C);
	viewList(C);


}

