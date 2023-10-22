#pragma once

#ifndef _SHIP_H_
#define _SHIP_H_

class Ship {
public:
	virtual void HandleMovement(float deltaTime) = 0;
	virtual void HandleFire() = 0;
};

#endif