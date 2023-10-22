#pragma once

#ifndef _ACTOR_MANAGER_H_
#define _ACTOR_MANAGER_H_

#include "Player.h"
#include "ActorFactory.h"
#include "Enemy.h"
#include "Asteroid.h"
#include "AsteroidBig.h"
#include "Laser.h"
#include <list>
#include "json.h"

class ActorManager {
private:
	std::list<Actor*> actors;
	std::list<Actor*> deletionStack;
	std::list<Laser*> laserDeletionStack;
	std::list<Laser*> lasers;

	bool isReset = false;

	Player* player = nullptr;
	ActorFactory* actorFactory = nullptr;

	float asteroidCounter = 0.0f;
	float asteroidBigCounter = 0.0f;
	float enemyACounter = 0.0f;
	float enemyBCounter = 0.0f;
	float asteroidSpawnRate = 1;
	float asteroidBigSpawnRate = 1;
	float enemyASpawnRate = 1;
	float enemyBSpawnRate = 1;

private:
	void CalculateCollisions();
	void SpawnEnemy(float deltaTime);
	void Destroy();

public:
	ActorManager() = default;

	~ActorManager();

	void Update(float deltaTime);

	Player* GetPlayer() { return player; }

	void AddLaser(Laser* laser);

	void RemoveLaser(Laser* laser);

	void AddActor(Actor* actor);

	void RemoveActor(Actor* actor);

	void SaveState(json::JSON& document);

	void LoadState(json::JSON& document);

	void Load();

	void Initialize();

	void MarkReset() { isReset = true; };
};

#endif

