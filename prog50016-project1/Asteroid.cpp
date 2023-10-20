#include "Asteroid.h"
#include <random>
#include "Game.h"
#include <iostream>
#include "GameTime.h"

Asteroid::Asteroid() {
	hit = { ENVIRONMENT };
	hurt = { ALLY };
}

void Asteroid::SetRandomSpawnPosition() {
	pos[0] = GameTime::Get().Rand()*Game::Get().GetRenderHandler()->GetWidth();
}

void Asteroid::Update(float deltaTime) {
	pos[1] += speed * deltaTime;
	Draw();
	if (pos[1] > Game::Get().GetRenderHandler()->GetHeight()) {
		Game::Get().GetActorManager()->RemoveActor(this);
	}
}

void Asteroid::Load() {
	Actor::Load("Data/Asteroid.json");
}