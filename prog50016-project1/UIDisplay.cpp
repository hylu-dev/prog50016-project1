#include "UIDisplay.h"
#include "Game.h"
#include "SDL.h"

void UIDisplay::Update() {
	SDL_Point size = { 0, 0 };

	for (int i = 0; i < lives; i++) {
		size = Game::Get().GetRenderHandler()->DrawTex(
			Game::Get().GetTextureManager()->RetrieveTexture("Hud/life.png"),
			i*size.x + 10*i + 10,
			10
		);
	}

	size = Game::Get().GetRenderHandler()->DrawFontText(
		"Score: " + std::to_string(score),
		10, size.y
	);

	Game::Get().GetRenderHandler()->DrawFontText(
		"High Score: " + std::to_string(highScore),
		10, size.y*2
	);
}

void UIDisplay::Load() {

}