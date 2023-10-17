#include "Game.h"
#include <iostream>

Game::Game() {
	prevFrameTime = SDL_GetTicks();
	inputHandler = new InputHandler();
	renderHandler = new RenderHandler();
	textureManager = new TextureManager(renderHandler);
	actorManager = new ActorManager();
}

Game::~Game() {
	delete inputHandler;
	delete renderHandler;
	delete textureManager;
	delete actorManager;
	inputHandler = nullptr;
	renderHandler = nullptr;
	textureManager = nullptr;
	actorManager = nullptr;
}

void Game::Play() {
	std::cout << "Game Start" << std::endl;
	bool quit = false;
	while (!quit) {
		UpdateDeltaTime();
		inputHandler->Update(&quit);
		
		// Render Objects here
		renderHandler->DrawBackground();
		actorManager->Update(deltaTime);
		renderHandler->Render();
	}
}

void Game::Load() {
	actorManager->Load();
}

void Game::UpdateDeltaTime() {
	float currentFrameTime = SDL_GetTicks();
	deltaTime = currentFrameTime - prevFrameTime;
	prevFrameTime = currentFrameTime;
}