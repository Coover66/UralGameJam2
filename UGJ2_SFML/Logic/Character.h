#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Map.h"

class Character:
	public Entity
{
protected:
	int speed;
	sf::IntRect collisionRect;
	int toX, toY;//радиус-вектор направления
	sf::IntRect w;
	Map & map;
public:
	Character(int x, int y, sf::Texture* _texture, Map & _map, double _direction = 0, int _width = 32, int _height = 32, Entity* w = NULL);
	virtual ~Character();
	void move(float deltaTime, int dir);
	
};

