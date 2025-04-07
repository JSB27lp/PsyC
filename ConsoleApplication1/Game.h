#pragma once
#include "Door.h"
#include "Eye.h"
#include "Step.h"
#include <vector>


class Game
{
private:
    const int screenWidth;
    const int screenHeight;

    Camera3D camera;

    bool doored;
    Door door;
    bool doored1;
    Door door1;

    std::vector<Step> stepArray;

    Texture2D eyeImg;
    std::vector<Eye> eyeArray;
    int i;



public:
	Game();
	void process();
    void draw();


};

