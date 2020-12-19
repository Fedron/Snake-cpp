#include "Game.h"

Game::Game()
{
	console = new Console("Snake++");
}

Game::~Game()
{
}

void Game::Draw(int x, int y, short value)
{
	console->Draw(x, y, value);
}

void Game::Draw(int x, int y, short value, short colour)
{
	console->Draw(x, y, value, colour);
}

void Game::Render()
{
	console->Render();
}
