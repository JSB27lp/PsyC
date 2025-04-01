#pragma once
#include "raylib.h"


class Eye
{
private:
	Vector3 billPositionStatic_;
	Texture2D & eyeImg_;
public:
	Eye(Texture2D & eyeImg);
	void display(Camera3D camera);
};