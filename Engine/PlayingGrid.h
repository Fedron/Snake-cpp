#pragma once
#include <cstdlib>
#include <ctime>

#include "Snake.h"

class PlayingGrid
{
public:
	PlayingGrid();
	~PlayingGrid();

	const bool IsGameOver() const {
		return gameOver;
	}
	const int GetScore() const {
		return score;
	}

	void MoveSnake(Location direction);
	void CheckCollisions();
	void Draw() const;

private:
	bool gameOver;

	int gridWidth;
	int gridHeight;
	int* grid;

	Snake* snake;
	Location apple;

	int score;
};
