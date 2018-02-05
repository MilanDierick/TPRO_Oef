// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>

#define LENGTH 6

int main()
{
	int getallen_reeks[LENGTH] = { 8,2,4,3,11,1 };
	auto kleinste_getal = 0;

	std::sort(getallen_reeks, getallen_reeks + LENGTH);
	kleinste_getal = getallen_reeks[0];
	 
    return 0;
}

