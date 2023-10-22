#include "Laser.h"
#include "GameTime.h"
#include "Game.h"

Laser::Laser() {
	hit = { ALLY };
	hurt = { ENEMY, ENVIRONMENT };
	name = "laser";
}

void Laser::SetPosition(float x, float y) {
	pos[0] = x;
	pos[1] = y;
}

void Laser::TakeDamage(int damage) {
	lives -= damage;
	if (lives == 0) {
		Game::Get().GetActorManager()->RemoveLaser(this);
	}
}

void Laser::Update(float deltaTime) {
	pos[1] -= speed * deltaTime;

	Draw();
	if (pos[1] < 0) {
		Game::Get().GetActorManager()->RemoveLaser(this);
	}
}

void Laser::Load() {
	Actor::Load("Data/Laser.json");
}