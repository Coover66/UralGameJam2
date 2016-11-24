#pragma once
#include <SFML/Graphics.hpp>

#include "Screen.h"
class Screen;

class Game
{
private:
	bool run;

	sf::RenderWindow* window;
	Screen* screen;

public:
	Game(void);
	~Game(void);
	int Execute(Screen* _screen, int width, int height);

	sf::RenderWindow* GetWindow();
	Screen* GetScreen();
	void SetScreen(Screen* screen);

	void Exit();
};

