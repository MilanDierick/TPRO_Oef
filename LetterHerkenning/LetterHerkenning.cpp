// LetterHerkenning.cpp : Defines the entry point for the console application.
//

#define WIDTH 5
#define LENGTH 5
#include <complex>
#include <iostream>

void inputCharacter(int charakter[][LENGTH], int defaultCharakter[][LENGTH]);
void outputCharakter(int charakter[][LENGTH]);
double compareCharacters(int unknownCharacter[][LENGTH], int character[][LENGTH]);

int main()
{
	int defaultCharakter[][LENGTH] = {
		5,5,5,5,5,
		5,5,5,5,5,
		5,5,5,5,5,
		5,5,5,5,5,
		5,5,5,5,5
	};
	int unknownCharacter[WIDTH][LENGTH] = {

	};

	int charakterA[][LENGTH] = {
		0,1,1,1,0,
		1,0,0,0,1,
		1,1,1,1,1,
		1,0,0,0,1,
		1,0,0,0,1,
	};

	int charakterB[][LENGTH] = {
		1,1,1,1,0,
		1,0,0,0,1,
		1,1,1,1,0,
		1,0,0,0,1,
		1,1,1,1,0
	};
	
	inputCharacter(unknownCharacter, defaultCharakter);
	std::cout << "Charakter: " << std::endl;
	outputCharakter(unknownCharacter);
	std::cout << compareCharacters(unknownCharacter, charakterA);

	system("PAUSE");
    return 0;
}

void inputCharacter(int unknownCharacter[][LENGTH], int defaultCharakter[][LENGTH])
{
	unknownCharacter = defaultCharakter;
	std::cout << "Geef in een grid van 5 op 5 een nieuwe character in." << std::endl;

	for (unsigned short x = 0; x < WIDTH; x++)
	{
		for (unsigned short y = 0; y < LENGTH; y++)
		{
			outputCharakter(unknownCharacter);
			std::cout << "Geef de waarde voor [" << x << "][" << y << "]: ";
			std::cin >> unknownCharacter[x][y];
			system("CLS");
		}
	}
}

void outputCharakter(int charakter[][LENGTH])
{
	for (unsigned short x = 0; x < WIDTH; x++)
	{
		for (unsigned short y = 0; y < LENGTH; y++)
		{
			std::cout << charakter[x][y];
		}
		std::cout << std::endl;
	}
}

double compareCharacters(int unknownCharacter[][LENGTH], int character[][LENGTH])
{
	double mse = 0.0;

	for (auto x = 0; x < WIDTH; x++)
	{
		for (auto y = 0; y < LENGTH; y++)
		{
			mse += std::pow(unknownCharacter[x][y] - character[x][y], 2);
		}
	}

	return mse / (WIDTH * LENGTH);
}

