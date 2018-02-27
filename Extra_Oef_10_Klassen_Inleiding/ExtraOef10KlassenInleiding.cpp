// ExtraOef10KlassenInleiding.cpp : Defines the entry point for the console application.
//

#include "World.h"

int main()
{
	auto world = new World(new Pacman(1, 3, new Positie()), new Pacman(1, 3, new Positie()), 30, 30);

	world->run();

	delete world;
	return 0;
}



