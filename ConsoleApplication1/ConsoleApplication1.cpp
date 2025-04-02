#include "raylib.h"
#include <vector>
#include "Game.h"


int main(void)
{
    Game game{};
    game.init();

    while (!WindowShouldClose())       
    {
        game.process();
    }

    CloseWindow();   

    return 0;
}

