#include "Player.h"



Player::Player(int x, int y, SDL_Texture* texture, Map & _map,
				double direction, int _width, int _height, Entity* _w)
				: Character(x, y, texture, _map, direction, _width, _height, _w) {}


Player::~Player()
{
}

void Player::rotatePlayer(int x, int y)
{
	toX = x - position.x;
	toY = y - position.y;
	direction = atan2(toX, toY) / M_PI * 180;
}

void Player::updateInput(Input* input, int deltaTime)
{
	if (input->IsKeyDown('w'))
		Character::move(deltaTime, 1);
	if (input->IsKeyDown('s')) 
		Character::move(deltaTime, -1);
	//if (input->IsKeyDown('a')) {}
	//if (input->IsKeyDown('d')) {}
	if (input->evt.type == SDL_MOUSEMOTION)
		this->rotatePlayer(input->evt.motion.x, input->evt.motion.y);
}
