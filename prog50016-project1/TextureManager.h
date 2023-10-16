#pragma once

#ifndef _TEXTURE_MANAGER_H_
#define _TEXTURE_MANAGER_H_

#include <string>
#include <map>
#include "SDL.h"
#include "RenderHandler.h"
#include "SDL_image.h"

class TextureManager {

private:
	std::map<std::string, SDL_Texture*> textures;
	RenderHandler* renderHandler = nullptr;

public:
	TextureManager(RenderHandler* _renderHandler) : renderHandler(_renderHandler) {};
	~TextureManager();

	SDL_Texture* RetrieveTexture(std::string path);

};

#endif

