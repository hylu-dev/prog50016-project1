#pragma once

#ifndef _ACTOR_MANAGER_H_
#define _ACTOR_MANAGER_H_

#include "Player.h"
#include "EnemyFactory.h"
#include "Enemy.h"
#include "Asteroid.h"
#include "AsteroidBig.h"
#include "Laser.h"
#include <list>

class ActorManager {
private:
	std::list<Actor*> actors;
	std::list<Actor*> deletionStack;
	std::list<Laser*> laserDeletionStack;
	std::list<Laser*> lasers;

	Player* player = nullptr;
	EnemyFactory* enemyFactory = nullptr;

private:
	void CalculateCollisions();

	void SpawnEnemy();

public:
	ActorManager();

	~ActorManager();

	void Update();

	void AddLaser(Laser* laser);

	void RemoveLaser(Laser* laser);

	void AddActor(Actor* actor);

	void RemoveActor(Actor* actor);

	void Save();

	void Load();
};

#endif

