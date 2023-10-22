#include "AsteroidBig.h"
#include <random>
#include "Game.h"
#include <iostream>
#include "GameTime.h"

AsteroidBig::AsteroidBig() {
	hit = { ENVIRONMENT };
	hurt = { ALLY  };
	move[0] = 0;
	move[1] = 1;
}

void AsteroidBig::Randomize() {
	pos[0] = GameTime::Get().Rand()*Game::Get().GetRenderHandler()->GetWidth();

	move[0] = GameTime::Get().Rand()*2 - 1;
	move[1] = 1;
}

void AsteroidBig::Update(float deltaTime) {
	pos[0] += move[0] * speed * deltaTime;
	pos[1] += move[1] * speed * deltaTime;
	Draw();

	if (pos[1] > Game::Get().GetRenderHandler()->GetHeight()) {
		Game::Get().GetActorManager()->RemoveActor(this);
	}
}

void AsteroidBig::Load() {
	Actor::Load("Data/AsteroidBig.json");
}