#pragma once
#include "Character.h"
class Player :
	public Character
{
public:
	Player(int x, int y, VecVecBool & map, SDL_Texture* texture, double direction);;
	virtual ~Player();
};

