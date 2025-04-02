#pragma once
#include "raylib.h"

class Door
{
private:
	Vector3 cubePosition = { 0.0f, 2.0f, 0.0f };
	float largeur = 2.0f, hauteur = 4.0f, profondeur = 0.5f;
	Color color = WHITE;
	Color colorBorder = GRAY;

public:
	void draw();
	bool collide(Camera3D camera);
};

