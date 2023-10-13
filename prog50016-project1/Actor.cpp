#include "Actor.h"
#include "SDL_image.h"
#include <iostream>

void Actor::Destroy() {
	SDL_DestroyTexture(texture);
	texture = nullptr;
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
	if (lives < 0) {
		Destroy();
	}
}

void Actor::Render() {
	renderRect = { pos[0], pos[1], texSize.x, texSize.y };
	SDL_RenderCopy(renderer, texture, NULL, &renderRect);
}

void Actor::Load(std::string path) {
	SDL_Surface* surface = IMG_Load("Mainplayer/player.png");
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	surface = nullptr;
	SDL_QueryTexture(texture, NULL, NULL, &texSize.x, &texSize.y);
}