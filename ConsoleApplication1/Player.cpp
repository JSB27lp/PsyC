#include "Player.h"



void Player::move(Camera & camera) {

	if (IsKeyPressed(KEY_Z)) {
		pos.z++;
	}
	camera.position = pos;
}

