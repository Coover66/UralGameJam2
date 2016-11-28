#pragma once

#include <SFML/Graphics.hpp>
#include "Point.h"
class Entity
{
protected:
	sf::Texture* texture;
	double direction;
public:
	Point position;
	sf::IntRect rect;//��� ����������� ��������, � ����� ��� �������� (� ���������� ���� ��������)
	sf::Sprite sprite;

	Entity(int x, int y, sf::Texture* _texture, double _direction = 0, int _width = 32, int _height = 32);
	virtual ~Entity();

	bool checkCollision(sf::IntRect a, sf::IntRect b);
	void render(sf::RenderWindow* window);
};

