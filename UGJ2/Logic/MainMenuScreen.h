#pragma once
#include "../Project.h"
#include "../Engine/Screen.h"

class MainMenuScreen :	public Screen
{
private:
	Input* input;
	Graphics* graphics;
	SDL_Renderer* renderer;
	SDL_Texture* t1;
	

public:
	MainMenuScreen();
	virtual ~MainMenuScreen();
	void Start();
	void Update();
	void Destroy();
};

