#pragma once
#include "Snake.h"

class PlayingGrid
{
public:
	PlayingGrid();
	~PlayingGrid();

	void MoveSnake(Location direction);
	void Draw() const;

private:
	int gridWidth;
	int gridHeight;
	int* grid;

	Snake* snake;
};
