#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
//class Input;
#include "Character.h"
class Player :
	public Character
{
public:
	Player(int x, int y, sf::Texture* texture, Map & _map, double direction = 0, int _width = 32, int _height = 32, Entity* w = NULL);
	virtual ~Player();

	void rotatePlayer(int x, int y);
	void updateInput(sf::Event* input, int deltaTime);

};

