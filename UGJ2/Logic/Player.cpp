#include "Player.h"



Player::Player(int x, int y, SDL_Texture* texture, double direction): Character(x, y, texture, direction) {}


Player::~Player()
{
}

void Player::movePlayer(int x, int y, int deltaTime)
{
	int toX = x - this->rect.x - this->rect.h/2;
	int toY = y - this->rect.y - this->rect.w / 2;
	this->move(toX, toY, deltaTime);
}
