#pragma once

#ifndef _ACTOR_H_
#define _ACTOR_H_

#include <vector>
#include "SDL.h"
#include <string>
#include "json.h"

enum Layer
{
	PASSIVE = 0,
	ALLY = 1,
	ENEMY = 2,
	ENVIRONMENT = 3
};

// A base class for things that move and collide
class Actor {
protected:
	SDL_Renderer* renderer = nullptr;
	float pos[2] = { 0 };
	int lives = 1;
	int damage = 1;
	float radius = 1;
	float speed = .5;
	std::vector<Layer> hit;
	std::vector<Layer> hurt;
	SDL_Texture* texture;
	SDL_Rect renderRect;
	SDL_Point texSize;

public:
	Actor();

	Actor(SDL_Renderer* _renderer) : renderer(_renderer) {};

	virtual void Update(float deltaTime) = 0;

	void Destroy();

	void Collide(Actor* actor);

	void TakeDamage(int value);

	void Render();

	void Load(std::string path);
};

#endif