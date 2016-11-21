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
	int toX, toY;//радиус-вектор направления
public:
	Entity(int x, int y, SDL_Texture* _texture, double direction = 0);
	virtual ~Entity();

	void render(SDL_Renderer* renderer);
};

