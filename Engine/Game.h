#pragma once
#include <thread>

#include "Console.h"

class Game
{
public:
	Game();
	virtual ~Game();

	void Draw(int x, int y, short value);
	void Draw(int x, int y, short value, short colour);
	void Render();

private:
	Console* console;
};
