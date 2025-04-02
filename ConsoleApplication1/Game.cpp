#include "Game.h"
#include "raylib.h"
#include <vector>
#include "Door.h"
#include "Eye.h"

Game::Game() :doored{ false }, i{ 0 },screenWidth{ 1920 }, screenHeight{1080} {
    InitWindow(screenWidth, screenHeight, "JSB");
    DisableCursor();
    SetTargetFPS(165);


    camera.position = { 10.0f, 10.0f, 10.0f }; // Camera position
    camera.target = { -16.0f, 4.0f, -16.0f };      // Camera looking at point
    camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 90;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    eyeImg = LoadTexture("resources/eye.jpg");
}

void Game::process() {
    if (i < 10000) {
        ++i;
        Eye eye{ eyeImg };
        eyeArray.push_back(eye);
    }

    UpdateCamera(&camera, CAMERA_FREE);

    doored = door.collide(camera);
}

void Game::draw() {
    BeginDrawing();

    ClearBackground(BLACK);
    if (doored)ClearBackground(WHITE);

    BeginMode3D(camera);

    door.draw();

    if (!doored) {
        DrawGrid(10, 1.0f);
        for (auto eye : eyeArray)
        {
            eye.draw(camera);
        }
    }
    else {
        DrawGrid(1000, 1.0f);
        DrawSphere({ -16.0f, 4.0f, -16.0f }, 1, BLACK);
    }

    EndMode3D();

    DrawText("Je Suis Bizarre. C'est sans doute � cause...", 10, 10, 12, WHITE);
    EndDrawing();
}