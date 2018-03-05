#include "Positie.h"

Positie::Positie(const int x, const int y, const int z): x(x),
                                                         y(y),
                                                         z(z)
{
}

int Positie::getX() const
{
	return x;
}

void Positie::setX(const int x)
{
	this->x = x;
}

int Positie::getY() const
{
	return y;
}

void Positie::setY(const int y)
{
	this->y = y;
}

int Positie::getZ() const
{
	return z;
}

void Positie::setZ(const int z)
{
	this->z = z;
}
