// ExtraOef06Pointers.cpp : Defines the entry point for the console application.
//

#include <iostream>
void manipulateVariable(int* getal);
void incrementOne(int* getal);
void multiplyByOne(int* getal);

int main()
{
	int getal = 4;
	int* pointerNaarGetal = &getal;

	manipulateVariable(pointerNaarGetal);
	std::cout << getal << std::endl;

	system("PAUSE");
    return 0;
}

void incrementOne(int* pointerNaarGetal)
{
	*pointerNaarGetal += 1;
}

void multiplyByOne(int* pointerNaarGetal)
{
	*pointerNaarGetal *= 2;
}

void manipulateVariable(int* pointerNaarGetal)
{
	incrementOne(pointerNaarGetal);
	multiplyByOne(pointerNaarGetal);
}

