#include "Game.h"
#include <iostream>

Game::Game() {
	prevFrameTime = SDL_GetTicks();
	window = SDL_CreateWindow("SDL Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	inputHandler = new InputHandler();
	player = new Player(renderer, inputHandler);
}

Game::~Game() {
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	delete window;
	delete renderer;
	delete inputHandler;
	player->Destroy();
	delete player;
}

void Game::Play() {
	std::cout << "Game Start" << std::endl;
	bool quit = false;
	while (!quit) {
		UpdateDeltaTime();
		inputHandler->Update(&quit);
		
		// Render Objects here
		SDL_SetRenderDrawColor(renderer, 127, 44, 44, 255);
		SDL_RenderClear(renderer);

		player->Update(deltaTime);
		SDL_RenderPresent(renderer);
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