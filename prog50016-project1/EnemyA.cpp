#include "EnemyA.h"
#include <random>
#include "Game.h"
#include <iostream>
#include "GameTime.h"
#include "EnemyLaserA.h"

EnemyA::EnemyA() {
	hit = { ENEMY };
	hurt = { ALLY };
	name = "enemyA";
}

void EnemyA::TakeDamage(int damage) {
	lives -= damage;
	if (lives <= 0) {
		Game::Get().GetUIDisplay()->IncrementScore();
		Game::Get().GetActorManager()->RemoveActor(this);
	}
}

void EnemyA::HandleMovement(float deltaTime) {
	pos[0] += move[0] * speed * deltaTime;
	pos[1] += move[1] * speed * deltaTime;
}

void EnemyA::HandleFire(float deltaTime) {
	fireRateCounter += deltaTime;
	if (fireRateCounter > fireRate) {
		fireRateCounter = 0;
		EnemyLaserA* laser = new EnemyLaserA();
		laser->Load();
		laser->Initialize(pos[0], pos[1]);
		Game::Get().GetActorManager()->AddActor(laser);
	}
}

void EnemyA::Initialize() {
	pos[0] = GameTime::Get().Rand()*Game::Get().GetRenderHandler()->GetWidth();
	move[0] = 0;
	move[1] = 1;
}

void EnemyA::Update(float deltaTime) {
	HandleMovement(deltaTime);
	HandleFire(deltaTime);

	Draw();
	if (pos[1] > Game::Get().GetRenderHandler()->GetHeight()+50) {
		Game::Get().GetActorManager()->RemoveActor(this);
	}
}

void EnemyA::Load() {
	Ship::Load("Data/EnemyShipA.json");
}