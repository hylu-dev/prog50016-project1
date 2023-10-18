#pragma once

#ifndef _ACTOR_MANAGER_H_
#define _ACTOR_MANAGER_H_

#include "Player.h"
#include "EnemyFactory.h"
#include "Enemy.h"
#include "Asteroid.h"
#include "AsteroidBig.h"
#include <list>

class ActorManager {
private:
	std::list<Actor*> actors;
	std::list<Actor*> deletionStack;

	Player* player = nullptr;
	EnemyFactory* enemyFactory = nullptr;


public:
	ActorManager();

	~ActorManager();

	void Update();

	void AddActor(Actor* actor);

	void RemoveActor(Actor* actor);

	void SpawnEnemy();

	void Save();

	void Load();
};

#endif

