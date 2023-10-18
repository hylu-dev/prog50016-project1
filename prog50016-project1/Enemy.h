#pragma once

#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Actor.h"

class Enemy : public Actor {
	int spawnRate = 1;

private:
	Enemy();
	~Enemy() = default;

	void SetRandomSpawnPosition();

	void Update(float deltaTime) override;
};

#endif