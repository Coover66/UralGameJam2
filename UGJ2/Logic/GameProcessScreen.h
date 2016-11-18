#pragma once
#include "../Engine/Project.h"
#include "../Engine/Screen.h"

class GameProcessScreen :
	public Screen
{
private:
	Input* input;
	Graphics* graphics;
	SDL_Renderer* renderer;
	Character* player;
	SDL_Texture* t1;
	SDL_Texture* t2;
	SDL_Rect r;
	SDL_Rect* r1;
	double angle = 45;
	int yDirection = 1;
	int mX = 0, mY = 0;
	double kek1;

public:
	GameProcessScreen();
	virtual ~GameProcessScreen();
	void Start();
	void Update();
	void Destroy();
};

