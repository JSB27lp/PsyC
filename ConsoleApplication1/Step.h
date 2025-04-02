#pragma once
#include "raylib.h"

class Step
{
private:
	Vector3 cubePosition;
	float largeur = 4.0f, hauteur = 1.0f, profondeur = 1.0f;
	Color color_;
	Color colorBorder_;
	bool empty_;

public:
	Step(Color color, Color colorBorder, Vector3 position, bool empty);
	void draw();
	bool collide(Camera3D camera);
};


