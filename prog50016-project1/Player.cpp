#include "Player.h"
#include <iostream>

Player::Player(SDL_Renderer* _renderer) : Actor(_renderer) {
	lives = 3;
	damage = 1;
	radius = 1;
	hit = { ALLY };
	hurt = { ENEMY, ENVIRONMENT };
	pos[0] = 640 - texSize.x*.5;
	pos[1] = 600;
}

void Player::Update(float deltaTime) {
    SDL_Event _event;

	if (isMove == true) {
		pos[0] += direction[0]*deltaTime;
		pos[1] += direction[1]*deltaTime;
	}

    Render();
}

void Player::ChangeDirection(int x, int y) {
	direction[0] = x;
	direction[1] = y;
}

void Player::EnableMove() {
	isMove = true;
}

void Player::DisableMove() {
	isMove = false;
}