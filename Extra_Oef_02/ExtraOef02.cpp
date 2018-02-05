// ExtraOef02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void input(double &a, double &b, double &c);
void discriminant();
double calc_discriminant(const double a, const double b, const double c);
void output_discrimant(const double D, const double x_pos, const double x_neg, const bool isNegative, const bool isNull);
double pos_x_value(const double a, const double b, const double D);
double neg_x_value(const double a, const double b, const double D);

int main()
{
	discriminant();

    return 0;
}

void input(double &a, double &b, double &c)
{
	std::cout << "Geef de waarde voor a: " << std::endl;
	std::cin >> a;

	std::cout << "Geef de waarde voor b: " << std::endl;
	std::cin >> b;
	
	std::cout << "Geef de waarde voor c: " << std::endl;
	std::cin >> c;
	
	return;
}

void discriminant()
{
	bool isNegative = false, isNull = false;
	double a, b, c, D, x_pos, x_neg;

	input(a, b, c);
	D = calc_discriminant(a, b, c);

	if (D > 0)
	{
		x_pos = pos_x_value(a, b, D);
		x_neg = neg_x_value(a, b, D);
	} 
	else if (D == 0)
	{
		x_pos = pos_x_value(a, b, D);
		isNull = true;
	}
	else
	{
		isNegative = true;
	}

	output_discrimant(D, x_pos, x_neg, isNegative, isNull);
}

double calc_discriminant(const double a, const double b, const double c)
{
	return (pow(b, 2) - (4 * a * c));
}

void output_discrimant(const double D, const double x_pos, const double x_neg, const bool isNegative, const bool isNull)
{
	std::cout << "De discriminant is gelijk aan: " << D << std::endl;

	if (isNegative)
	{
		std::cout << "Er zijn geen oplossingen." << std::endl;
	}
	else if (isNull)
	{
		std::cout << "X is gelijk aan: " << x_pos << std::endl;
	}
	else
	{
		std::cout << "X1 is gelijk aan: " << x_pos << std::endl;
		std::cout << "X2 is gelijk aan: " << x_neg << std::endl;
	}
}

double pos_x_value(const double a, const double b, const double D)
{
	return (-b + sqrt(D) / (2 * a));
}

double neg_x_value(const double a, const double b, const double D)
{
	return (-b - sqrt(D) / (2 * a));
}
