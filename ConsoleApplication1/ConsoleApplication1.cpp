#include "Game.h"
#include "LevelOne.h"

int main(void)
{
    InitWindow(1920, 1080, "JSB");
    DisableCursor();
    SetTargetFPS(165);

    Game game{};
    LevelOne levelone{};

    while (!WindowShouldClose()){
        if (!game.endLvl and 0) {
            game.process();
            game.draw();
        }
        else {
            levelone.process();
			levelone.draw();
        }
    }

    CloseWindow();   

    return 0;
}

