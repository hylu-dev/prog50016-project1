#pragma once

#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Actor.h"

class Enemy : public Actor {

private:

	Enemy(RenderHandler* _renderHandler);

	void Update(float deltaTime) override;

};

#endif