#pragma once

#ifndef _ENEMY_B_H_
#define _ENEMY_B_H_

#include "Actor.h"
#include "Ship.h"

class EnemyB : public Ship {
private:
	void HandleMovement(float deltaTime);
	void HandleFire(float deltaTime);

public:
	EnemyB();
	~EnemyB() = default;

	void TakeDamage(int damage) override;

	void Initialize();

	void Update(float deltaTime) override;

	void Load();
};

#endif