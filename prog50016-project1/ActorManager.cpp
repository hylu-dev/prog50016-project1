#include "ActorManager.h"

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

void ActorManager::Update(float deltaTime) {
	player->Update(deltaTime);
	for (auto& actor : actors) {
		actor->Update(deltaTime);
	}
}

void ActorManager::AddActor(Actor* actor) {
	actors.push_back(actor);
}

void ActorManager::RemoveActor(Actor* actor) {
	actors.remove(actor);
}

void ActorManager::SpawnEnemy() {

}

void ActorManager::Save() {

}

void ActorManager::Load() {
	player->Load();
}