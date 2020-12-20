#include <chrono>
using namespace std;

#include "Game.h"
#include "PlayingGrid.h"

int main()
{
    // Initialize the game and console
    Game* game = new Game();
    game->InitializeConsole(L"Snake++", 120, 30);

    // Initialize the snake game
    PlayingGrid* grid = new PlayingGrid();
    Location lastMoveDirection = { 1, 0 };

    while (true) {
        this_thread::sleep_for(200ms);
        Console& console = Console::GetInstance();

        // Inputs
        if (console.IsKeyPressed(VK_UP) && lastMoveDirection != Location{ 0, -1 }) {
            lastMoveDirection = { 0, -1 };
            grid->MoveSnake(lastMoveDirection);
        }

        if (console.IsKeyPressed(VK_LEFT) && lastMoveDirection != Location{ -1, 0 }) {
            lastMoveDirection = { -1, 0 };
            grid->MoveSnake(lastMoveDirection);
        }

        if (console.IsKeyPressed(VK_DOWN) && lastMoveDirection != Location{ 0, 1 }) {
            lastMoveDirection = { 0, 1 };
            grid->MoveSnake(lastMoveDirection);
        }

        if (console.IsKeyPressed(VK_RIGHT) && lastMoveDirection != Location{ 1, 0 }) {
            lastMoveDirection = { 1, 0 };
            grid->MoveSnake(lastMoveDirection);
        }

        // Game Logic
        grid->MoveSnake(lastMoveDirection);

        // Drawing
        grid->Draw();
        game->Render();
    }
}
