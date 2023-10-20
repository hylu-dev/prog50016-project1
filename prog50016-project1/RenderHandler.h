#pragma once

#ifndef _RENDER_HANDLER_H_
#define _RENDER_HANDLER_H_

#include "SDL.h"
#include <SDL_ttf.h>
#include <string>

class RenderHandler
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	int width = 1280;
	int height = 720;
	bool fullscreen = false;
	TTF_Font* font = nullptr;

public:
	RenderHandler();
	~RenderHandler();

	SDL_Renderer* GetRenderer() { return renderer; }

	int GetWidth() { return width;  }

	int GetHeight() { return height; }

	void DrawBackground();

	void DrawTex(SDL_Texture* texture, SDL_Rect* renderRect);

	void DrawFontText(std::string message, SDL_Rect* renderRect);

	void Render();
};

#endif