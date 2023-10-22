#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Actor.h"
#include "Ship.h"

class Player : public Ship {

private:
	float direction[2] = { 0.0f };
	float iFrameCounter = 0;
	float friction = .97f;
	float iFrames = 1;
	bool invincible = false;

private:
	void HandleMovement(float deltaTime);
	void HandleFire(float deltaTime);
	void HandleIFrames(float deltaTime);

public:
	Player();
	~Player() = default;

	void Draw() override;

	void Update(float deltaTime) override;

	void Collide(Actor* actor) override;

	void TakeDamage(int damage) override;

	void Load();
};

#endif 