#pragma once
#include "Entity.h"
class GlassWindow :
	public Entity
{
public:
	GlassWindow(int x, int y, SDL_Texture* _texture);
	virtual ~GlassWindow();
};

