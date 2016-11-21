#include "Character.h"

Character::Character(int x, int y, SDL_Texture* _texture, double _direction) : Entity(x, y, _texture, _direction)
{
	
	toX = 0;
	toY = 0;
	speed = 4;
}


Character::~Character()
{
}

void Character::move(float deltaTime, int dir)
{
	//dir - �����������, 1 - ������, -1 - �����, TODO: ��������� (������(21.11.2016 9:00) �������� ������ � Player::updateInput)
	int ratio = 1;
	if (toX != 0 || toY != 0)
		if (deltaTime > 0)
			ratio = sqrt((double)(toX*toX + toY*toY)) / speed * deltaTime;
			//��� else, �.�. ����� ������, ���� ����� �� ����� ���������
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