#include "RenderHandler.h"
#include "Game.h"

RenderHandler::RenderHandler() {
	window = SDL_CreateWindow("Ship Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, fullscreen);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	font = TTF_OpenFont("Hud/cour.ttf", 24);
}

RenderHandler::~RenderHandler() {
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
}

void RenderHandler::DrawBackground() {
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, Game::Get().GetTextureManager()->RetrieveTexture("Background/starBackground.png"), NULL, NULL);
}

void RenderHandler::DrawTex(SDL_Texture* texture, SDL_Rect* renderRect) {
	SDL_RenderCopy(renderer, texture, NULL, renderRect);
}

void RenderHandler::DrawFontText(std::string message, SDL_Rect* renderRect) {
	SDL_Color White = { 255, 255, 255 };
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, message.c_str(), White);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);

	SDL_Point size;
	SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
	SDL_Rect message_rect{ 0, 0, size.x, size.y }; //create a rect
	SDL_RenderCopy(renderer, texture, NULL, &message_rect);
}

void RenderHandler::Render() {
	SDL_RenderPresent(renderer);
}