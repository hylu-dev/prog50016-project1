#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Actor.h"

class Player : public Actor {

private:
	float direction[2] = { 0.0f };
	float movement[2] = { 0.0f };
	float friction = .998f;

public:
	Player();
	~Player() = default;

	void Update(float deltaTime) override;

	void Load();
};

#endif 