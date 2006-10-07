
#include "Util.h"
#include <sstream>
#include <iostream>
#include <locale>
#include "windows.h"

using namespace std;

int WStringToInteger(const std::wstring& str)
{
	std::wstringstream StringStr(str);
	int Integer;

	StringStr >> Integer;
	return Integer;
}


int StringToInteger(const std::string& str)
{
	std::stringstream StringStr(str);
	int Integer;

	StringStr >> Integer;
	return Integer;
}

std::wstring IntegerToWString(int Integer)
{
	std::wstringstream StringStr;
	StringStr << Integer;

	return StringStr.str();
}

std::string IntegerToString(int Integer)
{
	std::stringstream StringStr;
	StringStr << Integer;

	return StringStr.str();
}


std::wstring IntegerToHexWString(int Integer)
{
	std::wstringstream StringStr;
	StringStr << uppercase << hex << Integer;

	return StringStr.str();
}

void log::initLog(){
#ifdef _DEBUG
	if (!	AllocConsole()){
		MessageBox(NULL, "Cannot open console","error", MB_ICONERROR);
	}
#endif

}


void log::log(string msg){
#ifdef _DEBUG
	DWORD returnLen;
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), msg.c_str(),msg.length(),&returnLen, NULL);

#endif


}


/*
std::string WStringToString(const std::wstring& str)
{
	char* Narrow = new char[str.size() + 1];
	char defChar = ' ';
	_USE(cout.getloc(), ctype<wchar_t> ).narrow(str.c_str(), str.c_str()+ str.size() + 1, defChar, Narrow);

	std::string ret(Narrow);
	delete[] Narrow;

	return ret;
}
std::wstring StringToWString(const std::string& str)
{
	wchar_t* Widen = new wchar_t[str.size() + 1];
	_USE(cout.getloc(), ctype<wchar_t> ).widen(str.c_str(), str.c_str() + str.size(), Widen);

	Widen[str.size()] = 0;

	std::wstring wstr = Widen;
	delete[] Widen;

	return wstr;
}
*/