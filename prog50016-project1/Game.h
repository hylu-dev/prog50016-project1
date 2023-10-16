#pragma once

#ifndef _GAME_H_
#define _GAME_H_

#include "SDL.h"
#include "InputHandler.h"
#include "RenderHandler.h"
#include "TextureManager.h"
#include "Player.h"
#include <list>

class Game {

public:
	inline static Game& Get() {
		if (instance == nullptr) {
			instance = new Game();
		}
		return *instance;
	}

	inline void Destroy() {
		if (instance != nullptr) {
			delete instance;
			instance = nullptr;
		}
	}

	inline RenderHandler* GetRenderHandler() { return renderHandler; }
	inline InputHandler* GetInputHandler() { return inputHandler; }
	inline TextureManager* GetTextureManager() { return textureManager; }

	void UpdateDeltaTime();

	void Play();

	void Load();

private:
	static Game* instance;

	SDL_Window* window = nullptr;
	InputHandler* inputHandler = nullptr;
	RenderHandler* renderHandler = nullptr;
	TextureManager* textureManager = nullptr;
	Player* player = nullptr;
	float prevFrameTime = 0;
	float deltaTime = 0;

private:
	Game();
	~Game();
	inline explicit Game(Game const&) = delete;
	inline Game& operator=(Game const&) = delete;
};

#endif 