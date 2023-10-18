#include "EnemyFactory.h"

EnemyA* EnemyFactory::GetEnemyA() {
	EnemyA* enemy = new EnemyA();
	enemy->Load();
	enemy->SetRandomSpawnPosition();
	return enemy;
}

EnemyB* EnemyFactory::GetEnemyB() {
	EnemyB* enemy = new EnemyB();
	return enemy;
}

Asteroid* EnemyFactory::GetAsteroid() {
	Asteroid* asteroid = new Asteroid();
	asteroid->Load();
	asteroid->SetRandomSpawnPosition();
	return asteroid;
}

AsteroidBig* EnemyFactory::GetAsteroidBig() {
	AsteroidBig* asteroid = new AsteroidBig();
	asteroid->Load();
	asteroid->SetRandomSpawnPosition();
	return asteroid;
}
