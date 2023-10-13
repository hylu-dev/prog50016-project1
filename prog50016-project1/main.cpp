#include "Game.h"
#include <iostream>

int main(int argv, char* argc[]) {
	Game* game = new Game();
	game->Load();
	game->Play();

	delete game;
	return 0;
}