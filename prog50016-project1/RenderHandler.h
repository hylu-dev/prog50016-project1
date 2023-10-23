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
	std::string name = "";
	int width = 1280;
	int height = 720;
	bool fullscreen = false;
	TTF_Font* font = nullptr;
	int colorFilter[3] = { 255, 255, 255 };

public:
	RenderHandler() = default;
	~RenderHandler();

	SDL_Renderer* GetRenderer() { return renderer; }

	void Initialize();

	int GetWidth() { return width;  }

	int GetHeight() { return height; }

	void SetColor(int x, int y, int z);

	void ResetColor();

	void DrawBackground();

	SDL_Point DrawTex(SDL_Texture* texture, int x, int y, bool centered = true, float xScale = 1, float yScale = 1, float angle = 0);

	SDL_Point DrawFontText(std::string message, int x, int y);

	void Render();

	void Load();
};

#endif