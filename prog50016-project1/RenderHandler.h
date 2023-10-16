#pragma once

#ifndef _RENDER_HANDLER_H_
#define _RENDER_HANDLER_H_

#include "SDL.h"

class RenderHandler
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

public:
	RenderHandler();
	~RenderHandler();

	SDL_Renderer* GetRenderer();

	void DrawBackground();

	void DrawTex(SDL_Texture* texture, SDL_Rect* renderRect);

	void Render();
};

#endif