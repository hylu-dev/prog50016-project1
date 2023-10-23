#include "Game.h"
#include <iostream>
#include "GameTime.h"
#include "json.h"
#include <fstream>

Game* Game::instance = nullptr;

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

void Game::Initialize() {
	inputHandler = new InputHandler();
	renderHandler = new RenderHandler();
	renderHandler->Initialize();
	textureManager = new TextureManager(renderHandler);
	uiDisplay = new UIDisplay();
	actorManager = new ActorManager();
	actorManager->Initialize();
}

void Game::Reset() {
	uiDisplay->ResetScore();
	actorManager->MarkReset();
}

void Game::LoadState() {
	std::ifstream inputStream("Data/SaveState.json");
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON document = json::JSON::Load(str);

	actorManager->LoadState(document);
	uiDisplay->SetScore(document["score"].ToInt());
	uiDisplay->SetHighScore(document["score"].ToInt());
}

void Game::SaveState() {
	std::cout << "Save State" << std::endl;
	json::JSON document = json::JSON::Make(json::JSON::Class::Null);

	document["score"] = uiDisplay->GetScore();
	document["highScore"] = uiDisplay->GetHighScore();
	actorManager->SaveState(document);

	std::string jsonStr = document.dump();
	std::ofstream outputFile("Data/SaveState.json");
	if (outputFile.is_open()) {
		outputFile << jsonStr;
		outputFile.close();
		std::cout << "JSON data saved" << std::endl;
	}
	else {
		std::cerr << "Unable to open the file for writing." << std::endl;
	}
}