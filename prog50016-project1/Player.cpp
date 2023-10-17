#include "Player.h"
#include <iostream>
#include <cmath>
#include "Game.h"

Player::Player() {
	hit = { ALLY };
	hurt = { ENEMY, ENVIRONMENT };
	pos[0] = 640;
	pos[1] = 600;
}

void Player::Update(float deltaTime) {
	if (Game::Get().GetInputHandler()->GetKeyState(LEFT)) {
		direction[0] = -1;
	}
	if (Game::Get().GetInputHandler()->GetKeyState(RIGHT)) {
		direction[0] = 1;
	}
	if (!Game::Get().GetInputHandler()->GetKeyState(LEFT) && !Game::Get().GetInputHandler()->GetKeyState(RIGHT)) {
		direction[0] = 0;
	}
	if (Game::Get().GetInputHandler()->GetKeyState(UP)) {
		direction[1] = -1;
	}
	if (Game::Get().GetInputHandler()->GetKeyState(DOWN)) {
		direction[1] = 1;
	}
	if (!Game::Get().GetInputHandler()->GetKeyState(UP) && !Game::Get().GetInputHandler()->GetKeyState(DOWN)) {
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

void Player::Load() {
	Actor::Load("Data/Player.json");
}