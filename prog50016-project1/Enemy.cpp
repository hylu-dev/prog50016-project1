#include "Enemy.h"

void Enemy::Update(float deltaTime) {
	pos[1] += speed * deltaTime;
}