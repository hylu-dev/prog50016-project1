#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Actor.h"
#include <vector>

class Player : public Actor {

private:
	bool isMove = false;
	int direction[2] = {0};
	float friction = .2;

public:
	Player(SDL_Renderer* _renderer);

	void Update(float deltaTime) override;

	void ChangeDirection(int x, int y);

	void EnableMove();

	void DisableMove();

};

#endif 