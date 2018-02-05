// Milan Dierick | 5IT | 07
// VTI Lokeren | 05/02/2017

#include <string>
#include <iostream>

#define MAX_ADRESSEN 1000

std::string readInputFromUser();
void readAllInputFromUser(std::string* pAdressen, int* pCounter);
std::string readSearchStringFromUser();
int findOccurencesInAllStrings(std::string* pAdressen, std::string searchString, int* pCounter);
void run(std::string* pAdressen, int* pCounter);

int main()
{
	int counter = 0;
	std::string adressen[MAX_ADRESSEN];

	int* pCounter = &counter;
	std::string* pAdressen = adressen;

	run(pAdressen, pCounter);

	return 0;
}

std::string readInputFromUser()
{
	std::string tmp;

	std::cout << "Geef je adres in het volgende formaat: [STRAAT] [HUISNUMMER], [POSTCODE] [GEMEENTE]." << std::endl;
	std::cout << "Als je geen adressen meer wilt ingeven, geef een '*' in." << std::endl;
	std::getline(std::cin, tmp);
	system("CLS");

	return tmp;
}

void readAllInputFromUser(std::string* pAdressen, int* pCounter)
{
	bool isEnabled = true;
	std::string input = "";

	do
	{
		input = readInputFromUser();
		if (input != "*")
		{
			*pAdressen = input;
			pAdressen++;
			*pCounter += 1;
		}
		else
		{
			isEnabled = false; 
		}
	}
	while (isEnabled);
}

std::string readSearchStringFromUser()
{
	std::string tmp;

	std::cout << "Geef de te zoeken string in. " << std::endl;
	std::cout << "Als je geen strings meer wilt ingeven, geef een '*' in." << std::endl;
	std::getline(std::cin, tmp);
	system("CLS");

	return tmp;
}

int findOccurencesInAllStrings(std::string* pAdressen, std::string searchString, int* pCounter)
{
	int localCounter = 0;
	int hitCounter = 0;

	do
	{
		if (pAdressen[localCounter].find(searchString) != std::string::npos)
		{
			hitCounter++;
		}

		localCounter++;
	}
	while (localCounter <= *pCounter);

	return hitCounter;
}

void run(std::string* pAdressen, int* pCounter)
{
	int hitCount = 0;
	bool isEnabled = true;
	std::string input = "";

	readAllInputFromUser(pAdressen, pCounter);

	do
	{
		input = readSearchStringFromUser();

		if (input == "*")
			isEnabled = false;
		else
			std::cout << input << " komt " << findOccurencesInAllStrings(pAdressen, input, pCounter) << " keer voor in de ingegeven adresregels." << std::endl;
	} while (isEnabled);
}
