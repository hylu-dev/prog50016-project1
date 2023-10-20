#include "Game.h"
#include <iostream>
#include "GameTime.h"

Game* Game::instance = nullptr;

Game::Game() {
	inputHandler = new InputHandler();
	renderHandler = new RenderHandler();
	textureManager = new TextureManager(renderHandler);
	actorManager = new ActorManager();
	uiDisplay = new UIDisplay();
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
		GameTime::Get().Update();
		inputHandler->Update(&quit);
		
		// Render Objects here
		renderHandler->DrawBackground();
		actorManager->Update();
		renderHandler->Render();
	}
}

void Game::Load() {
	actorManager->Load();
}