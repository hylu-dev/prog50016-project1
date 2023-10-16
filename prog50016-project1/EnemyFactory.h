#pragma once

#ifndef _ENEMY_FACTORY_H_
#define _ENEMY_FACTORY_H_

#include "AlienShipA.h"
#include "AlienShipB.h"

class EnemyFactory
{
	AlienShipA GetEnemyA();

	AlienShipB GetEnemyB();
};

#endif