#include "RenderHandler.h"
#include "Game.h"

RenderHandler::RenderHandler() {
	window = SDL_CreateWindow("Ship Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, fullscreen);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	TTF_Init();
	font = TTF_OpenFont("Hud/SpaceMono-Regular.ttf", 24);
}

RenderHandler::~RenderHandler() {
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
}

void RenderHandler::SetColor(int x, int y, int z) {
	colorFilter[0] = x;
	colorFilter[1] = y;
	colorFilter[2] = z;
}

void RenderHandler::ResetColor() {
	colorFilter[0] = 255;
	colorFilter[1] = 255;
	colorFilter[2] = 255;
}

void RenderHandler::DrawBackground() {
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, Game::Get().GetTextureManager()->RetrieveTexture("Background/starBackground.png"), NULL, NULL);
}

void RenderHandler::DrawTex(SDL_Texture* texture, SDL_Rect* renderRect) {
	SDL_SetTextureColorMod(texture, colorFilter[0], colorFilter[1], colorFilter[2]);
	SDL_RenderCopy(renderer, texture, NULL, renderRect);
	ResetColor();
}

SDL_Point RenderHandler::DrawTex(SDL_Texture* texture, int x, int y) {
	SDL_SetTextureColorMod(texture, colorFilter[0], colorFilter[1], colorFilter[2]);
	SDL_Point size;
	SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
	SDL_Rect rect = { (int)(x - size.x * .5f),  (int)(y - size.y * .5f), size.x, size.y };
	SDL_RenderCopy(renderer, texture, NULL, &rect);
	ResetColor();
	return size;
}

SDL_Point RenderHandler::DrawFontText(std::string message, int x, int y) {
	SDL_Color White = { 255, 255, 255 };
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, message.c_str(), White);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);

	SDL_Point size;
	SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
	SDL_Rect message_rect{ x, y, size.x, size.y };
	SDL_RenderCopy(renderer, texture, NULL, &message_rect);

	SDL_DestroyTexture(texture);
	texture = nullptr;

	return size;
}

void RenderHandler::Render() {
	SDL_RenderPresent(renderer);
}