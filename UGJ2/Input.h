#pragma once
#include "Project.h"

class Input
{
private:
	SDL_Event evt;

public:
	Input(void);
	~Input(void);

	void Update();
	
	bool IsMouseButtonDown(Uint8 key);
	bool IsMouseButtonUp(Uint8 key);
	//POINT GetButtonDownCoords();

	bool IsKeyDown(Uint8 key);
	bool IsKeyUp(Uint8 key);
	Uint8 GetPressedKey();

	bool IsExit();
};

