#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Actor.h"
#include <vector>
#include "InputHandler.h"

class Player : public Actor {

private:
	float direction[2] = { 0.0f };
	float movement[2] = { 0.0f };
	float friction = .998f;
	InputHandler* inputHandler;

public:
	Player(RenderHandler* _renderHandler, InputHandler* _inputHandler);

	void Update(float deltaTime) override;
};

#endif 