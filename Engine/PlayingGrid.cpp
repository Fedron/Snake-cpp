#include "PlayingGrid.h"

PlayingGrid::PlayingGrid()
{
	gameOver = false;

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

	// Initialize the snake and apple
	snake = new Snake({ gridWidth / 2, gridHeight / 2 }, 4);

	srand(time(0));
	apple = {
		(rand() % (gridWidth - 2)) + 1,
		(rand() % (gridHeight - 2)) + 1
	};
}

PlayingGrid::~PlayingGrid()
{
	delete[] grid;
}

void PlayingGrid::MoveSnake(Location direction)
{
	if (abs(direction.x) == 1 || direction.x == 0 ||
		abs(direction.y) == 1 || direction.y == 0) {
		snake->Move(direction);
	}
}

void PlayingGrid::CheckCollisions()
{
	Location headLocation = snake->GetHeadLocation();

	// Check for collision between apple and snake
	if (headLocation == apple) {
		snake->Grow();
		apple = {
			(rand() % (gridWidth - 2)) + 1,
			(rand() % (gridHeight - 2)) + 1
		};
	}

	// Snake collisions with itself and the walls
	if (headLocation.x == 0 || headLocation.x == gridWidth - 1 ||
		headLocation.y == 0 || headLocation.y == gridHeight - 1) {
		gameOver = true;
	}
	
	if (snake->IsCollidingWithSelf())
		gameOver = true;
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

	Console::GetInstance().Draw(apple.x, apple.y, L'\u25cf', Colours::FG_RED);
	snake->Draw();
}
