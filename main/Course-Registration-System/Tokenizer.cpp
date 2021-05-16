#include "Tokenizer.h"
#include"Console.h"

std::vector<std::string> split(std::string haystack, std::string needle)
{
	size_t found;
	int cur = 0;
	std::vector<std::string> result;

	while (true)
	{
		found = haystack.find(needle, cur);

		if (found != haystack.npos)
		{
			result.push_back(haystack.substr(cur, found - cur));
			cur = found + needle.length();
		}
		else
		{
			result.push_back(haystack.substr(cur, haystack.length()));
			break;
		}

	}

	return result;
}
void controlTyping(std::string &name, short limit)
{
	HienTroChuot();
	name = "";
	char chname = _getch();
	while (chname != ENTER) //character 13 is enter
	{
		if (name.length() > limit && chname != '\b') chname = '\0';
		else if (chname == '\b' && name.length() > 0)//if user typed backspace 
		{
			std::cout << "\b \b";//rub the character behind the cursor.
			name.pop_back();
		}
		else if (chname == '\b' && name.length() == 0) chname = '\0';
		else
		{
			name.push_back(chname);
			std::cout << chname;
		}
		chname = _getch();
	}
	AnTroChuot();
}
