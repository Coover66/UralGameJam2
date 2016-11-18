#include "Graphics.h"
#include "SDL.h"
Graphics::Graphics(int width, int height)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Ural Game Jam 2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 128, 255, 0, 255);

	//Screen = SDL_CreateRGBSurface(0, width,height,32,0x00FF0000,0x0000FF00,0x000000FF,0xFF000000);
}


Graphics::~Graphics(void)
{
}

SDL_Renderer * Graphics::gatRenderer()
{
	return renderer;
}

Image* Graphics::NewImage(char* file)
{
	Image* image = new Image();
	image->surf = SDL_ConvertSurface(SDL_LoadBMP(file),Screen->format,NULL);

	return image;
}

Image* Graphics::NewImage(char* file, int r, int g, int b)
{
	Image* image = new Image();
	image->surf = SDL_ConvertSurface(SDL_LoadBMP(file),Screen->format,NULL);

	SDL_SetColorKey(image->surf, SDL_TRUE | SDL_RLEACCEL,
		SDL_MapRGB(image->surf->format, r, g, b));

	return image;
}

bool Graphics::DrawImage(Image* img, int x, int y)
{
	if(Screen == NULL || img->surf == NULL)
        return false;
 
    SDL_Rect Area;
    Area.x = x;
    Area.y = y;
 
    SDL_BlitSurface(img->surf, NULL, Screen, &Area);
 
	return true;
}

bool Graphics::DrawImage(Image* img, int x, int y, int startX, int startY, int endX, int endY)
{
	if(Screen == NULL || img->surf == NULL)
        return false;
 
    SDL_Rect Area;
    Area.x = x;
    Area.y = y;

    SDL_Rect SrcArea;
	SrcArea.x = startX;
	SrcArea.y = startY;
	SrcArea.w = endX;
	SrcArea.h = endY;

	SDL_BlitSurface(img->surf, &SrcArea, Screen, &Area);

	return true;
}

SDL_Texture* Graphics::loadTexture(std::string path)
{
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);

	return newTexture;
}

void Graphics::Flip()
{
	//SDL_Flip(Screen);
	//SDL_FillRect(Screen,NULL, 0x000000);
	SDL_RenderPresent(renderer);
}
