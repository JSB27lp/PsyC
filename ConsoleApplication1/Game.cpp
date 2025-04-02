#include "Game.h"
#include "raylib.h"
#include "rlgl.h" 
#include <vector>
#include "Door.h"
#include "Eye.h"

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
        if (door1.collide(camera)) {
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
        }

        if (camera.position.y<1) {
            camera.position.y = 1;
        }

        if (doored1) {
            if (camera.position.y > 1) {
                camera.position.y = 1;
            }
        }
    }
    //voici le Premier problème psychologique

    

    EndMode3D();



    if (!doored1) {
        if (!doored) {
            DrawText("Je suis bizarre. C'est sans doute a cause...", 10, 10, 20, WHITE);
        }
        else {
            DrawText("A cause de quoi ? Quelle est l'origine de votre psychose ?", 10, 10, 20, BLACK);
        }
    }
    else {
        if (!doored) {
            DrawText("La cause originelle semble en rapport avec une experience passee...", 10, 10, 20, WHITE);
        }
        else {
            DrawText("Montrez-moi !", 10, 10, 20, BLACK);
        }
    }




    EndDrawing();
}

// Draw cube textured
// NOTE: Cube position is the center position
void Game::DrawCubeTexture(Texture2D texture, Vector3 position, float width, float height, float length, Color color)
{
    float x = position.x;
    float y = position.y;
    float z = position.z;

    // Set desired texture to be enabled while drawing following vertex data
    rlSetTexture(texture.id);

    // Vertex data transformation can be defined with the commented lines,
    // but in this example we calculate the transformed vertex data directly when calling rlVertex3f()
    //rlPushMatrix();
        // NOTE: Transformation is applied in inverse order (scale -> rotate -> translate)
        //rlTranslatef(2.0f, 0.0f, 0.0f);
        //rlRotatef(45, 0, 1, 0);
        //rlScalef(2.0f, 2.0f, 2.0f);

    rlBegin(RL_QUADS);
    rlColor4ub(color.r, color.g, color.b, color.a);
    // Front Face
    rlNormal3f(0.0f, 0.0f, 1.0f);       // Normal Pointing Towards Viewer
    rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x - width / 2, y - height / 2, z + length / 2);  // Bottom Left Of The Texture and Quad
    rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x + width / 2, y - height / 2, z + length / 2);  // Bottom Right Of The Texture and Quad
    rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x + width / 2, y + height / 2, z + length / 2);  // Top Right Of The Texture and Quad
    rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x - width / 2, y + height / 2, z + length / 2);  // Top Left Of The Texture and Quad
    // Back Face
    rlNormal3f(0.0f, 0.0f, -1.0f);     // Normal Pointing Away From Viewer
    rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x - width / 2, y - height / 2, z - length / 2);  // Bottom Right Of The Texture and Quad
    rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x - width / 2, y + height / 2, z - length / 2);  // Top Right Of The Texture and Quad
    rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x + width / 2, y + height / 2, z - length / 2);  // Top Left Of The Texture and Quad
    rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x + width / 2, y - height / 2, z - length / 2);  // Bottom Left Of The Texture and Quad
    // Top Face
    rlNormal3f(0.0f, 1.0f, 0.0f);       // Normal Pointing Up
    rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x - width / 2, y + height / 2, z - length / 2);  // Top Left Of The Texture and Quad
    rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x - width / 2, y + height / 2, z + length / 2);  // Bottom Left Of The Texture and Quad
    rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x + width / 2, y + height / 2, z + length / 2);  // Bottom Right Of The Texture and Quad
    rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x + width / 2, y + height / 2, z - length / 2);  // Top Right Of The Texture and Quad
    // Bottom Face
    rlNormal3f(0.0f, -1.0f, 0.0f);     // Normal Pointing Down
    rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x - width / 2, y - height / 2, z - length / 2);  // Top Right Of The Texture and Quad
    rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x + width / 2, y - height / 2, z - length / 2);  // Top Left Of The Texture and Quad
    rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x + width / 2, y - height / 2, z + length / 2);  // Bottom Left Of The Texture and Quad
    rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x - width / 2, y - height / 2, z + length / 2);  // Bottom Right Of The Texture and Quad
    // Right face
    rlNormal3f(1.0f, 0.0f, 0.0f);       // Normal Pointing Right
    rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x + width / 2, y - height / 2, z - length / 2);  // Bottom Right Of The Texture and Quad
    rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x + width / 2, y + height / 2, z - length / 2);  // Top Right Of The Texture and Quad
    rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x + width / 2, y + height / 2, z + length / 2);  // Top Left Of The Texture and Quad
    rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x + width / 2, y - height / 2, z + length / 2);  // Bottom Left Of The Texture and Quad
    // Left Face
    rlNormal3f(-1.0f, 0.0f, 0.0f);    // Normal Pointing Left
    rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x - width / 2, y - height / 2, z - length / 2);  // Bottom Left Of The Texture and Quad
    rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x - width / 2, y - height / 2, z + length / 2);  // Bottom Right Of The Texture and Quad
    rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x - width / 2, y + height / 2, z + length / 2);  // Top Right Of The Texture and Quad
    rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x - width / 2, y + height / 2, z - length / 2);  // Top Left Of The Texture and Quad
    rlEnd();
    //rlPopMatrix();

    rlSetTexture(0);
}
