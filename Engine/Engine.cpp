#include "Game.h"
#include "PlayingGrid.h"

int main()
{
    // Initialize the game and console
    Game* game = new Game();
    game->InitializeConsole(L"Snake++", 120, 30);

    // Initialize the snake game
    PlayingGrid* grid = new PlayingGrid();

    while (true) {
        grid->Draw();
        game->Render();
    }
}
