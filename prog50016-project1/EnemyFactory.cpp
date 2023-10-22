#include "EnemyFactory.h"

EnemyA* EnemyFactory::GetEnemyA() {
	EnemyA* enemy = new EnemyA();
	enemy->Load();
	enemy->Initialize();
	return enemy;
}

EnemyB* EnemyFactory::GetEnemyB() {
	EnemyB* enemy = new EnemyB();
	enemy->Load();
	enemy->Initialize();
	return enemy;
}

Asteroid* EnemyFactory::GetAsteroid() {
	Asteroid* asteroid = new Asteroid();
	asteroid->Load();
	asteroid->Initialize();
	return asteroid;
}

AsteroidBig* EnemyFactory::GetAsteroidBig() {
	AsteroidBig* asteroid = new AsteroidBig();
	asteroid->Load();
	asteroid->Initialize();
	return asteroid;
}
