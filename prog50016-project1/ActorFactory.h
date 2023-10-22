#pragma once

#ifndef _ENEMY_FACTORY_H_
#define _ENEMY_FACTORY_H_

#include "EnemyA.h"
#include "EnemyB.h"
#include "Asteroid.h"
#include "AsteroidBig.h"
#include "EnemyLaserA.h"
#include "EnemyLaserB.h"
#include "Laser.h"

class ActorFactory {

public:
	EnemyA* GetEnemyA();

	EnemyB* GetEnemyB();

	Asteroid* GetAsteroid();

	AsteroidBig* GetAsteroidBig();

	EnemyLaserA* GetEnemyLaserA();

	EnemyLaserB* GetEnemyLaserB();

	Laser* GetLaser();
};

#endif