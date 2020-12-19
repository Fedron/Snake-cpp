#include "Game.h"

void Game::InitializeConsole(std::wstring windowTitle, int width, int height)
{
	Console::GetInstance().Initialize(windowTitle, width, height);
}

void Game::Draw(int x, int y, short value)
{
	Console::GetInstance().Draw(x, y, value);
}

void Game::Draw(int x, int y, short value, short colour)
{
	Console::GetInstance().Draw(x, y, value, colour);
}

void Game::Render()
{
	Console::GetInstance().Render();
}
