#include <fstream>
#include <iostream>

/*
 *
 * assigns the object to a file and opens it for input
 *
 */
class InFile {
	private:
		char* filename;
		std::ifstream file;

	public:
		InFile(char* str);
		~InFile();

		std::ifstream& operator>>(char* ch);
		bool isOpen();
		bool eof();
};

/*
 *
 * assigns the object to a file and opens it for output
 *
 */
class OutFile {
	private:
		char* filename;
		std::ofstream file;

	public:
		OutFile(char* str);
		~OutFile();

		std::ofstream& operator<<(char*);
		bool isOpen();
		bool eof();
};