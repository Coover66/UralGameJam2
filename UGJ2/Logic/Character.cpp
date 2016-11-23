#include "Character.h"

Character::Character(int x, int y, SDL_Texture* _texture, 
					double _direction, int _width, int _height, Entity* _w)
					: Entity(x, y, _texture, _direction, _width, _height)
{
	toX = 0;
	toY = 0;
	speed = 4;
	collisionRect = { x - (int)(_width *0.25), y - (int)(_height *0.25), (int)(_width*0.5), (int)( _height*0.5) };
	if (_w)
		w = { _w->rect.x , _w->rect.y, _w->rect.w, _w->rect.h };

		//w.x = _w->rect.x;
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
		int toXDivRatio = (int)dir*toX / ratio;
		int toYDivRatio = (int)dir*toY / ratio;
		if (!checkCollision(SDL_Rect { collisionRect.x +toXDivRatio, collisionRect.y+toYDivRatio, collisionRect.w, collisionRect.h } , w))
		{		
			position.x += toXDivRatio;
			position.y += toYDivRatio;
			rect.x += toXDivRatio;
			rect.y += toYDivRatio;
			collisionRect.x += toXDivRatio;
			collisionRect.y += toYDivRatio;
		}
	}

}