#include "RenderHandler.h"
#include "Game.h"

RenderHandler::RenderHandler() {
	window = SDL_CreateWindow("Ship Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

RenderHandler::~RenderHandler() {
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
}

SDL_Renderer* RenderHandler::GetRenderer() {
	return renderer;
}

void RenderHandler::DrawBackground() {
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, Game::Get().GetTextureManager()->RetrieveTexture("Background/starBackground.png"), NULL, NULL);
}

void RenderHandler::DrawTex(SDL_Texture* texture, SDL_Rect* renderRect) {
	SDL_RenderCopy(renderer, texture, NULL, renderRect);
}

void RenderHandler::Render() {
	SDL_RenderPresent(renderer);
}