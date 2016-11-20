#pragma once
#include "Character.h"
class Player :
	public Character
{
public:
	Player(int x, int y, SDL_Texture* texture, double direction);;
	virtual ~Player();

	void movePlayer(int x, int y, int deltaTime);
};

