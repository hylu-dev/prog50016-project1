#include "Asteroid.h"
#include <random>
#include "Game.h"
#include <iostream>
#include "GameTime.h"

Asteroid::Asteroid() {
	hit = { ENVIRONMENT };
	hurt = { ALLY };
	name = "asteroid";
}

void Asteroid::Initialize() {
	pos[0] = GameTime::Get().Rand()*Game::Get().GetRenderHandler()->GetWidth();

	move[0] = GameTime::Get().Rand() * 2 - 1;
	move[1] = 1;
}

void Asteroid::Update(float deltaTime) {
	pos[0] += move[0] * speed * deltaTime;
	pos[1] += move[1] * speed * deltaTime;
	Draw();

	if (pos[1] > Game::Get().GetRenderHandler()->GetHeight() + 50) {
		Game::Get().GetActorManager()->RemoveActor(this);
	}
}

void Asteroid::Load() {
	Actor::Load("Data/Asteroid.json");
}

void Asteroid::TakeDamage(int damage) {
	lives -= damage;
	if (lives <= 0) {
		Game::Get().GetUIDisplay()->IncrementScore();
		Game::Get().GetActorManager()->RemoveActor(this);
	}
}