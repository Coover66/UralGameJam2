#include "Character.h"



Character::Character(int x0, int y0, SDL_Texture* texture0, double direction)
{
	rect = { 10,10,100,100 };
	x = x0;
	y = y0;
	texture = texture0;
}


Character::~Character()
{
}

void Character::move(int toX, int toY, float deltaTime)
{
	//TODO: move
	if (x < 0)
	{
		x = 0;
	}
	else if (x > SCREEN_WIDTH - rect.w)
	{
		
		x = SCREEN_WIDTH - rect.w;
	}
	if (y < 0)
	{
		y = 0;
	}
	else if (y > SCREEN_HEIGHT - rect.h)
	{
		y = SCREEN_HEIGHT - rect.h;
	}
}

void Character::render(SDL_Renderer* renderer)
{
	SDL_RenderCopyEx(renderer, texture, NULL, &rect, -direction, NULL, SDL_FLIP_NONE);//player
}