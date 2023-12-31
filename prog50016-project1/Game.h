#pragma once

#ifndef _GAME_H_
#define _GAME_H_

#include "SDL.h"
#include "InputHandler.h"
#include "RenderHandler.h"
#include "TextureManager.h"
#include "ActorManager.h"
#include "UIDisplay.h"
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
	inline ActorManager* GetActorManager() { return actorManager; }
	inline UIDisplay* GetUIDisplay() { return uiDisplay; }

	void Play();

	void Initialize();

	void Reset();

	void LoadState();

	void SaveState();

private:
	static Game* instance;

	SDL_Window* window = nullptr;
	InputHandler* inputHandler = nullptr;
	RenderHandler* renderHandler = nullptr;
	TextureManager* textureManager = nullptr;
	ActorManager* actorManager = nullptr;
	UIDisplay* uiDisplay = nullptr;

private:
	Game() = default;
	~Game();
	inline explicit Game(Game const&) = delete;
	inline Game& operator=(Game const&) = delete;
};

#endif 