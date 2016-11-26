#pragma once

#include <SFML/Graphics.hpp>
#include "../Engine/Screen.h"
#include "GameProcessScreen.h"

class Menu :
	public Screen
{
private:
	sf::RenderWindow* window;
	sf::Clock clock;
	sf::Texture* tileSet;
	sf::Sprite* tile;


public:
	Menu();
	virtual ~Menu();
	void Start();
	void Update();
	void Destroy();
};

