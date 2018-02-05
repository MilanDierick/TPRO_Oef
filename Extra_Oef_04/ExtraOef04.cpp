// ExtraOef04.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <string>

#define charactersAmount 512
#define charactersInAlphabet 26

using namespace std;

int main()
{
	ifstream ifs("read.txt");
	char characters[charactersAmount];
	int characterCounts[charactersInAlphabet];
	char c;
	int charCount = 0;
	int i = 0;

	if (!ifs) {
		cout << "can not open file" << endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}

	while (ifs >> c)
	{
		characters[i] = c;
		++i;
	}

	for (int i = 0; i < charactersInAlphabet; i++)
	{
		characterCounts[i] = 0;
	}

	for each (char character in characters)
	{
		characterCounts[character - 97]++;
	}
	
	i = 0;

	for each (int charCount in characterCounts)
	{
		cout << static_cast<char>(i + 97) << ": " << charCount << endl;
		++i;
	}

	system("PAUSE");
    return 0;
}

