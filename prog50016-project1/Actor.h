#pragma once

#ifndef _ACTOR_H_
#define _ACTOR_H_

#include <vector>
#include <string>
#include "SDL.h"

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
	float pos[2] = { 0 };
	float move[2] = { 0 };
	int lives = 1;
	int damage = 1;
	float radius = 1;
	float speed = 2;
	std::vector<Layer> hit;
	std::vector<Layer> hurt;
	SDL_Texture* texture;
	SDL_Rect renderRect;
	SDL_Point texSize;

public:
	Actor() = default;

	~Actor();

	virtual void Update(float deltaTime) = 0;

	void Collide(Actor* actor);

	virtual void TakeDamage(int value);

	void Draw();

	virtual void Load(std::string path);
};

#endif