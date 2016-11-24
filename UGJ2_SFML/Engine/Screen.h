#pragma once

#include "Game.h"
class Game;

class Screen
{
protected:
	Game* game;
public:
	Screen(void);
	~Screen(void);

	void SetController(Game* game);

	virtual void Start();
	virtual void Update();
	virtual void Destroy();
};

