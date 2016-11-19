#include "Player.h"



Player::Player(int x, int y, VecVecBool & map, SDL_Texture* texture, double direction): Character(x, y, texture, direction) {}


Player::~Player()
{
}
