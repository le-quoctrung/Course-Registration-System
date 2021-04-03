
#include <iostream>
#include "Login_System.h"
#include "Console.h"
#include"time.h"
#include "Tokenizer.h"
#include "school.h"
#include"file.h"

int main()
{
	student* A;
	int n = 0;
	ReadFile("input.txt", A,n);
	Output(A, n);

	return 0;
}
