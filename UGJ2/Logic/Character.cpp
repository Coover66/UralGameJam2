#include "Character.h"

Character::Character(int x, int y, SDL_Texture* _texture, double direction) : Entity(x, y, _texture)
{
	rect = { 10,10,100,100 };
}


Character::~Character()
{
}

void Character::move(int toX, int toY, float deltaTime)
{
	int ratio = 1;
	if (toY != 0 && toY != 0)
	{
		ratio = sqrt((double)abs(toX*toX + toY*toY)) / 10 * deltaTime;
		direction = atan2(toX, toY) / M_PI * 180;
	}//нет else, т.е. может упасть, если долго не будет изменений

//	position.x += toX / ratio;
//	position.y += toY / ratio;

	if (position.x < 0)
	{
		position.x = 0;
	}
	else if (position.x > SCREEN_WIDTH - rect.w)
	{
		
		position.x = SCREEN_WIDTH - rect.w;
	}
	if (position.y < 0)
	{
		position.y = 0;
	}
	else if (position.y > SCREEN_HEIGHT - rect.h)
	{
		position.y = SCREEN_HEIGHT - rect.h;
	}
}