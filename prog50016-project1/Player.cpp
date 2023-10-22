#include "Player.h"
#include <iostream>
#include <cmath>
#include "Game.h"
#include "GameTime.h"
#include "Laser.h"

Player::Player() {
	hit = { ALLY };
	hurt = { ENEMY, ENVIRONMENT };
	name = "player";
}

void Player::SetLives(int val) {
	lives = val;
	Game::Get().GetUIDisplay()->SetLives(lives);
}

void Player::Draw() {
	if (invincible) {
		Game::Get().GetRenderHandler()->SetColor(255, 150, 255);
	}
	Game::Get().GetRenderHandler()->DrawTex(texture, (int)pos[0], (int)pos[1], true, 1/(abs(move[0])*.2f+1), 1, 0.0f);
}

void Player::Collide(Actor* actor) {
	if (!invincible) {
		Ship::Collide(actor);
	}
}

void Player::HandleMovement(float deltaTime) {
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

	move[0] += direction[0] * speed * deltaTime;
	move[1] += direction[1] * speed * deltaTime;

	move[0] *= friction;
	move[1] *= friction;

	pos[0] += move[0];
	pos[1] += move[1];

	if (pos[0] < 0) { pos[0] = 0; }
	if (pos[0] > Game::Get().GetRenderHandler()->GetWidth()) {
		pos[0] = (float)Game::Get().GetRenderHandler()->GetWidth();
	}
	if (pos[1] < 0) { pos[1] = 0; }
	if (pos[1] > Game::Get().GetRenderHandler()->GetHeight()) {
		pos[1] = (float)Game::Get().GetRenderHandler()->GetHeight();
	}
}

void Player::HandleFire(float deltaTime) {
	fireRateCounter += deltaTime;
	if (Game::Get().GetInputHandler()->GetKeyState(FIRE)) {
		if (fireRateCounter > fireRate) {
			fireRateCounter = 0;
			Laser* laser = new Laser();
			laser->Load();
			laser->SetPosition(pos[0], pos[1]);
			Game::Get().GetActorManager()->AddLaser(laser);
		}
	}
}

void Player::Update(float deltaTime) {
	HandleIFrames(deltaTime);
	HandleMovement(deltaTime);
	HandleFire(deltaTime);
    Draw();
}

void Player::HandleIFrames(float deltaTime) {
	if (invincible) {
		iFrameCounter += deltaTime;
	}
	if (iFrameCounter > iFrames) {
		invincible = false;
		iFrameCounter = 0;
	}
}

void Player::TakeDamage(int damage) {
	if (!invincible) {
		lives -= damage;
		invincible = true;
		Game::Get().GetUIDisplay()->SetLives(lives);
	}
	if (lives <= 0) {
		std::cout << "Dead" << std::endl;
		Game::Get().Reset();
	}
}

void Player::Load() {
	Ship::Load("Data/Player.json");
	Game::Get().GetUIDisplay()->SetLives(lives);
}