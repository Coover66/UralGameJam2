#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
class GlassWindow :
	public Entity
{
public:
	GlassWindow(int x, int y, sf::Texture* _texture);
	virtual ~GlassWindow();
};

