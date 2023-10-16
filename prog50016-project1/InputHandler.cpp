#include "InputHandler.h"

InputHandler::InputHandler() {
	inputMap = {
		{LEFT, false},
		{RIGHT, false},
		{UP, false},
		{DOWN, false},
		{FIRE, false}
	};
}

bool InputHandler::GetKeyState(InputKey input) {
	return inputMap[input];
}

void InputHandler::SetKeyState(InputKey input, bool state) {
	inputMap[input] = state;
}

void InputHandler::Update(bool* quit) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_WINDOWEVENT:
				if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
					*quit = true;
				}
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					*quit = true;
					break;
				}
				if (event.key.keysym.sym == SDLK_w) {
					inputMap[UP] = true;
				}
				if (event.key.keysym.sym == SDLK_s) {
					inputMap[DOWN] = true;
				}
				if (event.key.keysym.sym == SDLK_a) {
					inputMap[LEFT] = true;
				}

				if (event.key.keysym.sym == SDLK_d) {
					inputMap[RIGHT] = true;
				}
				if (event.key.keysym.sym == SDLK_SPACE) {
					inputMap[FIRE] = true;
				}
				break;
			case SDL_KEYUP:
				if (event.key.keysym.sym == SDLK_w) {
					inputMap[UP] = false;
				}
				if (event.key.keysym.sym == SDLK_s) {
					inputMap[DOWN] = false;
				}
				if (event.key.keysym.sym == SDLK_a) {
					inputMap[LEFT] = false;
				}
				if (event.key.keysym.sym == SDLK_d) {
					inputMap[RIGHT] = false;
				}
				if (event.key.keysym.sym == SDLK_SPACE) {
					inputMap[FIRE] = false;
				}
				break;
			default:
				break;
		}
	}
}
