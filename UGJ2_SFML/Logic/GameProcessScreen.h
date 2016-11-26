#pragma once
#include <SFML/Graphics.hpp>
#include "../Engine/Screen.h"
#include <iostream>
#include <fstream>
//#include "Character.h"
#include "Player.h"

class GameProcessScreen :
	public Screen
{
private:
	sf::RenderWindow* window;
	sf::Clock clock;

	Player* player;
	Entity* wall;//for test collision
	sf::Texture* t1;
	sf::Texture* t2;
	sf::Texture* stone;
	
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

