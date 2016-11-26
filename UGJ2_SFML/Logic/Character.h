#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Character:
	public Entity
{
protected:
	int speed;
	sf::IntRect collisionRect;
	int toX, toY;//������-������ �����������
	sf::IntRect w;
public:
	Character(int x, int y, sf::Texture* _texture, double _direction = 0, int _width = 32, int _height = 32, Entity* w = NULL);
	virtual ~Character();
	void move(float deltaTime, int dir);
	
};

