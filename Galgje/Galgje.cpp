// Galgje.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

#define MAX_MESSAGE_LENTH 50

std::string chooseUnkownWord();
void resizeResultString(std::string *unknownWord, std::string *resultString);
std::string readStringFromUser(char *message);
char readCharacterGuessFromUser(bool checkForDuplicate = false);
bool compareCharacterGuessWithUnknownWord(char guess, std::string *unknownWord, std::string *resultString);
void printResult(std::string *resultString);
void runGame(std::string *unknownWord, std::string *resultString);


int main()
{
	// dynalloc
	auto message = new char[MAX_MESSAGE_LENTH];
	auto unknownWord = new std::string;
	auto resultString = new std::string();

	runGame(unknownWord, resultString);

	// clean-up
	delete[] message;
	delete unknownWord;
	delete resultString;

	std::cin.get();
    return 0;
}

std::string chooseUnkownWord()
{
	// TODO: Implement picking unkown word form predefined list.
	return readStringFromUser("Geef het te zoeken woord: ");
}

void resizeResultString(std::string *unknownWord, std::string *resultString)
{
	auto iteratorResultString = resultString->begin();

	for (auto iteratorUnknownWord = unknownWord->cbegin(); iteratorUnknownWord != unknownWord->cend(); ++iteratorUnknownWord)
	{
		
	}
}

std::string readStringFromUser(char *message)
{
	auto tmp = std::string(message);

	std::cout << tmp;
	getline(std::cin, tmp);

	return tmp;
}

char readCharacterGuessFromUser(bool checkForDuplicate)
{
	// TODO: Implement checking for characters that have already been entered before.
	return readStringFromUser("Geef je gok in: ")[0];
}

bool compareCharacterGuessWithUnknownWord(char guess, std::string *unknownWord, std::string *resultString)
{
	// NOTE: The size of 'unknownWord' has te be the same as 'resultString'!
	auto isCorrect = true;
	auto iteratorResultString = resultString->begin();

	for (auto iterator = unknownWord->cbegin(); iterator != unknownWord->cend(); ++iterator)
	{
		if (*iterator != guess)
			isCorrect = false;
		else
		{
			*resultString = guess;
			isCorrect = true;
		}

		++iteratorResultString;
	}

	printResult(resultString);

	return isCorrect;
}

void printResult(std::string *resultString)
{
	for (auto iterator = resultString->cbegin(); iterator != resultString->cend(); ++iterator)
		std::cout << *iterator << " ";
}

void runGame(std::string *unknownWord, std::string *resultString)
{
	*unknownWord = chooseUnkownWord();
	resultString->resize(unknownWord->size());
	readCharacterGuessFromUser(false);

	while (!compareCharacterGuessWithUnknownWord(readCharacterGuessFromUser(false), unknownWord, resultString))
	{
		std::cout << "Jammer, maar je hebt het woord nog niet geraken. \nrobeer het nog eens." << std::endl;
	}
}
