#include "graphics.h"
#include <iostream>

graphics::graphics(int width, int height)
{
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("kek", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 128,255,0,255);
}

void graphics::run()
{
	bool out = false;
	bool kek = false;
	SDL_Texture* t1 = loadTexture("grass.bmp");
	SDL_Texture* t2 = loadTexture("SNOW.BMP");
	SDL_SetTextureBlendMode (t2, SDL_BLENDMODE_ADD);
	SDL_Rect r = {10,10,10,10};
	SDL_Rect* r1;
	//r1 = {100,100,0,0};
	SDL_RenderCopyEx(renderer, t2, NULL, &r, 0, NULL, SDL_FLIP_NONE);
	while (!out)
	{
		
		while(SDL_PollEvent(&evt)){
			if( evt.type == SDL_QUIT ) out = true;
            if( evt.type == SDL_KEYUP &&
                evt.key.keysym.sym == SDLK_ESCAPE ) out = true;
			if( evt.type == SDL_KEYUP &&
				evt.key.keysym.sym == (Uint8)'w' ) 
					kek = !kek;
		}
		SDL_RenderClear(renderer);
		//if (kek)		
			SDL_RenderCopy(renderer, t1 ,NULL,NULL);
		//else
			SDL_RenderCopy(renderer, t2 ,NULL,NULL);

		SDL_RenderPresent(renderer);

		SDL_Delay(33);
	}
}

graphics::~graphics(void)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

SDL_Texture* graphics::loadTexture( std::string path )
{
	SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
    SDL_Texture* newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
    SDL_FreeSurface( loadedSurface );

    return newTexture;
}
