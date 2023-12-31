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
	std::string name = "";
	float pos[2] = { 0 };
	float move[2] = { 0 };
	int value = 1;
	int lives = 1;
	int damage = 1;
	float radius = 1;
	float speed = 2;
	std::vector<Layer> hit;
	std::vector<Layer> hurt;
	SDL_Texture* texture;

public:
	Actor() = default;

	~Actor();

	std::string GetName() { return name; }

	int GetLives() { return lives; }

	virtual void SetLives(int val) { lives = val; }

	float* GetPosition() { return pos; }

	void SetPosition(float x, float y) { pos[0] = x;pos[1] = y; }

	float* GetMove() { return move; }

	void SetMove(float x, float y) { move[0] = x;move[1] = y; }

	virtual void Update(float deltaTime) = 0;

	virtual void Collide(Actor* actor);

	virtual void TakeDamage(int value);

	virtual void Draw();

	virtual void Load(std::string path);
};

#endif