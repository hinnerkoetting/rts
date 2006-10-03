/*
 *@author: Hinnerk Oetting
 *File: file.cpp
 *
 * file handling
 */


#include <fstream>
#include <iostream>
#include <ios>
#include <windows.h>

#include "file.h"

/*
 *
 * 
 *
 */
InFile::InFile(char* str) {
	filename = str;
	file.open(filename);
}

/*
 *
 * 
 *
 */
InFile::~InFile() {
	file.close();
}

/*
 *
 * reads until eoln or next space
 *
 */
std::ifstream& InFile::operator>>(char* ch) {
	file >> ch;
	return file;
}

/*
 *
 * 
 *
 */
bool InFile::isOpen() {
	return (file.is_open());
}

/*
 *
 *
 *
 */
bool InFile::eof() {
	return !file.good();
}

/*
 *
 *
 *
 */
OutFile::OutFile(char* str) {
	filename = str;
	file.open(filename,std::ios::out);
}

/*
 *
 * 
 *
 */
OutFile::~OutFile() {
	file.close();
}

/*
 *
 * 
 *
 */
bool OutFile::isOpen() {
	return (file.is_open());
}

/*
 *
 * writes a line into the file
 *
 */
std::ofstream& OutFile::operator <<(char* ch) {
	file << ch;
	return file;
}

/*
 *
 *
 *
 */
bool OutFile::eof() {
	return !file.good();
}