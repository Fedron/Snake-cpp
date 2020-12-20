#include <chrono>
using namespace std;

#include "Game.h"
#include "PlayingGrid.h"

int main()
{
    // Initialize the game and console
    Game* game = new Game();
    game->InitializeConsole(L"Snake++", 50, 15);

    // Initialize the snake game
    PlayingGrid* grid = new PlayingGrid();
    Location lastMoveDirection = { 1, 0 };

    while (!grid->IsGameOver()) {
        this_thread::sleep_for(150ms);
        Console& console = Console::GetInstance();

        // Inputs
        if (console.IsKeyPressed(VK_UP) && lastMoveDirection != Location{ 0, -1 }) {
            lastMoveDirection = { 0, -1 };
            grid->MoveSnake(lastMoveDirection);
        }
        else if (console.IsKeyPressed(VK_LEFT) && lastMoveDirection != Location{ -1, 0 }) {
            lastMoveDirection = { -1, 0 };
            grid->MoveSnake(lastMoveDirection);
        }
        else if (console.IsKeyPressed(VK_DOWN) && lastMoveDirection != Location{ 0, 1 }) {
            lastMoveDirection = { 0, 1 };
            grid->MoveSnake(lastMoveDirection);
        }
        else if (console.IsKeyPressed(VK_RIGHT) && lastMoveDirection != Location{ 1, 0 }) {
            lastMoveDirection = { 1, 0 };
            grid->MoveSnake(lastMoveDirection);
        }
        else {
            grid->MoveSnake(lastMoveDirection);
        }

        // Game Logic  
        grid->CheckCollisions();

        // Drawing
        grid->Draw();
        game->Render();

        wchar_t score[10];
        swprintf_s(score, L"Score: %d", grid->GetScore());
        console.Draw(console.GetWidth() - 15, console.GetHeight() / 2,
            score);
    }

    wchar_t scoreGameOver[20];
    swprintf_s(scoreGameOver, L"You scored: %d!", grid->GetScore());
    while (true) {
        Console& console = Console::GetInstance();
        console.Draw(
            console.GetWidth() / 2 - 4, console.GetHeight() / 2 - 1,
            L"Game Over!");
        console.Draw(
            console.GetWidth() / 2 - 6, console.GetHeight() / 2,
            scoreGameOver);

        console.Render();
    }
}
