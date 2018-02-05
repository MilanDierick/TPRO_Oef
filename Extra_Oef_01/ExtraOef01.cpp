// ExtraOef01.cpp : Defines the entry point for the console application
//

#include "stdafx.h"
#include <iostream>

double gemiddelde(double x, double y, double z);
void grootste_getal(double x, double y, double z);

int main()
{
	double x, y, z;

	std::cout << "Geef 3 getallen waarvan het programma het gemiddelde moet berekenen: " << std::endl;
	std::cin >> x;
	std::cin >> y;
	std::cin >> z;

	std::cout << "Het gemiddelde is: " << gemiddelde(x, y, z) << std::endl;
	grootste_getal(x, y, z);

	system("PAUSE");
    return 0;
}

double gemiddelde(double x, double y, double z)
{
	return ((x + y + z) / 3);
}

void grootste_getal(double x, double y, double z)
{
	if (x >= y && x >= z)
	{
		std::cout << x << " is het grootste getal." << std::endl;
	}
	else if (y >= x && y >= z)
	{
		std::cout << y << " is het grootste getal." << std::endl;
	}
	else
	{
		std::cout << z << " is het grootste getal." << std::endl;
	}
}
