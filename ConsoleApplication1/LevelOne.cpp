#include "LevelOne.h"
#include "raylib.h"


void LevelOne::draw() {
    BeginDrawing();

    ClearBackground(GREEN);

    //BeginMode3D(camera);

    //EndMode3D();

    DrawText("Il a bien fallu trouver un moyen de s'echapper mentalement", 10, 10, 20, WHITE);

    EndDrawing();
}