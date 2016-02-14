#include<fstream>
#include <string>
#ifndef COUNTER_H
#define COUNTER_H

bool fileExists(const std::string& name);

void revFile(std::string &fileName);

std::string revWordInStr(std::string &words);

namespace fileData
{
	class Counter
	{
	public:

		unsigned int getNumDigits();
		unsigned int getNumDigits2();
		//unsigned int getNumLines();
		unsigned int getNumChars();
		unsigned int getNumWords();
		Counter(std::ifstream &file);
		Counter(std::string string);
		~Counter();

	private:
		unsigned int numDigits;
		unsigned int numDigits2;
		unsigned int numLines;
		unsigned int numChars;
		unsigned int numWords;

	};

}
#endif