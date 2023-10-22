#include "ActorManager.h"
#include "GameTime.h"
#include <iostream>
#include "json.h"
#include <fstream>

ActorManager::~ActorManager() {
	Destroy();
}

void ActorManager::Initialize() {
	player = new Player();
	enemyFactory = new EnemyFactory();
	isReset = false;
	Load();
}

void ActorManager::Update(float deltaTime) {
	CalculateCollisions();
	player->Update(GameTime::Get().DeltaTime());
	SpawnEnemy(deltaTime);
	for (auto& actor : actors) {
		actor->Update(GameTime::Get().DeltaTime());
	}
	for (auto& laser : lasers) {
 		laser->Update(GameTime::Get().DeltaTime());
	}
	for (auto& actor : deletionStack) {
		actors.remove(actor);
		delete actor;
	}
	deletionStack.clear();
	for (auto& laser : laserDeletionStack) {
		lasers.remove(laser);
		delete laser;
	}
	laserDeletionStack.clear();
	if (isReset) {
		Destroy();
		Initialize();
	}
}

void ActorManager::Destroy() {
	for (auto& actor : actors) {
		delete actor;
	}
	actors.clear();
	for (auto& laser : lasers) {
		delete laser;
	}
	lasers.clear();
	delete player;
	player = nullptr;
	delete enemyFactory;
	enemyFactory = nullptr;
}

void ActorManager::CalculateCollisions() {
	for (auto& actor : actors) {
		player->Collide(actor);
	}
	for (auto& laser : lasers) {
		for (auto& actor : actors) {
			laser->Collide(actor);
		}
	}
}

void ActorManager::AddLaser(Laser* laser) {
	lasers.push_back(laser);
}

void ActorManager::RemoveLaser(Laser* laser) {
	laserDeletionStack.push_back(laser);
}

void ActorManager::AddActor(Actor* actor) {
	actors.push_back(actor);
}

void ActorManager::RemoveActor(Actor* actor) {
	deletionStack.push_back(actor);
}

void ActorManager::SpawnEnemy(float deltaTime) {
	asteroidCounter += deltaTime;
	asteroidBigCounter += deltaTime;
	enemyACounter += deltaTime;
	enemyBCounter += deltaTime;

	if (enemyACounter > enemyASpawnRate) {
		enemyACounter = 0;
		AddActor(enemyFactory->GetEnemyA());
	}
	if (enemyBCounter > enemyBSpawnRate) {
		enemyBCounter = 0;
		AddActor(enemyFactory->GetEnemyB());
	}
	if (asteroidCounter > asteroidSpawnRate) {
		asteroidCounter = 0;
		AddActor(enemyFactory->GetAsteroid());
	}
	if (asteroidBigCounter > asteroidBigSpawnRate) {
		asteroidBigCounter = 0;
		AddActor(enemyFactory->GetAsteroidBig());
	}
}

void ActorManager::Save() {

}

void ActorManager::Load() {
	player->Load();

	std::ifstream inputStream("Data/SpawnRates.json");
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON document = json::JSON::Load(str);

	if (document.hasKey("asteroid")) {
		asteroidSpawnRate = document["asteroid"].ToFloat();
	}
	if (document.hasKey("asteroidBig")) {
		asteroidBigSpawnRate = document["asteroidBig"].ToFloat();
	}
	if (document.hasKey("enemyShipA")) {
		enemyASpawnRate = document["enemyShipA"].ToFloat();
	}
	if (document.hasKey("enemyShipB")) {
		enemyBSpawnRate = document["enemyShipB"].ToFloat();
	}

}