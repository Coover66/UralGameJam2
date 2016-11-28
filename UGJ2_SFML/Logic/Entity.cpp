#include "Entity.h"



Entity::Entity(int x, int y, sf::Texture* _texture, double _direction, int _width, int _height) : position(x, y), texture(_texture)
{
	direction = _direction;
	rect = { x - (int)_width/2, y - (int)_height/2, _width,  _height };
	sprite.setTexture(*_texture);
}


Entity::~Entity()
{
}

bool Entity::checkCollision(sf::IntRect a, sf::IntRect b)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A////////////////////////////swap? top/left width/height 
	leftA = a.height;
	rightA = a.height + a.width;
	topA = a.top;
	bottomA = a.top + a.height;

	//Calculate the sides of rect B
	leftB = b.left;
	rightB = b.left + b.width;
	topB = b.top;
	bottomB = b.top + b.height;
	
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

void Entity::render(sf::RenderWindow* window)
{
	window->draw(sprite);
	//SDL_RenderCopyEx(renderer, texture, NULL, &rect, -direction, NULL, SDL_FLIP_NONE);
}