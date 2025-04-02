#pragma once
#include "Door.h"
#include "Eye.h"
#include <vector>
class Game
{
private:
    const int screenWidth;
    const int screenHeight;

    Camera3D camera;

    bool doored;
    Door door;

    Texture2D eyeImg;
    std::vector<Eye> eyeArray;
    int i;

public:
	Game();
	void init();
	void process();
};

