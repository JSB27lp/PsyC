/*******************************************************************************************
*
*   raylib [core] example - Initialize 3d camera free
*
*   Example complexity rating: [★☆☆☆] 1/4
*
*   Example originally created with raylib 1.3, last time updated with raylib 1.3
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2015-2025 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <vector>

#include "Door.h"
#include "Eye.h"


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "JSB");

    // Define the camera to look into our 3d world
    Camera3D camera = { 0 };
    camera.position = { 10.0f, 10.0f, 10.0f }; // Camera position
    camera.target = { 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    DisableCursor();                    // Limit cursor to relative movement inside the window

    SetTargetFPS(165);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    
    bool doored = false;
    Door door;

    Texture2D eyeImg = LoadTexture("resources/eye.jpg");
    std::vector<Eye> eyeArray;
    int i{0};

    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        if (i<10000) {
            ++i;
            Eye eye{ eyeImg };
            eyeArray.push_back(eye);
        }

        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera, CAMERA_FREE);

        doored = door.collide(camera);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);
        if (doored)ClearBackground(WHITE);

        BeginMode3D(camera);

            door.display();

            if (!doored) {
                DrawGrid(10, 1.0f); 
                for (auto eye : eyeArray)
                {
                    eye.display(camera);
                }
            }
            else { 
                DrawGrid(1000, 1.0f);
                DrawSphere({ -16.0f, 4.0f, -16.0f }, 1, BLACK);
            }

        EndMode3D();

        DrawText("Je Suis Bizarre. C'est sans doute à cause...", screenWidth/2, screenHeight -10, 12, WHITE);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

