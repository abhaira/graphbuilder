#include <fstream>
#include <list>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <iostream>

struct path
{
	std::string strFirstNode;
	std::string strSecondNode;
	const int cost;
};

struct ErrorInvalidFormatException {};

static inline void ltrim(std::string& s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch)
	{
		return !std::isspace(ch);
	}));
}

// trim from end (in place)
static inline void rtrim(std::string& s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch)
	{
		return !std::isspace(ch);
	}).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string& s)
{
	ltrim(s);
	rtrim(s);
}

static void parseLineIntoTokens(const std::string& line,
																std::vector<std::string>& tokens)
{
	const char *token = strtok((char *)line.c_str(), ",");

	while (token)
	{
		std::string str(token);
		trim(str);
		tokens.push_back(str);
		token = strtok(NULL, ",");
	}
}

std::list<path> parseFile(std::string pstrInputPath)
{
	std::list<path> paths{};

	std::ifstream inputFile{pstrInputPath};
	std::string line{};

	while (std::getline(inputFile, line))
	{
		std::vector<std::string> tokens;
		parseLineIntoTokens(line, tokens);

		if (tokens.size() != 3) { throw ErrorInvalidFormatException(); }

		paths.push_back(path{tokens[0], tokens[1], std::atoi(tokens[2].c_str())});
	}

	return paths;
}
