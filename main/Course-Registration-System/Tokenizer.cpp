#include "Tokenizer.h"

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
