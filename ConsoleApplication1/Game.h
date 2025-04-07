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


    bool doored;
    Door door;
    bool doored1;
    Door door1;

    Camera3D camera;
    Door doorend;


    std::vector<Step> stepArray;

    Texture2D eyeImg;
    std::vector<Eye> eyeArray;
    int i;

    Texture2D child;
    Texture2D childTxt;

public:
	Game();
	void process();
    void draw();

    bool endLvl = false;


};

