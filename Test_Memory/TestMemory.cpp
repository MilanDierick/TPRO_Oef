// TestMemory.cpp : Defines the entry point for the console application.
//

#include <iostream>

int main()
{
	for (auto i = 0; ; i++)
	{
		auto pointer = new double[4096];
		std::cout << i << std::endl;
	}

    return 0;
}

