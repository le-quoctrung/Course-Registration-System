#include "time.h"

int GetYear()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	return 1900 + ltm->tm_year;
}
int GetMonth()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	return 1 + ltm->tm_mon;
}
int GetDay()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	return  ltm->tm_mday;
}
void findSemesYear(int M) {
	switch (M) {
	case 4:
	case 5:
	case 6:
		cout << "\nSemester 3\n";
		break;
	case 7:
	case 8:
	case 9:
		cout << "\nSemester 1\n";
		break;
	case 10:
	case 11:
	case 12:
		cout << "\nSemester 2\n";
	}
}