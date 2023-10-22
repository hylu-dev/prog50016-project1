#pragma once

#ifndef _ENEMY_A_H_
#define _ENEMY_A_H_

#include "Actor.h"

class EnemyA : public Actor {
private:
	int spawnRate = 1;

public:
	EnemyA();
	~EnemyA() = default;

	void Randomize();

	void Update(float deltaTime) override;

	void Load();
};

#endif