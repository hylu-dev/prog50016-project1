#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Actor.h"
#include <vector>
#include "InputHandler.h"

class Player : public Actor {

private:
	int direction[2] = { 0 };
	int movement[2] = { 0 };
	float friction = .2f;
	InputHandler* inputHandler;

public:
	Player(SDL_Renderer* _renderer, InputHandler* _inputHandler);

	void Update(float deltaTime) override;
};

#endif 