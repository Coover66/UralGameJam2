#pragma once
#include "../Project.h"
//class Input;
#include "Character.h"
class Player :
	public Character
{
public:
	Player(int x, int y, SDL_Texture* texture, Map & _map, double direction = 0, int _width = 32, int _height = 32, Entity* w = NULL);
	virtual ~Player();

	void rotatePlayer(int x, int y);
	void updateInput(Input* input, int deltaTime);

};

