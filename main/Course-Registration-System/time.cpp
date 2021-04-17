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
date getDate()
{
	date d;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	
	d.year = 1900 + ltm->tm_year;
	d.month = 1 + ltm->tm_mon;
	d.day = ltm->tm_mday;

	return d;
}

void displayDate(date* d)
{
	std::cout << d->year << "-" << d->month << "-" << d->day;
}

int GetDay()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	return  ltm->tm_mday;
}