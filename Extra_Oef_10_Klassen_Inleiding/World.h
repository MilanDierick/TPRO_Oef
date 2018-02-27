#pragma once
#include "Pacman.h"
#include <vector>

class World
{
public:
	Pacman *wout;
	Pacman *kim; // Not used at the moment
	int height;
	int width;
	std::vector<std::vector<char>> map;

	World(Pacman *wout, Pacman *kim, int height, int width);
	void update();
	static void cls();
	void draw() const;
	void run();
	static void setCursorPosition(int x, int y);
};
