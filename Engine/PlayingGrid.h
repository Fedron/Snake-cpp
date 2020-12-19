#pragma once
#include "Snake.h"

class PlayingGrid
{
public:
	PlayingGrid();
	~PlayingGrid();

	void Draw() const;

private:
	int gridWidth;
	int gridHeight;
	int* grid;

	Snake* snake;
};
