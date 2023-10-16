#include "Game.h"
#include <iostream>

Game* Game::instance = nullptr;

int main(int argv, char* argc[]) {
	Game::Get().Load();
	Game::Get().Play();
	Game::Get().Destroy();
	return 0;
}