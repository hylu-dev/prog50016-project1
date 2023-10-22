#include "EnemyB.h"
#include <random>
#include "Game.h"
#include <iostream>
#include "GameTime.h"
#include "EnemyLaserB.h"

EnemyB::EnemyB() {
	hit = { ENEMY };
	hurt = { ALLY };
}

void EnemyB::HandleMovement(float deltaTime) {
	pos[0] += move[0] * speed * deltaTime;
	pos[1] += move[1] * speed * deltaTime;
}

void EnemyB::TakeDamage(int damage) {
	lives -= damage;
	if (lives <= 0) {
		Game::Get().GetUIDisplay()->IncrementScore();
		Game::Get().GetActorManager()->RemoveActor(this);
	}
}
void EnemyB::HandleFire(float deltaTime) {
	fireRateCounter += deltaTime;
	if (fireRateCounter > fireRate) {
		fireRateCounter = 0;
		EnemyLaserB* laser = new EnemyLaserB();
		laser->Load();
		laser->Initialize(pos[0], pos[1]);
		Game::Get().GetActorManager()->AddActor(laser);
	}
}

void EnemyB::Initialize() {
	pos[0] = GameTime::Get().Rand() * Game::Get().GetRenderHandler()->GetWidth();
	move[0] = 0;
	move[1] = 1;
}

void EnemyB::Update(float deltaTime) {
	HandleMovement(deltaTime);
	HandleFire(deltaTime);

	Draw();
	if (pos[1] > Game::Get().GetRenderHandler()->GetHeight() + 50) {
		Game::Get().GetActorManager()->RemoveActor(this);
	}
}

void EnemyB::Load() {
	Ship::Load("Data/EnemyShipB.json");
}