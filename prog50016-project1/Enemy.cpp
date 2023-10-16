#include "Enemy.h"

Enemy::Enemy(RenderHandler* _renderHandler) : Actor(_renderHandler) {

}

void Enemy::Update(float deltaTime) {
	pos[1] += speed * deltaTime;
}