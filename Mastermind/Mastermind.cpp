// Milan Dierick | 5IT | 07
// VTI Lokeren | 22/01/2018
// Mastermind.cpp : Defines the entry point for the console application.
//

#include <cstdlib>
#include <iostream>

void generateRandomNumbers(int* pointerToRandomNumbers);
void inputGuessesFromUser(int* pointerToGuesses, int* pointerToRandomNumbers);
int compareGuessesWithRandomNumbers(int* pointerToGuesses, int* pointerToRandomNumbers);
bool keepPlaying();
void playGame(int* pointerToGuesses, int* pointerToRandomNumbers);
void printFeedbackToUser(int correctNumberCount);
void resetPointers(int* pointerToGuesses, int* pointerToRandomNumbers);

#define RANDOM_NUMBER_COUNT 4
#define MAX_GUESS_COUNT 12

int main()
{
	int randomNumbers[RANDOM_NUMBER_COUNT];
	int guesses[RANDOM_NUMBER_COUNT];
	const auto pointerToRandomNumbers = randomNumbers;
	const auto pointerToGuesses = guesses;

	playGame(pointerToGuesses, pointerToRandomNumbers);

	std::cin.get();
    return 0;
}

void generateRandomNumbers(int* pointerToRandomNumbers)
{
	auto tmp = 0;
	for (auto i = 0; i < RANDOM_NUMBER_COUNT;)
	{
		tmp = rand() % 9;
		if (std::count(pointerToRandomNumbers, pointerToRandomNumbers + RANDOM_NUMBER_COUNT, tmp) == 0)
		{
			std::cout << tmp;
			pointerToRandomNumbers[i] = tmp;
			i++;
		}
	}
}

void inputGuessesFromUser(int* pointerToGuesses, int* pointerToRandomNumbers)
{
	resetPointers(pointerToGuesses, pointerToRandomNumbers);

	for (auto i = 0; i < RANDOM_NUMBER_COUNT; i++)
	{
		std::cout << "Geef getal " << i + 1 << ": ";
		std::cin >> *pointerToGuesses;
		std::cout << std::endl;
		pointerToGuesses++;
	}
}

int compareGuessesWithRandomNumbers(int* pointerToGuesses, int* pointerToRandomNumbers)
{
	auto correctNumberCount = 0;

	resetPointers(pointerToGuesses, pointerToRandomNumbers);

	for (auto i = 0; i < RANDOM_NUMBER_COUNT; i++)
	{
		if (*pointerToGuesses == *pointerToRandomNumbers)
			correctNumberCount++;

		pointerToGuesses++;
		pointerToRandomNumbers++;
	}

	return correctNumberCount;
}

bool keepPlaying()
{
	auto input = 'n';

	do
	{
		std::cout << "Wil je nog een ronde spelen (j/n)? ";
		std::cin >> input;
		std::cout << std::endl;
	}
	while (input != 'j' && input != 'n');

	if (input == 'j')
		return true;

	return false;
}

void playGame(int* pointerToGuesses, int* pointerToRandomNumbers)
{
	auto tries = 0;
	auto correctNumberCount = 0;

	// Makes sure that every execution has a different set of random numbers.
	srand(NULL);

	do
	{
		generateRandomNumbers(pointerToRandomNumbers);
		do
		{
			inputGuessesFromUser(pointerToGuesses, pointerToRandomNumbers);
			correctNumberCount = compareGuessesWithRandomNumbers(pointerToGuesses, pointerToRandomNumbers);
			printFeedbackToUser(correctNumberCount);
			tries++;
		} while (tries < MAX_GUESS_COUNT && correctNumberCount != 4);
	}
	while (keepPlaying());
}

void printFeedbackToUser(int correctNumberCount)
{
	std::cout << "Je hebt " << correctNumberCount << " juiste getallen geraden!" << std::endl;
}

void resetPointers(int* pointerToGuesses, int* pointerToRandomNumbers)
{
	pointerToGuesses -= RANDOM_NUMBER_COUNT;
	pointerToRandomNumbers -= RANDOM_NUMBER_COUNT;
}