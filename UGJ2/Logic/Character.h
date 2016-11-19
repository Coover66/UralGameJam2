#pragma once
#include "../Project.h"
#include "Entity.h"

class Character:
	public Entity
{
protected:
	int speed;
public:
	Character(int x, int y, SDL_Texture* texture, double direction = 0);
	virtual ~Character();
	void move(int toX, int toY, float deltaTime);
	
};

