#pragma once

#ifndef _ENEMY_LASER_A_H_
#define _ENEMY_LASER_A_H_

#include "Actor.h"

class EnemyLaserA : public Actor {

public:
	EnemyLaserA();
	~EnemyLaserA() = default;

	void TakeDamage(int damage) override;

	void Initialize(float x, float y);

	void Update(float deltaTime) override;

	void Load();
};

#endif