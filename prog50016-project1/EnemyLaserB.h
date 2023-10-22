#pragma once

#ifndef _ENEMY_LASER_B_H_
#define _ENEMY_LASER_B_H_

#include "Actor.h"

class EnemyLaserB : public Actor {

private:
	float angle = 0;

public:
	EnemyLaserB();
	~EnemyLaserB() = default;

	float GetAngle() { return angle; }

	void SetAngle(float val) { angle = val; }

	void Draw() override;

	void TakeDamage(int damage) override;

	void Initialize(float x, float y);

	void Update(float deltaTime) override;

	void Load();
};

#endif