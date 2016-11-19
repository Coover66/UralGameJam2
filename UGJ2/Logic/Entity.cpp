#include "Entity.h"



Entity::Entity(int x, int y, SDL_Texture* _texture) : position(x, y), texture(_texture)
{
}


Entity::~Entity()
{
}

void Entity::render(SDL_Renderer* renderer)
{
	SDL_RenderCopyEx(renderer, texture, NULL, &rect, -direction, NULL, SDL_FLIP_NONE);//player
}