
#include <iostream>
#include "Login_System.h"
#include "Console.h"
#include"time.h"
#include "Tokenizer.h"
#include "school.h"
#include"file.h"

int main()
{
	student* pHead = nullptr;
	
	ReadFile("input.txt", pHead);
	Output(pHead);

	
	return 0;
}
