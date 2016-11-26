#include "Player.h"



Player::Player(int x, int y, sf::Texture* texture,
				double direction, int _width, int _height, Entity* _w)
				: Character(x, y, texture, direction, _width, _height, _w) {}


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
			this->move(deltaTime, 1);
		if (evt->key.code == sf::Keyboard::S)
			this->move(deltaTime, -1);
		//if (input->IsKeyDown('a')) {}
		//if (input->IsKeyDown('d')) {}
	}
	if (evt->type == sf::Event::MouseMoved)
		this->rotatePlayer(evt->mouseMove.x, evt->mouseMove.y);
}
