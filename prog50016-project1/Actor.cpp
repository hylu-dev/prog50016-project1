#include "Actor.h"
#include "Game.h"
#include <iostream>
#include "json.h"
#include <fstream>

Actor::~Actor() {
	texture = nullptr;
}

void Actor::Collide(Actor* actor) {
	float sqDist = (actor->pos[0] - pos[0]) * (actor->pos[0] - pos[0]) + (actor->pos[1] - pos[1]) * (actor->pos[1] - pos[1]);
	float sqRads = radius * radius + 2 * radius * actor->radius + actor->radius * actor->radius;
	if (sqDist < sqRads) {
 		for (Layer& l1 : hit) {
			for (Layer& l2 : actor->hurt) {
				if (l1 == l2) {
					TakeDamage(actor->damage);
					break;
				}
			}
		}

		for (Layer& l1 : actor->hit) {
			for (Layer& l2 : hurt) {
				if (l1 == l2) {
					actor->TakeDamage(damage);
					break;
				}
			}
		}
	}
}

void Actor::TakeDamage(int damage) {
	lives -= damage;
	if (lives <= 0) {
		Game::Get().GetActorManager()->RemoveActor(this);
	}
}

void Actor::Draw() {
	Game::Get().GetRenderHandler()->DrawTex(texture, (int)pos[0], (int)pos[1]);
}

void Actor::Load(std::string path) {
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