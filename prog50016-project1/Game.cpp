#include "Game.h"
#include <iostream>

Game::Game() {
	prevFrameTime = SDL_GetTicks();
	window = SDL_CreateWindow("SDL Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	player = new Player(renderer);
}

Game::~Game() {
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	delete window;
	delete renderer;
	player->Destroy();
	delete player;
}

void Game::Play() {
	std::cout << "Game Start" << std::endl;
	bool quit = false;
	while (!quit) {
		UpdateDeltaTime();
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_WINDOWEVENT:
				if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
					quit = true;
				}
				break;
			case SDL_KEYDOWN:
				player->EnableMove();
				if (event.key.keysym.sym == SDLK_w) {
					player->ChangeDirection(0, -1);
				}
				else if (event.key.keysym.sym == SDLK_a) {
					player->ChangeDirection(-1, 0);
				}
				else if (event.key.keysym.sym == SDLK_s) {
					player->ChangeDirection(0, 1);
				}
				else if (event.key.keysym.sym == SDLK_d) {
					player->ChangeDirection(1, 0);
				}		
				
				break;
			case SDL_KEYUP:
				player->DisableMove();
				std::cout << "Key Event Up" << std::endl;
				break;
			case SDL_MOUSEWHEEL:
				break;
			default:
				break;
			}
		}

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