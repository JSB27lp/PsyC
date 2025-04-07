#include "LevelOne.h"


LevelOne::LevelOne() {
    camera.position = { 10.0f, 10.0f, 10.0f }; // Camera position
    camera.target = { -16.0f, 4.0f, -16.0f };      // Camera looking at point
    camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 90;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type
}

void LevelOne::process() {
    UpdateCamera(&camera, CAMERA_FREE);
}

void LevelOne::draw() {
    BeginDrawing();

    ClearBackground(GREEN);

    BeginMode3D(camera);

        DrawGrid(10000, 1.0f);

    EndMode3D();

    DrawText("Il a bien fallu trouver un moyen de s'echapper mentalement", 10, 10, 20, WHITE);

    EndDrawing();
}
