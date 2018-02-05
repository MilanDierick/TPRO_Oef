// ExtraOef07Strings.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>

std::string vraagVoornaam();
std::string vraagFamilienaam();
std::string vraagStraat();
int vraagHuisnummer();
std::string vraagGemeente();
int vraagPostcode();

int main()
{
	auto voornaam = vraagVoornaam();
	auto familienaam = vraagFamilienaam();
	auto straat = vraagStraat();
	auto gemeente = vraagGemeente();
	auto huisnummer = vraagHuisnummer();
	auto postcode = vraagPostcode();


	std::cin.get();
    return 0;
}

std::string vraagVoornaam()
{
	std::string tmp;

	std::cout << "Geef je voornaam: ";
	std::getline(std::cin, tmp);
	return tmp;
}

std::string vraagFamilienaam()
{
	std::string tmp;

	std::cout << "Geef je familienaam: ";
	std::getline(std::cin, tmp);
	return tmp;
}

std::string vraagStraat()
{
	std::string tmp;

	std::cout << "In welke straat woon je? ";
	std::getline(std::cin, tmp);
	return tmp;
}

int vraagHuisnummer()
{
	int tmp;

	std::cout << "Geef je huisnummer: ";
	std::cin >> tmp;
	return tmp;
}

std::string vraagGemeente()
{
	std::string tmp;

	std::cout << "Geef je gemeente: ";
	std::getline(std::cin, tmp);
	return tmp;
}

int vraagPostcode()
{
	int tmp;

	std::cout << "Geef je postcode: ";
	std::cin >> tmp;
	return tmp;
}