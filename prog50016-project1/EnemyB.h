#pragma once

#ifndef _ENEMY_B_H_
#define _ENEMY_B_H_

#include "Actor.h"

class EnemyB : public Actor {
private:
	int spawnRate = 1;

private:
	void HandleMovement(float deltaTime);
	void HandleFire();

public:
	EnemyB();
	~EnemyB() = default;

	void TakeDamage(int damage) override;

	void Initialize();

	void Update(float deltaTime) override;

	void Load();
};

#endif