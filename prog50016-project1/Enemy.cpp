#include "Enemy.h"

Enemy::Enemy() {
	hit = { ENEMY };
	hurt = { ALLY };
}

void Enemy::SetRandomSpawnPosition() {

}

void Enemy::Update(float deltaTime) {
	pos[1] += speed * deltaTime;
}