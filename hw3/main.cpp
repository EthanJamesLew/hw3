//G03729047 Ethan Lew
#include"main.h"
using namespace std;

int main(int argc, char *argv[])
{
	string fileName = "";
	ifstream inFile;

	do {
		cout << "Enter a file name: ";
		cin >> fileName;

		if (fileExists(fileName) == false)
		{
			cout << "\nWhoops! That file doesn't exist. ";
		}
	} while (fileExists(fileName) == false);
	

	inFile.open(fileName);

	revFile(fileName);

	fileData::Counter count = fileData::Counter(inFile);
	cout << "Filename: " << fileName << endl;
	cout << "\nNumber of uppercase letters: " << count.getNumUpper() << endl;
	cout << "\nNumber of lowercase letters: " << count.getNumLower() << endl;
	cout << "\nNum of characters: " << count.getNumChars() << endl;
	cout << "\nNumber of digits: " << count.getNumDigits() << endl;
	cout << "\nNumber of words: " << count.getNumWords() << endl;
	cout << "\nNum of lines with 1 digit and 1 lower case: " <<count.getCond() << endl;
	cout << "\nNum of lines with 2 digits and 3 lower-case: " << count.getCond2() << endl;

	cout << endl << "\n Wrote file to disk." << endl;

	return 0;
}

