#include "TextureManager.h"

TextureManager::~TextureManager() {
	for (auto& pair : textures) {
		SDL_DestroyTexture(pair.second);
		pair.second = nullptr;
	}
	textures.clear();
}

SDL_Texture* TextureManager::RetrieveTexture(std::string path) {
	if (textures.count(path) == 0) {
		SDL_Surface* surface = IMG_Load(path.c_str());
		textures[path] = SDL_CreateTextureFromSurface(renderHandler->GetRenderer(), surface);
		SDL_FreeSurface(surface);
		surface = nullptr;
	}
	return textures[path];
}