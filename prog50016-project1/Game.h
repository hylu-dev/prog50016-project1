#pragma once

#ifndef _GAME_H_
#define _GAME_H_

#include "SDL.h"
#include "Player.h"

class Game {

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
Player* player = nullptr;
float prevFrameTime = 0;
float deltaTime = 0;

public:
	Game();
	~Game();

	void UpdateDeltaTime();

	void Play();

	void Load();

};

#endif 