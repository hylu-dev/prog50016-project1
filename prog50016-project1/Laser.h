#pragma once

#ifndef _LASER_H_
#define _LASER_H_

#include "Actor.h"

class Laser : public Actor {
private:
	int spawnRate = 1;

public:
	Laser();
	~Laser() = default;

	void TakeDamage(int damage) override;

	void SetPosition(float x, float y);

	void Update(float deltaTime) override;

	void Load();
};

#endif