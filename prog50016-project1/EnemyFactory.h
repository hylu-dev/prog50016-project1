#pragma once

#ifndef _ENEMY_FACTORY_H_
#define _ENEMY_FACTORY_H_

#include "EnemyA.h"
#include "EnemyB.h"
#include "Asteroid.h"
#include "AsteroidBig.h"

class EnemyFactory {

public:
	EnemyA* GetEnemyA();

	EnemyB* GetEnemyB();

	Asteroid* GetAsteroid();

	AsteroidBig* GetAsteroidBig();
};

#endif