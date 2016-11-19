#pragma once
#include "../Project.h"
#include "Point.h"

class Entity
{
protected:
	SDL_Rect rect;
	SDL_Texture* texture;
	Point position;
	double direction;
public:
	Entity(int x, int y, SDL_Texture* _texture);
	virtual ~Entity();

	void render(SDL_Renderer* renderer);
};

