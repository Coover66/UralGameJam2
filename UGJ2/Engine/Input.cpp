#include "Input.h"
#include <Windows.h>

Input::Input(void)
{
}


Input::~Input(void)
{
}

void Input::Update()
{
	while(SDL_PollEvent(&evt));
}

bool Input::IsMouseButtonDown(Uint8 key)
{
	if(evt.type == SDL_MOUSEBUTTONDOWN)
		if(evt.button.button == key)
			return true;
	return false;
}

bool Input::IsMouseButtonUp(Uint8 key)
{
	if(evt.type == SDL_MOUSEBUTTONUP)
		if(evt.button.button == key)
			return true;
	return false;
}

POINT Input::GetButtonDownCoords()
{
	POINT point;
	point.x = evt.button.x;
	point.y = evt.button.y;

	return point;
}

bool Input::IsKeyDown(Uint8 key)
{
	return (evt.type == SDL_KEYDOWN && evt.key.keysym.sym == key);
}

bool Input::IsKeyUp(Uint8 key)
{
	return (evt.type == SDL_KEYUP && evt.key.keysym.sym == key);
}

Uint8 Input::GetPressedKey()
{
	return evt.key.keysym.sym;
}

bool Input::IsExit()
{
	return (evt.type == SDL_QUIT);
}