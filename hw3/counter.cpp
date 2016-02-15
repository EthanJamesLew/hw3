#include"counter.h"
#include <fstream>
#include<string>
#include<stdio.h>
#include<iostream>
using namespace fileData;

bool fileExists(const std::string& name)
{
	std::ifstream f(name.c_str());
	if (f.good()) {
		f.close();
		return true;
	}
	else {
		f.close();
		return false;
	}
}

void revFile(std::string &fileName)
{
	std::ifstream file;
	std::ofstream out;
	std::string revName;
	std::string tempStr;
	std::string line;
	std::string con;

	for (int i = fileName.size() - 1; i >= 0; i--)
	{
		revName += fileName[i];
	}

	file.open(fileName.c_str());
	out.open(revName.c_str());

	while (file.peek() != EOF)
	{
		tempStr = "";
		getline(file, line);
		/*for (int i = line.size() - 1; i >= 0; i--)
		{
			tempStr += line[i];
		}*/
		tempStr = revWordInStr(line);
		out << tempStr << std::endl;
	}
	file.close();
	out.close();
	return;
}

int wordInStr(std::string sentence) {
	int numberOfWords = 0;
	size_t i;

	if (isalpha(sentence[0])) {
		numberOfWords++;
	}

	for (i = 1; i < sentence.length(); i++) {
		if ((isalpha(sentence[i])) && (!isalpha(sentence[i - 1]))) {
			numberOfWords++;
		}
	}

	return numberOfWords;
}

unsigned int numInStr(const std::string& s) {
	unsigned int count = 0;
	for (int i = 0; i < s.length(); i++)//for each char in string,
		if ((s[i] >= '0' && s[i] <= '9'))
		{
			count += 1;
		}
	return count;
}


unsigned int lowerInStr(const std::string& s)
{
	unsigned int count = 0;
	for (int i = 0; i < s.length(); i++)//for each char in string,
		if ((islower(s[i])))
		{
			count += 1;
		}
	return count;

}

Counter::Counter(std::ifstream &file)
{
	numWords = 0;
	numChars = 0;
	numLines = 0;
	numDigits = 0;
	numDigits2 = 0;
	std::string word;
	std::string line;

	//Read by word
	while (file.peek() != EOF)
	{
		
		getline(file, line);
		numWords += wordInStr(line);
		numChars += line.length();
		if ((numInStr(line) >= 1) && (lowerInStr(line)>=1))
		{
			numDigits += 1;
			if ((numInStr(line) >= 2) && (lowerInStr(line) >= 3))
			{
				numDigits2 += 1;
			}
		}

	}
	file.close();
}

Counter::Counter(std::string string)
{
	numWords = wordInStr(string);
	numLines = 1;
	numChars = 0;
	numDigits = 0;
	numDigits2 = 0;

	numChars += string.length();

	if ((numInStr(string) >= 1) && (lowerInStr(string) >= 1))
	{
		numDigits += 1;
		if ((numInStr(string) >= 2) && (lowerInStr(string) >= 3))
		{
			numDigits2 += 1;
		}
	}

}

Counter::~Counter()
{
}

unsigned int Counter::getNumDigits()
{
	return numDigits;
}

unsigned int Counter::getNumDigits2()
{
	return numDigits2;
}

unsigned int Counter::getNumChars()
{
	return numChars;
}

unsigned int Counter::getNumWords()
{
	return numWords;
}
