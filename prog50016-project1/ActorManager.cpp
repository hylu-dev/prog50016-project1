#include "ActorManager.h"
#include "GameTime.h"
#include <iostream>

ActorManager::ActorManager() {
	player = new Player();
	enemyFactory = new EnemyFactory();
}

ActorManager::~ActorManager() {
	for (auto& actor : actors) { 
		delete actor; 
	}
	actors.clear();
	delete player;
}

void ActorManager::Update() {
	CalculateCollisions();
	player->Update(GameTime::Get().DeltaTime());
	SpawnEnemy();
	for (auto& actor : actors) {
		actor->Update(GameTime::Get().DeltaTime());
	}
	for (auto& actor : deletionStack) {
		actors.remove(actor);
		delete actor;
	}
	deletionStack.clear();
}

void ActorManager::CalculateCollisions() {
	for (auto& actor : actors) {
		player->Collide(actor);
	}
}

void ActorManager::AddActor(Actor* actor) {
	actors.push_back(actor);
}

void ActorManager::RemoveActor(Actor* actor) {
	deletionStack.push_back(actor);
}

void ActorManager::SpawnEnemy() {
	if (GameTime::Get().FrameCount() % 10000 == 0) {
		AddActor(enemyFactory->GetEnemyA());
	}
	if (GameTime::Get().FrameCount() % 2000 == 0) {
		AddActor(enemyFactory->GetAsteroid());
	}
	if (GameTime::Get().FrameCount() % 4000 == 0) {
		AddActor(enemyFactory->GetAsteroidBig());
	}
}

void ActorManager::Save() {

}

void ActorManager::Load() {
	player->Load();
}