#pragma once
#include "../Project.h"

class Character
{
private:
	int x, y;	//TODO: point ?
	double direction;
	int speed;
	SDL_Rect rect;
	SDL_Texture* texture;
public:
	Character(int x0, int y0, SDL_Texture* texture, double direction);
	virtual ~Character();

	void move(int toX, int toY, float deltaTime);
	void render(SDL_Renderer* renderer);
};

