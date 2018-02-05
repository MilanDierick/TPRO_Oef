// Pointers.cpp : Defines the entry point for the console application.
//


#include <iostream>

int main()
{
	int a[4] = { 10,15,20,25 };
	int *q = a;

	int b = 20;
	int *p = &b;
	p++;
	p--;
	std::cout << *p++ << std::endl;
	std::cout << *p-- << std::endl;
	std::cout << *p << std::endl;
	std::cout << (*p)++ << std::endl << std::endl;
	std::cout << *p << std::endl;

	std::cout << std::endl << std::endl;

	// *p | p++
	for (int i = 0; i < 4; i++)
	{
		std::cout << *q << std::endl;
		q++;
	}

	q = a;
	std::cout << std::endl;

	// *p | ++p
	for (int i = 0; i < 4; i++)
	{
		std::cout << *q << std::endl;
		++q;
	}

	q = a;
	std::cout << std::endl;

	// p | p++
	for (int i = 0; i < 4; i++)
	{
		std::cout << q << std::endl;
		q++;
	}

	q = a;
	std::cout << std::endl;

	// p | ++p
	for (int i = 0; i < 4; i++)
	{
		std::cout << q << std::endl;
		++q;
	}

	q = a;
	std::cout << std::endl;

	// &p | p++
	for (int i = 0; i < 4; i++)
	{
		std::cout << &q << std::endl;
		q++;
	}

	q = a;
	std::cout << std::endl;

	// &p | ++p
	for (int i = 0; i < 4; i++)
	{
		std::cout << &q << std::endl;
		++q;
	}

	q = a;
	std::cout << std::endl;

	system("PAUSE");
    return 0;
}

