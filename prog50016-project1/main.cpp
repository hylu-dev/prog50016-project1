#include <iostream>

//#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_image.h"

void displayImage(SDL_Renderer* renderer, SDL_Texture* source, SDL_Rect& rect) {

	SDL_Texture* target = SDL_CreateTexture(
		renderer,
		SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET,
		rect.w,
		rect.h
	);

	SDL_SetRenderTarget(renderer, target);
	SDL_RenderCopy(renderer, source, &rect, NULL);
	SDL_SetRenderTarget(renderer, NULL);

	//SDL_Rect dstrect = { 0, 0, size.x, size.y };
	SDL_RenderCopy(renderer, target, NULL, &rect);
}

int main(int argv, char* argc[]) {
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	window = SDL_CreateWindow("SDL Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Surface* surface = IMG_Load("hollowknight.png");
	SDL_Texture* source = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface); // we got the texture now free surface

	bool quit = false;
	while (!quit) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_WINDOWEVENT:
				if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
					quit = true;
				}
				break;
			case SDL_KEYDOWN:
				std::cout << "Key Event" << std::endl;
				break;
			case SDL_KEYUP:
			case SDL_MOUSEMOTION:
			case SDL_MOUSEBUTTONDOWN:
				//std::cout << "Mouse Event" << std::endl;
				break;
			case SDL_MOUSEBUTTONUP:
			case SDL_MOUSEWHEEL:
			default:
				break;
			}
		}

		SDL_SetRenderDrawColor(renderer, 127, 44, 44, 255);
		SDL_RenderClear(renderer);

		// Render Objects here
		SDL_SetRenderDrawColor(renderer, 127, 44, 44, 255);
		SDL_RenderClear(renderer);

		SDL_Rect rect = { 0, 0, 200, 200 };
		displayImage(renderer, source, rect);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}