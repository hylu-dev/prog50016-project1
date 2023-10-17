#include "Enemy.h"

void Enemy::SetRandomSpawnPosition() {

}

void Enemy::Update(float deltaTime) {
	pos[1] += speed * deltaTime;
}


