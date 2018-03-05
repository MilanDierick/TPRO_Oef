#pragma once

class Positie
{
public:
	// http://en.cppreference.com/w/cpp/language/converting_constructor
	explicit Positie(const int x = 0, const int y = 0, const int z = 0);
	int getX() const;
	void setX(const int x);
	int getY() const;
	void setY(const int y);
	int getZ() const;
	void setZ(const int z);

private:
	int x;
	int y;
	int z;
};
