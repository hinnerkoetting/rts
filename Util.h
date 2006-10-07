
#ifndef UTIL_H
#define UTIL_H

#include <string>

int				WStringToInteger(const std::wstring&);
std::wstring	IntegerToWString(int);
int				StringToInteger(const std::string&);
std::string		IntegerToString(int);

std::wstring	IntegerToHexWString(int);
//std::string		WStringToString(const std::wstring&);
//std::wstring	StringToWString(const std::string&);

namespace log{
	void initLog();
	void log(std::string msg);
	void log(char* p);
}


#endif