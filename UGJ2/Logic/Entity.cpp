#include "Entity.h"



Entity::Entity(int x, int y, SDL_Texture* _texture, double _direction, int _width, int _height) : position(x, y), texture(_texture)
{
	direction = _direction;
	rect = { x - (int)_width/2, y - (int)_height/2, _width,  _height };
}


Entity::~Entity()
{
}

bool Entity::checkCollision(SDL_Rect a, SDL_Rect b)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;
	
	//If any of the sides from A are outside of B
	if (bottomA <= topB)
		return false;

	if (topA >= bottomB)
		return false;

	if (rightA <= leftB)
		return false;

	if (leftA >= rightB)
		return false;

	//If none of the sides from A are outside B
	return true;
}

void Entity::move(int dx, int dy)
{
	rect.x += dx;
	rect.y += dy;
	position.x += dx;
	position.y += dy;
}

void Entity::moveTo(int x, int y)
{
	rect.x = x;
	rect.y = y;
	position.x = x;
	position.y = y;
}

void Entity::render(SDL_Renderer* renderer)
{
	SDL_RenderCopyEx(renderer, texture, NULL, &rect, -direction, NULL, SDL_FLIP_NONE);
}