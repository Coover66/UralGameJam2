#pragma once
#include "../Project.h"
#include <Windows.h>

class Input
{
public:
	SDL_Event evt;

public:
	Input(void);
	~Input(void);

	void Update();
	
	bool IsMouseButtonDown(Uint8 key);
	bool IsMouseButtonUp(Uint8 key);
	POINT GetButtonDownCoords();

	bool IsKeyDown(Uint8 key);
	bool IsKeyUp(Uint8 key);
	Uint8 GetPressedKey();

	bool IsExit();
};

