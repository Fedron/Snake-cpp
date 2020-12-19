#include <iostream>
#include "Game.h"

int main()
{
    Game* game = new Game();
    for (int x = 0; x < 90; x++) {
        for (int y = 5; y < 21; y++) {
            game->Draw(x, y, L'#', Colours::FG_BLUE);
        }
    }

    while (true) {
        game->Render();
    }
}
