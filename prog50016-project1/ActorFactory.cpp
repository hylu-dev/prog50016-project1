#include "ActorFactory.h"

EnemyA* ActorFactory::GetEnemyA() {
	EnemyA* enemy = new EnemyA();
	enemy->Load();
	enemy->Initialize();
	return enemy;
}

EnemyB* ActorFactory::GetEnemyB() {
	EnemyB* enemy = new EnemyB();
	enemy->Load();
	enemy->Initialize();
	return enemy;
}

Asteroid* ActorFactory::GetAsteroid() {
	Asteroid* asteroid = new Asteroid();
	asteroid->Load();
	asteroid->Initialize();
	return asteroid;
}

AsteroidBig* ActorFactory::GetAsteroidBig() {
	AsteroidBig* asteroid = new AsteroidBig();
	asteroid->Load();
	asteroid->Initialize();
	return asteroid;
}

EnemyLaserA* ActorFactory::GetEnemyLaserA() {
	EnemyLaserA* enemyLaserA = new EnemyLaserA();
	enemyLaserA->Load();
	return enemyLaserA;
}
EnemyLaserB* ActorFactory::GetEnemyLaserB() {
	EnemyLaserB* enemyLaserB= new EnemyLaserB();
	enemyLaserB->Load();
	return enemyLaserB;
}
Laser* ActorFactory::GetLaser() {
	Laser* laser = new Laser();
	laser->Load();
	return laser;
}