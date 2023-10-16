#include "Player.h"
#include <iostream>

Player::Player(RenderHandler* _renderHandler, InputHandler* _inputHandler) : Actor(_renderHandler) {
	hit = { ALLY };
	hurt = { ENEMY, ENVIRONMENT };
	pos[0] = 640;
	pos[1] = 600;
	inputHandler = _inputHandler;
}

void Player::Update(float deltaTime) {
	if (inputHandler->GetKeyState(LEFT)) {
		pos[0] -= speed * deltaTime;
	}
	if (inputHandler->GetKeyState(RIGHT)) {
		pos[0] += speed * deltaTime;
	}
	if (inputHandler->GetKeyState(UP)) {
		pos[1] -= speed * deltaTime;
	}
	if (inputHandler->GetKeyState(DOWN)) {
		pos[1] += speed * deltaTime;
	}

	//pos[0] += direction[0] * deltaTime;
	//pos[1] += direction[1]*deltaTime;

    Draw();
}