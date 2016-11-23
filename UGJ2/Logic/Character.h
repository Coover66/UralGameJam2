#pragma once
#include "../Project.h"
#include "Entity.h"

class Character:
	public Entity
{
protected:
	int speed;
	SDL_Rect collisionRect;
	int toX, toY;//радиус-вектор направления
	SDL_Rect w;
public:
	Character(int x, int y, SDL_Texture* _texture, double _direction = 0, int _width = 32, int _height = 32, Entity* w = NULL);
	virtual ~Character();
	void move(float deltaTime, int dir);
	
};

