#include "Player.h"



Player::Player(int x, int y, sf::Texture* texture, Map & _map,
				double direction, int _width, int _height, Entity* _w)
				: Character(x, y, texture, _map, direction, _width, _height, _w) {}


Player::~Player()
{
}

void Player::rotatePlayer(int x, int y)
{
	//toX = x - position.x;
	//toY = y - position.y;
	direction = atan2(toX, toY) / 3.1485 * 180;
}

void Player::updateInput(sf::Event* evt, int deltaTime)
{
	if (evt->type == sf::Event::KeyPressed)
	{
		if (evt->key.code == sf::Keyboard::W)
			map.update(Point(0, -sprite.getTextureRect().height));
			//sprite.move(sf::Vector2f(0, -sprite.getTextureRect().height));
		if (evt->key.code == sf::Keyboard::S)
			map.update(Point(0, sprite.getTextureRect().height));
			//sprite.move(sf::Vector2f(0, sprite.getTextureRect().height));
		if (evt->key.code == sf::Keyboard::A)
			map.update(Point(-sprite.getTextureRect().width, 0));
			//sprite.move(sf::Vector2f(-sprite.getTextureRect().width, 0));
		if (evt->key.code == sf::Keyboard::D)
			map.update(Point(sprite.getTextureRect().width, 0));
			//sprite.move(sf::Vector2f(sprite.getTextureRect().width, 0));
	}
	//if (evt->type == sf::Event::MouseMoved)
	//	this->rotatePlayer(evt->mouseMove.x, evt->mouseMove.y);
}
