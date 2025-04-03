#pragma once

#include "raylib.h"
class Player
{
public :
	Vector3 pos;
	void move(Camera & camera);
};

