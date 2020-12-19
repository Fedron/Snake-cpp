#pragma once
#include <thread>

#include "Console.h"

class Game
{
public:
	void InitializeConsole(std::wstring windowTitle, int width, int height);

	// Drawing
	void Draw(int x, int y, short value);
	void Draw(int x, int y, short value, short colour);
	void Render();
};
