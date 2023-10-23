#include "EnemyLaserA.h"
#include "GameTime.h"
#include "Game.h"

EnemyLaserA::EnemyLaserA() {
	hit = { ENEMY };
	hurt = { ALLY };
	name = "enemyLaserA";
}

void EnemyLaserA::Initialize(float x, float y) {
	pos[0] = x;
	pos[1] = y;
	move[0] = 0;
	move[1] = 1;
}

void EnemyLaserA::TakeDamage(int damage) {
	if (lives > 0) {
		lives -= damage;
		if (lives <= 0) {
			Game::Get().GetActorManager()->RemoveActor(this);
		}
	}
}

void EnemyLaserA::Update(float deltaTime) {
	pos[0] += move[0] * speed * deltaTime;
	pos[1] += move[1] * speed * deltaTime;

	Draw();
	if (pos[1] < 0) {
		Game::Get().GetActorManager()->RemoveActor(this);
	}
}

void EnemyLaserA::Load() {
	Actor::Load("Data/EnemyLaserA.json");
}