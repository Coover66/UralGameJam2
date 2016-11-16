#pragma once
#include "SDL.h"
#include <iostream>

class graphics
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event evt;
public:
	graphics(int width, int height);
	virtual ~graphics(void);
	void run();
	SDL_Texture* graphics::loadTexture( std::string path );
};

