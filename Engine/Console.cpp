#include "Console.h"

Console::Console(std::string title)
{
	width = 120;
	height = 30;

	// Initialize handles
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);

	windowRect = { 0, 0, 1, 1 };
	SetConsoleWindowInfo(hConsole, TRUE, &windowRect);
	
	// Initialize the screen buffer and console window
	COORD coord = { (short)width, (short)height };
	SetConsoleScreenBufferSize(hConsole, coord);
	SetConsoleActiveScreenBuffer(hConsole);

	windowRect = { 0, 0, (short)width - 1, (short)height - 1 };
	SetConsoleWindowInfo(hConsole, TRUE, &windowRect);

	screen = new CHAR_INFO[width * height];
	memset(screen, 0, sizeof(CHAR_INFO) * width * height);
}

Console::~Console()
{
	delete[] screen;
	CloseHandle(hConsole);
}

void Console::Draw(int x, int y, short value)
{
	Draw(x, y, value, Colours::FG_WHITE);
}

void Console::Draw(int x, int y, short value, short colour)
{
	if (x >= 0 && x < width && y >= 0 && y <= height) {
		screen[y * width + x].Char.UnicodeChar = value;
		screen[y * width + x].Attributes = colour;
	}
}

void Console::Render()
{
	SetConsoleTitle(TEXT("Snake++"));
	WriteConsoleOutput(
		hConsole, screen,
		{ (short)width, (short)height }, { 0, 0 },
		&windowRect
	);
}
