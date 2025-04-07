#include "Game.h"
#include "util.h"


Game::Game() :doored{ false }, doored1{ false }, i{ 0 }, screenWidth{ 1920 }, screenHeight{ 1080 }, door{WHITE,GRAY,{ 0.0f, 2.0f, 0.0f },false }, door1{ BLACK,GRAY,{ 0.0f, 2.0f, -25.0f },false } {
    InitWindow(screenWidth, screenHeight, "JSB");
    DisableCursor();
    SetTargetFPS(165);


    camera.position = { 10.0f, 10.0f, 10.0f }; // Camera position
    camera.target = { -16.0f, 4.0f, -16.0f };      // Camera looking at point
    camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 90;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    eyeImg = LoadTexture("resources/eye.jpg");


    child = LoadTexture("resources/child.jpg");
    childTxt = LoadTexture("resources/child_txt.jpg");

    for (int i{ 0 };i < 100;i++) {
        float s1 = static_cast<float>(rand() % 100 - 50);
        float s2 = static_cast<float>(rand() % 100 - 50);
        float s3 = static_cast<float>(rand() % 100 - 50);
        Step step{ BLACK, GRAY, { s1, s2, s3 }, false };
        stepArray.push_back(step);
    }

}

void Game::process() {
    if (i < 10000) {
        ++i;
        Eye eye{ eyeImg };
        eyeArray.push_back(eye);
    }

    UpdateCamera(&camera, CAMERA_FREE);
  


    if (!doored) {
        doored = door.collide(camera);
    }
    else {
        if (door1.collide(camera) && !doored1) {
            camera.position = { 10.0f, 10.0f, 10.0f }; // Camera position
            camera.target = { -16.0f, 4.0f, -16.0f };      // Camera looking at point
            doored = !doored;
            doored1 = true;
        }
    }
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

        DrawCubeTexture(eyeImg, { -2.0f, 0.5f, -0.0f }, 1.0f, 1.0f, 1.0f, WHITE);
        DrawCubeTexture(eyeImg, { 0.0f, 0.5f, -20.0f }, 1.0f, 1.0f, 1.0f, WHITE);
        if (!doored1) {
            door1.draw();
        }
        else {
            for (auto step : stepArray) {
                step.draw();
            }
            DrawCubeTexture(child, { 0.0f, 4.5f, -20.0f }, 3.0f, 3.0f, 3.0f, WHITE);
            DrawCubeTexture(childTxt, { 0.0f, 1.5f, -20.0f }, 3.0f, 3.0f, 3.0f, WHITE);
        }

        if (camera.position.y<1) {
            camera.position.y = 1;
        }

    }
    //voici le Premier problème psychologique

    

    EndMode3D();



    if (!doored1) {
        if (!doored) {
            DrawText("Je suis bizarre. C'est sans doute a cause...", 10, 10, 20, WHITE);
        }
        else {
            DrawText("A cause de quoi ?", 10, 10, 20, BLACK);
            DrawText("Quelle est l'origine de ma psychose ?", 10, 30, 20, BLACK);
        }
    }
    else {
        if (!doored) {
            DrawText("La cause originelle semble en rapport avec une experience passee...", 10, 10, 20, WHITE);
        }
    }




    EndDrawing();
}


