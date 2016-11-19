#pragma once
#include "Entity.h"
class Door :
	public Entity
{
public:
	Door(int x, int y, SDL_Texture* _texture);
	virtual ~Door();
};

