#include "AsteroidBig.h"
#include <random>
#include "Game.h"
#include <iostream>
#include "GameTime.h"

AsteroidBig::AsteroidBig() {
	hit = { ENVIRONMENT };
	hurt = { ALLY  };
}

void AsteroidBig::SetRandomSpawnPosition() {
	pos[0] = GameTime::Get().Rand()*Game::Get().GetRenderHandler()->GetWidth();
}

void AsteroidBig::Update(float deltaTime) {
	pos[1] += speed * deltaTime;
	Draw();
	if (pos[1] > Game::Get().GetRenderHandler()->GetHeight()) {
		Game::Get().GetActorManager()->RemoveActor(this);
	}
}

void AsteroidBig::Load() {
	Actor::Load("Data/AsteroidBig.json");
}