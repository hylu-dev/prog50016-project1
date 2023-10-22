#pragma once

#ifndef _ENEMY_A_H_
#define _ENEMY_A_H_

#include "Actor.h"
#include "Ship.h"

class EnemyA : public Ship {
private:
	int spawnRate = 1;

private:
	void HandleMovement(float deltaTime);
	void HandleFire(float deltaTime);

public:
	EnemyA();
	~EnemyA() = default;

	void TakeDamage(int damage) override;

	void Initialize();

	void Update(float deltaTime) override;

	void Load();
};

#endif