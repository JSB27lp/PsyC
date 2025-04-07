#pragma once
#include "raylib.h"
class LevelOne
{
private:
	Camera3D camera;
public:
	LevelOne();
	void process();
	void draw();
};

