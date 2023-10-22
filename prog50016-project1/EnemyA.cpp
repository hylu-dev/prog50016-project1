#include "EnemyA.h"
#include <random>
#include "Game.h"
#include <iostream>
#include "GameTime.h"
#include "EnemyLaserA.h"

EnemyA::EnemyA() {
	hit = { ENEMY };
	hurt = { ALLY };
}

void EnemyA::HandleMovement(float deltaTime) {
	pos[0] += move[0] * speed * deltaTime;
	pos[1] += move[1] * speed * deltaTime;
}

void EnemyA::HandleFire() {
	if (GameTime::Get().FrameCount() % 500 == 0) {
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
	HandleFire();

	Draw();
	if (pos[1] > Game::Get().GetRenderHandler()->GetHeight()+50) {
		Game::Get().GetActorManager()->RemoveActor(this);
	}
}

void EnemyA::Load() {
	Actor::Load("Data/EnemyShipA.json");
}