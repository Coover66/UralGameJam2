#pragma once
#include "../Project.h"
#include "Point.h"

class Entity
{
protected:
	SDL_Texture* texture;
	double direction;
public:
	Point position;
	SDL_Rect rect;//��� ����������� ��������, � ����� ��� �������� (� ���������� ���� ��������)

	Entity(int x, int y, SDL_Texture* _texture, double direction = 0, int _width = 32, int _height = 32);
	virtual ~Entity();

	bool checkCollision(SDL_Rect a, SDL_Rect b);
	void move(int dx, int dy);
	void moveTo(int x, int y); //���������� �� �������
	void render(SDL_Renderer* renderer);
};

