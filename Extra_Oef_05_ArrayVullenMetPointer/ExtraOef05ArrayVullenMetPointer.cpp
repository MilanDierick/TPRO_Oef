// Milan Dierick | 5IT | 07
// VTI Lokeren | 10/01/2018
// ExtraOef05ArrayVullenMetPointer.cpp : Defines the entry point for the console application.
//

#include <iostream>
int* print(int* p, const int getal);

#define AANTAL 21

int main()
{
	int lijst[AANTAL] = {0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100};
	const int getal = 20;
	int* ptr = print(lijst, getal);

	if (ptr != nullptr)
	{
		std::cout << "Het adres van het getal " << getal << " is: " << ptr << std::endl;
		std::cout << "De index van het getal is: " << ptr - lijst << "." << std::endl;
	}
	else
	{
		std::cout << "Het getal komt niet voor!" << std::endl;
	}

	print(lijst, getal);

	system("PAUSE");
	return 0;
}

int* print(int* p, const int getal)
{
	for (int i = 0; i < AANTAL; i++)
	{
		if (*p == getal)
			return p;
		p++;
	}
	return nullptr;
}
