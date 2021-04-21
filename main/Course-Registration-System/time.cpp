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

date getDate()
{
	date d;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	
	d.year = GetYear();
	d.month = GetMonth();
	d.day = GetDay();

	return d;
}

std::string displayDate(date d)
{
	std::stringstream write;

	write << d.year << "-" << d.month << "-" << d.day;

	return write.str();
}
