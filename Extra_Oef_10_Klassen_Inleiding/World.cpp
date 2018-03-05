#include "World.h"
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <chrono>
#include <thread>

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#define SLEEP_TIME_DEFAULT 256
#define SLEEP_UPDATE_INTERVAL 1
#define WORLD_CHARACTER_FILL '0'
#define WORLD_CHARACTER_PLAYER '1'

World::World(Pacman *wout, Pacman *kim, const int height, const int width)
{
	this->pacman1 = wout;
	this->height = height;
	this->width = width;
	map.resize(width, std::vector<char>(height, WORLD_CHARACTER_FILL));
}

void World::update()
{
	if (GetAsyncKeyState(VK_DOWN) && pacman1->getPositie()->getY() < height -1)
	{
		map[pacman1->getPositie()->getY()][pacman1->getPositie()->getX()] = WORLD_CHARACTER_FILL;
		pacman1->getPositie()->setY(pacman1->getPositie()->getY() + 1);
		map[pacman1->getPositie()->getY()][pacman1->getPositie()->getX()] = WORLD_CHARACTER_PLAYER;
		draw();
	}

	else if (GetAsyncKeyState(VK_UP) && pacman1->getPositie()->getY() > 0)
	{
		map[pacman1->getPositie()->getY()][pacman1->getPositie()->getX()] = WORLD_CHARACTER_FILL;
		pacman1->getPositie()->setY(pacman1->getPositie()->getY() - 1);
		map[pacman1->getPositie()->getY()][pacman1->getPositie()->getX()] = WORLD_CHARACTER_PLAYER;
		draw();
	}

	else if (GetAsyncKeyState(VK_RIGHT) && pacman1->getPositie()->getX() < width - 1)
	{
		map[pacman1->getPositie()->getY()][pacman1->getPositie()->getX()] = WORLD_CHARACTER_FILL;
		pacman1->getPositie()->setX(pacman1->getPositie()->getX() + 1);
		map[pacman1->getPositie()->getY()][pacman1->getPositie()->getX()] = WORLD_CHARACTER_PLAYER;
		draw();
	}

	else if (GetAsyncKeyState(VK_LEFT) && pacman1->getPositie()->getX() > 0)
	{
		map[pacman1->getPositie()->getY()][pacman1->getPositie()->getX()] = WORLD_CHARACTER_FILL;
		pacman1->getPositie()->setX(pacman1->getPositie()->getX() - 1);
		map[pacman1->getPositie()->getY()][pacman1->getPositie()->getX()] = WORLD_CHARACTER_PLAYER;
		draw();
	}
}

void World::cls()
{
	// Get the Win32 handle representing standard output.
	// This generally only has to be done once, so we make it static.
	static const auto H_OUT = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	const COORD topLeft = {0, 0};

	// std::cout uses a buffer to batch writes to the underlying console.
	// We need to flush that to the console because we're circumventing
	// std::cout entirely; after we clear the console, we don't want
	// stale buffered text to randomly be written out.
	std::cout.flush();

	// Figure out the current width and height of the console window
	if (!GetConsoleScreenBufferInfo(H_OUT, &csbi))
	{
		// TODO: Handle failure!
		abort();
	}
	const DWORD length = csbi.dwSize.X * csbi.dwSize.Y;

	DWORD written;

	// Flood-fill the console with spaces to clear it
	FillConsoleOutputCharacter(H_OUT, TEXT(' '), length, topLeft, &written);

	// Reset the attributes of every character to the default.
	// This clears all background colour formatting, if any.
	FillConsoleOutputAttribute(H_OUT, csbi.wAttributes, length, topLeft, &written);

	// Move the cursor back to the top left for the next sequence of writes
	SetConsoleCursorPosition(H_OUT, topLeft);
}

void World::draw() const
{
	setCursorPosition(0, 0);
	for (auto x = 0; x < height; ++x)
	{
		for (auto y = 0; y < width; ++y)
		{
			std::cout << map[x][y];
			//std::this_thread::sleep_for(std::chrono::microseconds(SLEEP_UPDATE_INTERVAL));
		}
		std::cout << std::endl;
	}
}

void World::run()
{
	auto isRunning = true;
	
	do
	{
		using namespace std;
		const auto begin = clock();

		//cls();
		update();
		//draw();

		const auto end = clock();
		
		if (double(end - begin) < 16)
			Sleep(16 - double(end - begin));
			
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			system("CLS");
			std::cout << "Exiting the game..." << std::endl;
			isRunning = false;
		}
	}
	while (isRunning);
}

// x is the column, y is the row. The origin (0,0) is top-left.
void World::setCursorPosition(const int x, const int y)
{
	static const auto H_OUT = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	const COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	SetConsoleCursorPosition(H_OUT, coord);
}

Pacman* World::getPacman1() const
{
	return pacman1;
}

void World::setPacman1(Pacman* const pacman1)
{
	this->pacman1 = pacman1;
}

int World::getHeight() const
{
	return height;
}

void World::setHeight(const int height)
{
	this->height = height;
}

int World::getWidth() const
{
	return width;
}

void World::setWidth(const int width)
{
	this->width = width;
}

std::vector<std::vector<char>> World::getMap() const
{
	return map;
}

void World::setMap(const std::vector<std::vector<char>>& map)
{
	this->map = map;
}
