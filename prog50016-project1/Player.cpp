#include "Player.h"
#include <iostream>
#include <cmath>

Player::Player(RenderHandler* _renderHandler, InputHandler* _inputHandler) : Actor(_renderHandler) {
	hit = { ALLY };
	hurt = { ENEMY, ENVIRONMENT };
	pos[0] = 640;
	pos[1] = 600;
	inputHandler = _inputHandler;
}

void Player::Update(float deltaTime) {
	if (inputHandler->GetKeyState(LEFT)) {
		direction[0] = -1;
	}
	if (inputHandler->GetKeyState(RIGHT)) {
		direction[0] = 1;
	}
	if (!inputHandler->GetKeyState(LEFT) && !inputHandler->GetKeyState(RIGHT)) {
		direction[0] = 0;
	}
	if (inputHandler->GetKeyState(UP)) {
		direction[1] = -1;
	}
	if (inputHandler->GetKeyState(DOWN)) {
		direction[1] = 1;
	}
	if (!inputHandler->GetKeyState(UP) && !inputHandler->GetKeyState(DOWN)) {
		direction[1] = 0;
	}

	// normalize vector
	float magnitude = (float)std::sqrt(direction[0] * direction[0] + direction[1] * direction[1]);
	if (magnitude > 0) {
		direction[0] = direction[0] / magnitude;
		direction[1] = direction[1] / magnitude;
	}
	
	movement[0] += direction[0] * speed * deltaTime * 0.005f;
	movement[1] += direction[1] * speed * deltaTime * 0.005f;

	movement[0] *= friction;
	movement[1] *= friction;

	pos[0] += movement[0];
	pos[1] += movement[1];

    Draw();
}