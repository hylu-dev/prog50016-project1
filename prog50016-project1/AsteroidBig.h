#pragma once

#ifndef _ASTEROID_BIG_H_
#define _ASTEROID_BIG_H_

#include "Actor.h"

class AsteroidBig : public Actor {
private:

public:
	AsteroidBig();
	~AsteroidBig() = default;

	void TakeDamage(int damage);

	void Initialize();

	void Update(float deltaTime) override;

	void Load();
};

#endif