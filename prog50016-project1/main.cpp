#include "Game.h"
#include <iostream>

int main(int argv, char* argc[]) {
	Game::Get().Initialize();
	Game::Get().Play();
	Game::Get().Destroy();

	return 0;
}