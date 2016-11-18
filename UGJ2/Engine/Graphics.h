#pragma once
#include "../Project.h"
#include <iostream>

#include "Image.h"

class Image;

class Graphics
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Surface* Screen;
public:
	Graphics(int width, int height);
	~Graphics(void);

	SDL_Renderer* gatRenderer();

	Image* NewImage(char* file); // Image ���� ��?
	Image* NewImage(char* file, int r, int g, int b);// Image ���� ��?
	bool DrawImage(Image* img, int x, int y);// Image ���� ��?
	bool DrawImage(Image* img, int x, int y, int startX, int startY, int endX, int endY);// Image ���� ��?

	SDL_Texture* loadTexture(std::string path);
	void Flip();
};

