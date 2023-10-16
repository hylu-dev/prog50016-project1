#include "Enemy.h"

Enemy::Enemy(SDL_Renderer* _renderer) : Actor(_renderer) {

}

void Enemy::Update(float deltaTime) {
	pos[1] += speed * deltaTime;
}