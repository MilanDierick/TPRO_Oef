// Milan Dierick | 5IT | 07 | VTI Lokeren | 19/02/2018
// ExtraOefKlastaakStringsEnVectoren.cpp : Defines the entry point for the console application.
// 

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

bool isPalindroom(const std::string& woord);
void invoerTeTestenStrings(std::vector<std::string>& teTestenStrings);
void controleerStringsVoorPalindromen(std::vector<std::string>& teTestenStrings, std::vector<bool>& testResultaten);
void printResultaat(std::vector<std::string>& teTestenStrings, std::vector<bool>& testResultaten);
void clearScreen();
void save(std::vector<std::string> &teTestenStrings); // Dit programma maakt zelf het data-bestand niet aan!
void load(std::vector<std::string> &teTestenStrings); // Dit programma maakt zelf het data-bestand niet aan!

int main()
{
	auto tmp = false;
	auto isRunning = true;
	auto input = 'n';
	std::vector<std::string> teTestenStrings;
	std::vector<bool> testResultaat;

	do
	{
		teTestenStrings.clear();
		testResultaat.clear();

		//invoerTeTestenStrings(teTestenStrings);
		load(teTestenStrings); // Als data wordt geladen, wordt de data die al in 'testResultaten' staat, overschreven.
		controleerStringsVoorPalindromen(teTestenStrings, testResultaat);
		printResultaat(teTestenStrings, testResultaat);
		save(teTestenStrings); // Als data wordt opgeslaan, wordt de data die al in het data-bestand staat, uiteraard overschreven.
		std::cout << "Wil je het programma opnieuw uitvoeren(j/n):";
		std::cin >> input;

		if (input == 'n')
			isRunning = false;
	}
	while (isRunning);

	return 0;
}

bool isPalindroom(const std::string& woord)
{
	auto isPalindroom = true;

	auto pos1 = woord.cbegin();
	auto pos2 = woord.cend() - 1;

	do
	{
		if (*pos1 != *pos2)
			return false;

		++pos1;
		--pos2;
	}
	while (pos1 != woord.cend() && pos2 != woord.cbegin());

	return true;
}

void invoerTeTestenStrings(std::vector<std::string>& teTestenStrings)
{
	std::string input;
	auto isRunning = true;

	do
	{
		std::cout << "Geef een woord dat je wil laten nakijken: ";
		std::cin >> input;

		if (input == "-1")
			isRunning = false;
		else
			teTestenStrings.push_back(input);

		clearScreen();

	}
	while (isRunning);
}

void controleerStringsVoorPalindromen(std::vector<std::string>& teTestenStrings, std::vector<bool>& testResultaten)
{
	// Bij elke controle worden alle strings opnieuw geëvalueerd. 
	//testResultaten.cls();

	for (auto pos1 = teTestenStrings.cbegin(); pos1 != teTestenStrings.cend(); ++pos1)
		testResultaten.push_back(isPalindroom(*pos1));

	if (teTestenStrings.size() != testResultaten.size())
		std::cout << "ERROR: 'teTestenStrings' != 'testResultaten'" << std::endl;
}

void printResultaat(std::vector<std::string>& teTestenStrings, std::vector<bool>& testResultaten)
{
	auto teller = 0;

	std::cout << std::left << std::setw(20) << "string" << "  |  " << std::setw(10) << "palindroom" << std::endl;

	for (const auto& teTestenString : teTestenStrings)
	{
		std::cout << std::left << std::setw(20) << teTestenString << "  |  " << std::setw(10) << testResultaten[teller] << std
			::endl;
		++teller;
	}
}

void clearScreen()
{
	// Vermijden van system("CLS") om programma compatibel te maken met andere OS.
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void save(std::vector<std::string> &teTestenStrings) // Dit programma maakt zelf het data - bestand niet aan!
{
	const std::string dataFile = "data.csv";

	std::ofstream outputStream(dataFile);
	if (outputStream.is_open())
	{
		for (const auto& teTestenString : teTestenStrings)
			outputStream << teTestenString << std::endl;
		outputStream.close();
	}
	else std::cout << "ERROR: Unable to open file '" << dataFile << "'";
}

void load(std::vector<std::string> &teTestenStrings)// Dit programma maakt zelf het data-bestand niet aan!
{
	const std::string dataFile = "data.csv";

	std::string line;
	std::ifstream inputStream(dataFile);
	if (inputStream.is_open())
	{
		while (std::getline(inputStream, line))
			teTestenStrings.push_back(line);
		inputStream.close();
	}

	else std::cout << "ERROR: Unable to open file '" << dataFile << "'";
}
