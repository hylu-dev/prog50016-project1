#pragma once

#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Actor.h"

class Enemy : public Actor {

private:

	Enemy(SDL_Renderer* _renderer);

	void Update(float deltaTime) override;

};

#endif