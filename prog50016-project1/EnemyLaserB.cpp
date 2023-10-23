#include "EnemyLaserB.h"
#include "GameTime.h"
#include "Game.h"

EnemyLaserB::EnemyLaserB() {
	hit = { ENEMY };
	hurt = { ALLY };
	name = "enemyLaserB";
}

void EnemyLaserB::Initialize(float x, float y) {
	pos[0] = x;
	pos[1] = y;
	float* playerPos = Game::Get().GetActorManager()->GetPlayer()->GetPosition();
	move[0] = playerPos[0] - x;
	move[1] = playerPos[1] - y;

	float magnitude = (float)std::sqrt(move[0] * move[0] + move[1] * move[1]);
	if (magnitude > 0) {
		move[0] = move[0] / magnitude;
		move[1] = move[1] / magnitude;
	}

	angle = std::atan2(move[1], move[0])*180/std::_Pi - 90;
}

void EnemyLaserB::Draw() {
	Game::Get().GetRenderHandler()->SetColor(200, 255, 100);
	Game::Get().GetRenderHandler()->DrawTex(texture, (int)pos[0], (int)pos[1], true, 2, 2, angle);
}

void EnemyLaserB::TakeDamage(int damage) {
	if (lives > 0) {
		lives -= damage;
		if (lives <= 0) {
			Game::Get().GetActorManager()->RemoveActor(this);
		}
	}
}

void EnemyLaserB::Update(float deltaTime) {
	pos[0] += move[0] * speed * deltaTime;
	pos[1] += move[1] * speed * deltaTime;

	Draw();
	if (pos[1] < 0) {
		Game::Get().GetActorManager()->RemoveActor(this);
	}
}

void EnemyLaserB::Load() {
	Actor::Load("Data/EnemyLaserB.json");
}