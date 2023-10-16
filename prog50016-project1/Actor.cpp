#include "Actor.h"
#include "SDL_image.h"
#include <iostream>

Actor::~Actor() {
	SDL_DestroyTexture(texture);
	texture = nullptr;
	renderHandler = nullptr;
}

void Actor::Collide(Actor* actor) {
	float sqDist = (actor->pos[0] - pos[0]) * (actor->pos[0] - pos[0]) + (actor->pos[1] - pos[0]) * (actor->pos[1] - pos[0]);
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
}

void Actor::Draw() {
	renderRect = { (int)pos[0], (int)pos[1], texSize.x, texSize.y };
	renderHandler->DrawTex(texture, &renderRect);
}

void Actor::Load(std::string path) {
	SDL_Surface* surface = IMG_Load("Mainplayer/player.png");
	texture = SDL_CreateTextureFromSurface(renderHandler->GetRenderer(), surface);
	SDL_FreeSurface(surface);
	surface = nullptr;
	SDL_QueryTexture(texture, NULL, NULL, &texSize.x, &texSize.y);
	pos[0] -= texSize.x * .5f;
	if (texSize.x < texSize.y) {
		radius = texSize.x * .5f;
	}
	else {
		radius = texSize.y * .5f;
	}
}