#include "Character.h"



Character::Character(int x, int y, SDL_Texture* _texture, double direction) : position(x, y), texture(_texture)
{
	rect = { 10,10,100,100 };
}


Character::~Character()
{
}

void Character::move(int toX, int toY, float deltaTime)
{
	//TODO: move
	if (position.x < 0)
	{
		position.x = 0;
	}
	else if (position.x > SCREEN_WIDTH - rect.w)
	{
		
		position.x = SCREEN_WIDTH - rect.w;
	}
	if (position.y < 0)
	{
		position.y = 0;
	}
	else if (position.y > SCREEN_HEIGHT - rect.h)
	{
		position.y = SCREEN_HEIGHT - rect.h;
	}
}

void Character::render(SDL_Renderer* renderer)
{
	SDL_RenderCopyEx(renderer, texture, NULL, &rect, -direction, NULL, SDL_FLIP_NONE);//player
}