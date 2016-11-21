#include "Player.h"



Player::Player(int x, int y, SDL_Texture* texture, double direction): Character(x, y, texture, direction) {}


Player::~Player()
{
}

void Player::movePlayer(int x, int y, int deltaTime)
{
	int toX = x - this->rect.x - this->rect.h/2;
	int toY = y - this->rect.y - this->rect.w / 2;
	//this->move(toX, toY, deltaTime);
}

void Player::rotatePlayer(int x, int y)
{
	toX = x - this->rect.x - this->rect.h / 2;
	toY = y - this->rect.y - this->rect.w / 2;
	direction = atan2(toX, toY) / M_PI * 180;
}

void Player::updateInput(Input* input, int deltaTime)
{
	if (input->IsKeyDown('w'))
		this->move(deltaTime, 1);
	if (input->IsKeyDown('s')) 
		this->move(deltaTime, -1);
	//if (input->IsKeyDown('a')) {}
	//if (input->IsKeyDown('d')) {}
	if (input->evt.type == SDL_MOUSEMOTION)
		this->rotatePlayer(input->evt.motion.x, input->evt.motion.y);
}
