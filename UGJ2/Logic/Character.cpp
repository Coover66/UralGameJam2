#include "Character.h"

Character::Character(int x, int y, SDL_Texture* _texture, double _direction) : Entity(x, y, _texture, _direction)
{
	
	toX = 0;
	toY = 0;
}


Character::~Character()
{
}

void Character::move(float deltaTime, int dir)
{
	int ratio = 1;
	if (toX != 0 || toY != 0)
		if (deltaTime > 0)
			ratio = sqrt((double)(toX*toX + toY*toY)) / 10 * deltaTime;
			//нет else, т.е. может упасть, если долго не будет изменений
	if (ratio > 0)
	{
		double toXDivRatio = dir*toX / ratio;
		double toYDivRatio = dir*toY / ratio;
		position.x += toXDivRatio;
		position.y += toYDivRatio;
		rect.x += toXDivRatio;
		rect.y += toYDivRatio;
	}

}