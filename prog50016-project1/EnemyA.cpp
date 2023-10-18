#include "EnemyA.h"
#include <random>
#include "Game.h"
#include <iostream>
#include "GameTime.h"

EnemyA::EnemyA() {
	hit = { ENEMY };
	hurt = { ALLY };
}

void EnemyA::SetRandomSpawnPosition() {

	pos[0] = GameTime::Get().Rand()*Game::Get().GetRenderHandler()->GetWidth();
}

void EnemyA::Update(float deltaTime) {
	pos[1] += 100*speed*deltaTime;

	Draw();
	if (pos[1] > Game::Get().GetRenderHandler()->GetHeight()) {
		Game::Get().GetActorManager()->RemoveActor(this);
	}
}

void EnemyA::Load() {
	Actor::Load("Data/EnemyShipA.json");
}