#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
class Door :
	public Entity
{
public:
	Door(int x, int y, sf::Texture* _texture);
	virtual ~Door();
};

