#include "ActorManager.h"
#include "GameTime.h"
#include <iostream>

ActorManager::~ActorManager() {
	Destroy();
}

void ActorManager::Initialize() {
	player = new Player();
	enemyFactory = new EnemyFactory();
	isReset = false;
	Load();
}

void ActorManager::Update() {
	CalculateCollisions();
	player->Update(GameTime::Get().DeltaTime());
	SpawnEnemy();
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

void ActorManager::SpawnEnemy() {
	if (GameTime::Get().FrameCount() % 1000 == 0) {
		AddActor(enemyFactory->GetEnemyA());
	}
	if (GameTime::Get().FrameCount() % 200 == 0) {
		AddActor(enemyFactory->GetAsteroid());
	}
	if (GameTime::Get().FrameCount() % 1000 == 0) {
		AddActor(enemyFactory->GetAsteroidBig());
	}
}

void ActorManager::Save() {

}

void ActorManager::Load() {
	player->Load();
}