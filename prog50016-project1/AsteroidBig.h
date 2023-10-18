#pragma once

#ifndef _ASTEROID_BIG_H_
#define _ASTEROID_BIG_H_

#include "Actor.h"

class AsteroidBig : public Actor {
private:
	int spawnRate = 1;

public:
	AsteroidBig();
	~AsteroidBig() = default;

	void SetRandomSpawnPosition();

	void Update(float deltaTime) override;

	void Load();
};

#endif