#pragma once
#include "raylib.h"
#include "CubeWithTexture.h"
class LevelOne
{
private:
	Camera3D camera;
	CubeWithTexture cuby;
	Texture2D textury = LoadTexture("resources/hgfdh4.png");
public:
	LevelOne();
	void process();
	void draw();
};

