#include "PlayingGrid.h"

PlayingGrid::PlayingGrid()
{
	gridWidth = (Console::GetInstance().GetWidth() - 20);
	gridHeight = Console::GetInstance().GetHeight();

	grid = new int[gridWidth * gridHeight];
	memset(grid, 0, sizeof(int) * gridWidth * gridHeight);

	// Set the borders of the grid to walls
	for (int x = 0; x < gridWidth; x++) {
		for (int y = 0; y < gridHeight; y++) {
			if (x == 0 || x == gridWidth - 1 || y == 0 || y == gridHeight - 1)
				grid[y * gridWidth + x] = 1;
		}
	}

	// Initialize the snake
	snake = new Snake({ gridWidth / 2, gridHeight / 2 }, 4);
}

PlayingGrid::~PlayingGrid()
{
	delete[] grid;
}

void PlayingGrid::Draw() const
{
	// Draw the walls
	for (int x = 0; x < gridWidth; x++) {
		for (int y = 0; y < gridHeight; y++) {
			if (grid[y * gridWidth + x] == 1)
				Console::GetInstance().Draw(x, y, L'\u2588', Colours::FG_DARK_GREY);
		}
	}

	snake->Draw();
}
