#include "Game.h"
#include <iostream>

Game::Game() {
	prevFrameTime = SDL_GetTicks();
	inputHandler = new InputHandler();
	renderHandler = new RenderHandler();
	textureManager = new TextureManager(renderHandler);
	player = new Player();
}

Game::~Game() {
	delete inputHandler;
	delete renderHandler;
	delete player;
	inputHandler = nullptr;
	renderHandler = nullptr;
	player = nullptr;
}

void Game::Play() {
	std::cout << "Game Start" << std::endl;
	bool quit = false;
	while (!quit) {
		UpdateDeltaTime();
		inputHandler->Update(&quit);
		
		// Render Objects here
		renderHandler->DrawBackground();
		player->Update(deltaTime);
		renderHandler->Render();
	}
}

void Game::Load() {
	player->Load("Data/Player.json");
}
void Game::UpdateDeltaTime() {
	float currentFrameTime = SDL_GetTicks();
	deltaTime = currentFrameTime - prevFrameTime;
	prevFrameTime = currentFrameTime;
}