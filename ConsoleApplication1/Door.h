#pragma once
#include "raylib.h"

class Door
{
private:
	Vector3 cubePosition;
	float largeur = 2.0f, hauteur = 4.0f, profondeur = 0.5f;
	Color color_;
	Color colorBorder_;
	bool empty_;

public:
	Door(Color color, Color colorBorder, Vector3 position, bool empty);
	void draw();
	bool collide(Camera3D camera);
};

