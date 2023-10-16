#include "Game.h"
#include <iostream>

Game::Game() {
	prevFrameTime = SDL_GetTicks();
	inputHandler = new InputHandler();
	renderHandler = new RenderHandler();
	player = new Player(renderHandler, inputHandler);
}

Game::~Game() {
	delete inputHandler;
	delete renderHandler;
	delete player;
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
	player->Load("path");
}
void Game::UpdateDeltaTime() {
	float currentFrameTime = SDL_GetTicks();
	deltaTime = currentFrameTime - prevFrameTime;
	prevFrameTime = currentFrameTime;
}