#include "Console.h"

Console::~Console()
{
	delete[] screen;
	CloseHandle(hConsole);
}

void Console::Initialize(std::wstring windowTitle, int width, int height)
{
	this->width = width;
	this->height = height;
	this->windowTitle = windowTitle;

	// Initialize handles
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);

	windowRect = { 0, 0, 1, 1 };
	SetConsoleWindowInfo(hConsole, TRUE, &windowRect);
	SetConsoleMode(hConsoleInput, ENABLE_EXTENDED_FLAGS | ~ENABLE_QUICK_EDIT_MODE);

	// Initialize the screen buffer and console window
	COORD coord = { (short)width, (short)height };
	SetConsoleScreenBufferSize(hConsole, coord);
	SetConsoleActiveScreenBuffer(hConsole);

	windowRect = { 0, 0, (short)width - 1, (short)height - 1 };
	SetConsoleWindowInfo(hConsole, TRUE, &windowRect);

	screen = new CHAR_INFO[width * height];
	memset(screen, 0, sizeof(CHAR_INFO) * width * height);
}

const int Console::GetWidth() const
{
	return width;
}

const int Console::GetHeight() const
{
	return height;
}

const bool Console::IsKeyPressed(const int key)
{
	// TODO: Implement key debouncing
	int state = GetAsyncKeyState(key);
	return state != 0;
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

void Console::Draw(int x, int y, std::wstring text)
{
	Draw(x, y, text, Colours::FG_WHITE);
}

void Console::Draw(int x, int y, std::wstring text, short colour)
{
	for (int i = 0; i < text.size(); i++) {
		Draw(x + i, y, text[i], colour);
	}
}

void Console::Render()
{
	SetConsoleTitle(windowTitle.c_str());
	WriteConsoleOutput(
		hConsole, screen,
		{ (short)width, (short)height }, { 0, 0 },
		&windowRect
	);

	memset(screen, 0, sizeof(CHAR_INFO) * width * height);
}
