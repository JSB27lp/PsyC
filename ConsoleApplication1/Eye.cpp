#include "Eye.h"
#include <cstdlib> 


Eye::Eye(Texture2D & eyeImg) : eyeImg_{eyeImg} {
	billPositionStatic_ = { 0, 0, 0 };
	int v1 = rand() % 100 - 50;
	billPositionStatic_.x += v1;
	int v2 = rand() % 100 - 50;
	billPositionStatic_.y += v2;
	int v3 = rand() % 100 - 50;
	billPositionStatic_.z += v3;
}

void Eye::display(Camera3D camera) {


	if (!((billPositionStatic_.x > -5 && billPositionStatic_.x < 5) && (billPositionStatic_.y > -5 && billPositionStatic_.y < 5) && (billPositionStatic_.z > -5 && billPositionStatic_.z < 5))) {
		DrawBillboard(camera, eyeImg_, billPositionStatic_, 2.0f, WHITE);
	}
}