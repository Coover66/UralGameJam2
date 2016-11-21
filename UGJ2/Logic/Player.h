#pragma once
#include "../Project.h"
//class Input;
#include "Character.h"
class Player :
	public Character
{
public:
	Player(int x, int y, SDL_Texture* texture, double direction = 0);;
	virtual ~Player();

	void movePlayer(int x, int y, int deltaTime);
	void rotatePlayer(int x, int y);
	void updateInput(Input* input, int deltaTime);

};

