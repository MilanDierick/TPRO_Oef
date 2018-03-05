#pragma once
#include "Pacman.h"
#include <vector>

class World
{
public:
	World(Pacman *wout, Pacman *kim, int height, int width);
	void update();
	static void cls();
	void draw() const;
	void run();
	static void setCursorPosition(int x, int y);

	Pacman* getPacman1() const;
	void setPacman1(Pacman* const pacman1);
	int getHeight() const;
	void setHeight(const int height);
	int getWidth() const;
	void setWidth(const int width);
	std::vector<std::vector<char>> getMap() const;
	void setMap(const std::vector<std::vector<char>>& map);
	
private:
	Pacman *pacman1;
	int height;
	int width;
	std::vector<std::vector<char>> map;
};
