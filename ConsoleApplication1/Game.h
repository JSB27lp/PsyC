#pragma once
#include "Door.h"
#include "Eye.h"
#include "Step.h"
#include <vector>
#include "player.h"
class Game
{
private:
    const int screenWidth;
    const int screenHeight;

    Camera3D camera;
    Player player;

    bool doored;
    Door door;
    bool doored1;
    Door door1;

    std::vector<Step> stepArray;

    Texture2D eyeImg;
    std::vector<Eye> eyeArray;
    int i;

    void DrawCubeTexture(Texture2D texture, Vector3 position, float width, float height, float length, Color color); // Draw cube textured


public:
	Game();
	void process();
    void draw();


};

