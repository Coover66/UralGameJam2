#pragma once
#include "../Project.h"
#include "Point.h"

class Character
{
protected:
	Point position;
	double direction;
	int speed;
	SDL_Rect rect;
	SDL_Texture* texture;
public:
	Character(int x, int y, SDL_Texture* texture, double direction = 0);
	virtual ~Character();
	void move(int toX, int toY, float deltaTime);
	void render(SDL_Renderer* renderer);
};

