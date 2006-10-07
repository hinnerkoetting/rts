
#ifndef UTIL_H
#define UTIL_H

#include <string>

int				wstringToInteger(const std::wstring&);
std::wstring	integerToWString(int);
int				stringToInteger(const std::string&);
std::string		IntegerToString(int);

std::wstring	integerToHexWString(int);
//std::string		WStringToString(const std::wstring&);
//std::wstring	StringToWString(const std::string&);

namespace log{
	void initLog();
	void log(std::string msg);
	void log(char* p);
}


#endif