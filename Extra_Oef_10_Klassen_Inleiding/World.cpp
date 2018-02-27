#include "World.h"
#include <iostream>
#include <Windows.h>
#include <ctime>
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN

World::World(Pacman *wout, Pacman *kim, const int height, const int width)
{
	this->wout = wout;
	this->kim = kim;
	this->height = height;
	this->width = width;
	map.resize(width, std::vector<char>(height, ' '));
}

void World::update()
{
	map[wout->positie->y][wout->positie->x] = ' ';


	if (GetAsyncKeyState(VK_DOWN) && wout->positie->y < height -1)
			wout->positie->y++;

	else if (GetAsyncKeyState(VK_UP) && wout->positie->y > 0)
		wout->positie->y--;

	else if (GetAsyncKeyState(VK_RIGHT) && wout->positie->x < width - 1)
		wout->positie->x++;

	else if (GetAsyncKeyState(VK_LEFT) && wout->positie->x > 0)
		wout->positie->x--;

	map[wout->positie->y][wout->positie->x] = '#';
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
			std::cout << map[x][y];
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
		draw();

		const auto end = clock();

		if (double(end - begin) / CLOCKS_PER_SEC < 0.016)
			Sleep(256 - double(end - begin));

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
	static const HANDLE H_OUT = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	const COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	SetConsoleCursorPosition(H_OUT, coord);
}
