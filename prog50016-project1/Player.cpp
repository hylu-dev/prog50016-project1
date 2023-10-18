#include "Player.h"
#include <iostream>
#include <cmath>
#include "Game.h"
#include "GameTime.h"

Player::Player() {
	hit = { ALLY };
	hurt = { ENEMY, ENVIRONMENT };
}

void Player::Update(float deltaTime) {
	// controls
	if (Game::Get().GetInputHandler()->GetKeyState(LEFT) ) {
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
	
	movement[0] += direction[0] * speed * deltaTime;
	movement[1] += direction[1] * speed * deltaTime;

	movement[0] *= friction;
	movement[1] *= friction;

	pos[0] += movement[0];
	pos[1] += movement[1];

	if (pos[0] < 0) { pos[0] = 0; }
	if (pos[0] > Game::Get().GetRenderHandler()->GetWidth()) {
		pos[0] = Game::Get().GetRenderHandler()->GetWidth();
 }
	if (pos[1] < 0) { pos[1] = 0; }
	if (pos[1] > Game::Get().GetRenderHandler()->GetHeight()) {
		pos[1] = Game::Get().GetRenderHandler()->GetHeight();
	}

    Draw();
}

void Player::Load() {
	Actor::Load("Data/Player.json");
}