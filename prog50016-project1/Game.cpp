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
	delete uiDisplay;
	inputHandler = nullptr;
	renderHandler = nullptr;
	textureManager = nullptr;
	actorManager = nullptr;
	uiDisplay = nullptr;
}

void Game::Play() {
	std::cout << "Game Start" << std::endl;
	bool quit = false;
	while (!quit) {
		GameTime::Get().Update();
		inputHandler->Update(&quit);
		renderHandler->DrawBackground();
		actorManager->Update(GameTime::Get().DeltaTime());
		uiDisplay->Update();
		renderHandler->Render();
	}
}

void Game::Load() {
	actorManager->Initialize();
}

void Game::Reset() {
	uiDisplay->ResetScore();
	actorManager->MarkReset();
}