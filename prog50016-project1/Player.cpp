#include "Player.h"
#include <iostream>

Player::Player(SDL_Renderer* _renderer, InputHandler* _inputHandler) : Actor(_renderer) {
	lives = 3;
	damage = 1;
	radius = 1;
	speed = 1;
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

    Render();
}

void Player::ChangeXDirection(int num) {
	direction[0] = num;
}

void Player::ChangeYDirection(int num) {
	direction[1] = num;
}