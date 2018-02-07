// ExtraOef09Iteratoren.cpp : Defines the entry point for the console application.
//


#include <string>
#include <iostream>

std::string readStringFromUser(std::string message);
int countWordsInString(std::string input);
int countCharacterInString(std::string &input, std::string character);
void capatilizeCharacterInString(std::string::iterator positionOfCharacter);
void changeCharacterInString(std::string &input, std::string character, char newCharacter);

// De functie om characters in de string te vervangn is geïmplementeerd,
// maar het leek me niet passend om deze in de uitvoer van het programma
// toe te voegen.

int main()
{
	auto input = readStringFromUser("Geef een string die bewerkt moet worden: ");
	const auto characterToSearchFor = readStringFromUser("Geef de character die in de string verandert moet worden.");
	
	std::cout << "De ingegeven string bevat " << countWordsInString(input) << " words." << std::endl;
	std::cout << "De gezochte character komt " << countCharacterInString(input, characterToSearchFor) << " keer voor in de string." << std::endl;
	std::cout << "De ingegeven string ziet er nu zo uit: " << std::endl << input << std::endl;
	
	std::cin.get();
	return 0;
}

std::string readStringFromUser(std::string message)
{
	std::string tmp = "";

	std::cout << message << std::endl;
	std::getline(std::cin, tmp);

	return tmp;
}

int countWordsInString(std::string input)
{
	auto wordCount = 0;

	for (auto iterator = input.cbegin(); iterator < input.cend(); ++iterator)
	{
		switch (*iterator)
		{
		case '.': case '?': case '!': case ' ':
			wordCount++;
			break;
		default:
			break;;
		}
	}

	return wordCount;
}

int countCharacterInString(std::string &input, std::string character)
{
	auto characterCount = 0;

	for (auto iterator = input.begin(); iterator < input.end(); ++iterator)
	{
		if (*iterator == character[0])
		{
			capatilizeCharacterInString(iterator);
			++characterCount;
		}
	}

	return characterCount;
}

void capatilizeCharacterInString(std::string::iterator positionOfCharacter)
{
	*positionOfCharacter = toupper(*positionOfCharacter);
}

void changeCharacterInString(std::string &input, std::string character, char newCharacter)
{
	for (auto iterator = input.begin(); iterator < input.end(); ++iterator)
	{
		if (*iterator == character[0])
			*iterator = newCharacter;
	}
}
