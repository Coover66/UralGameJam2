#include "Character.h"

Character::Character(int x, int y, sf::Texture* _texture, Map & _map,
					double _direction, int _width, int _height, Entity* _w)
					: Entity(x, y, _texture, _direction, _width, _height), map(_map)
{
	toX = 0;
	toY = 0;
	speed = 4;
	collisionRect = { x - (int)(_width *0.25), y - (int)(_height *0.25), (int)(_width*0.5), (int)( _height*0.5) };
	if (_w)
		w = { _w->rect.left , _w->rect.top, _w->rect.width, _w->rect.height };

		//w.x = _w->rect.x;
}


Character::~Character()
{
}

void Character::move(float deltaTime, int dir)
{
	//dir - направление, 1 - вперед, -1 - назад, TODO: исправить (сейчас(21.11.2016 9:00) вызываем только в Player::updateInput)
	int ratio = 1;
	if (toX != 0 || toY != 0)
		if (deltaTime > 0)
			ratio = sqrt((double)(toX*toX + toY*toY)) / speed * deltaTime;
			//нет else, т.е. может упасть, если долго не будет изменений
	if (ratio > 0)
	{
		int toXDivRatio = (int)dir*toX / ratio;
		int toYDivRatio = (int)dir*toY / ratio;
		if (!checkCollision(sf::IntRect{ collisionRect.left +toXDivRatio, collisionRect.top+toYDivRatio, collisionRect.width, collisionRect.height } , w))
		{		
			position.x += toXDivRatio;
			position.y += toYDivRatio;
			rect.left += toXDivRatio;
			rect.top += toYDivRatio;
			collisionRect.left += toXDivRatio;
			collisionRect.top += toYDivRatio;
		}
	}

}