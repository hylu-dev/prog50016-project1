#pragma once

#ifndef _SHIP_H_
#define _SHIP_H_

#include "Actor.h"

class Ship : public Actor {

protected:
	float fireRate = 1;
	float fireRateCounter = 0;

protected:
	virtual void HandleMovement(float deltaTime) = 0;
	virtual void HandleFire(float deltaTime) = 0;
	virtual void Load(std::string path);
};

#endif