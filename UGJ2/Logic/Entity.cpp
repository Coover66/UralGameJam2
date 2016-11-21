#include "Entity.h"



Entity::Entity(int x, int y, SDL_Texture* _texture, double _direction) : position(x, y), texture(_texture)
{
	direction = _direction;
	int halfOfSize = 45;
	rect = { x - halfOfSize, y - halfOfSize, 2*halfOfSize, 2*halfOfSize };
}


Entity::~Entity()
{
}

void Entity::render(SDL_Renderer* renderer)
{
	SDL_RenderCopyEx(renderer, texture, NULL, &rect, -direction, NULL, SDL_FLIP_NONE);
}