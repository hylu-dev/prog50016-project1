#pragma once

#ifndef _ASTEROID_H_
#define _ASTEROID_H_

#include "Actor.h"

class Asteroid : public Actor {
private:
	int spawnRate = 1;

public:
	Asteroid();
	~Asteroid() = default;

	void SetRandomSpawnPosition();

	void Update(float deltaTime) override;

	void Load();
};

#endif