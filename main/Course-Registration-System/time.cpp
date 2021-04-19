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

	write << d.year << "/" << d.month << "/" << d.day;

	return write.str();
}

date parseDate(std::string str)
{
	date result;

	std::vector<std::string> token = split(str, "/");

	result.year = std::stoi(token[2]);
	result.month = std::stoi(token[1]);
	result.day = std::stoi(token[0]);

	return result;
}

void copyDate(date& a, date b)
{
	a.year = b.year;
	a.month = b.month;
	a.day = b.day;
}

bool checkValid(date D)
{
	int d = D.day;
	int m = D.month;
	int y = D.year;

	if (!(1 <= m && m <= 12))
		return false;
	if (!(1 <= d && d <= 31))
		return false;
	if ((d == 31) && (m == 2 || m == 4 || m == 6 || m == 9 || m == 11))
		return false;
	if ((d == 30) && (m == 2))
		return false;
	if ((m == 2) && (d == 29) && (y % 4 != 0))
		return false;
	if ((m == 2) && (d == 29) && (y % 400 == 0))
		return true;
	if ((m == 2) && (d == 29) && (y % 100 == 0))
		return false;
	if ((m == 2) && (d == 29) && (y % 4 == 0))
		return true;

	return true;
	
}
