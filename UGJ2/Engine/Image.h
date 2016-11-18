#pragma once
#include "../Project.h"
class Image
{
private:
	SDL_Surface* surf;
public:
	Image(void);
	~Image(void);	
	
	friend class Graphics;

	int GetWidth();
	int GetHeight();
};

