#pragma once
#include "../Project.h"
#include "Entity.h"

class Character:
	public Entity
{
protected:
	int speed;
	
public:
	Character(int x, int y, SDL_Texture* _texture, double _direction = 0);
	virtual ~Character();
	void move(float deltaTime, int dir);
	
};

