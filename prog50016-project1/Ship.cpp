#include "Ship.h"
#include "json.h"
#include <fstream>
#include "Game.h"

void Ship::Load(std::string path) {
	std::ifstream inputStream(path);
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON document = json::JSON::Load(str);

	if (document.hasKey("x")) {
		pos[0] = (float)document["x"].ToInt();
	}
	if (document.hasKey("y")) {
		pos[1] = (float)document["y"].ToInt();
	}
	if (document.hasKey("lives")) {
		lives = document["lives"].ToInt();
	}
	if (document.hasKey("damage")) {
		damage = document["damage"].ToInt();
	}
	if (document.hasKey("speed")) {
		speed = document["speed"].ToInt();
	}
	if (document.hasKey("fireRate")) {
		fireRate = document["fireRate"].ToFloat();
	}
	if (document.hasKey("value")) {
		value = document["value"].ToInt();
	}
	if (document.hasKey("sprite")) {
		texture = Game::Get().GetTextureManager()->RetrieveTexture(document["sprite"].ToString());
	}

	SDL_Point texSize;
	SDL_QueryTexture(texture, NULL, NULL, &texSize.x, &texSize.y);
	pos[1] -= texSize.y;
	if (texSize.x < texSize.y) {
		radius = texSize.x * .5f;
	}
	else {
		radius = texSize.y * .5f;
	}
}
