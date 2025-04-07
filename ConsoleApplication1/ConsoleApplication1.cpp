#include "Game.h"


int main(void)
{
    Game game{};

    while (!WindowShouldClose()){
        game.process();
        game.draw();
    }

    CloseWindow();   

    return 0;
}

