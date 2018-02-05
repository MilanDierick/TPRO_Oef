// Valkuilensubroutines.cpp : Defines the entry point for the console application.
//

#include <iostream>
void bar(int &teller);
void foo(int &teller);


int main()
{
	int teller = 0;

	bar(teller);
	std::cin.get();
    return 0;
}

void bar(int &teller)
{
	foo(teller);
}

void foo(int &teller)
{
	std::cout << teller << std::endl;
	teller++;
	if (teller < 10)
	{
		foo(teller);
	}
}
