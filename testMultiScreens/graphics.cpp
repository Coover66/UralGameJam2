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
	bool menu = true;

	bool out = false;
	bool kek = false;
	SDL_Texture* t1 = loadTexture("../Data/grass.bmp");
	SDL_Texture* t2 = loadTexture("../Data/SNOW.BMP");
	SDL_Texture* t3 = loadTexture("../Data/obshaga6.bmp");
	SDL_SetTextureBlendMode (t2, SDL_BLENDMODE_ADD);
	SDL_Rect r = {10,10,100,100};
	SDL_Rect* r1;
	double angle = 45;
	int yDirection = 1;
	int mX=0, mY=0;
	double kek1;
	//r1 = {100,100,0,0};
	SDL_RenderCopyEx(renderer, t2, NULL, &r, 0, NULL, SDL_FLIP_NONE);
	while (!out)
	{

		while (SDL_PollEvent(&evt)) {
			if (evt.type == SDL_QUIT) out = true;
			if (evt.type == SDL_KEYUP &&  evt.key.keysym.sym == SDLK_ESCAPE) out = true;
			if (evt.type == SDL_KEYDOWN && evt.key.keysym.sym == (Uint8)'m') menu = !menu;
			if (!menu)
			{
				if (evt.type == SDL_KEYDOWN && evt.key.keysym.sym == (Uint8)'w') { r.x += mX / kek1; r.y += mY / kek1; }
				if (evt.type == SDL_KEYDOWN && evt.key.keysym.sym == (Uint8)'s') { r.x -= mX / kek1; r.y -= mY / kek1; }
				if (evt.type == SDL_KEYDOWN && evt.key.keysym.sym == (Uint8)'a') r.x--;
				if (evt.type == SDL_KEYDOWN && evt.key.keysym.sym == (Uint8)'d') r.x++;
				if (evt.type == SDL_MOUSEMOTION)
				{
					mX = evt.motion.x - r.x - r.h / 2;
					mY = evt.motion.y - r.y - r.w / 2;

					if (mY != 0 && mY != 0)
					{
						kek1 = sqrt((double)abs(mX*mX + mY*mY)) / 10;
						angle = atan2(mX, mY) / M_PI * 180;
					}
					std::cout << mX << " " << mY << " " << angle << std::endl;
				}
			}

		}




		SDL_RenderClear(renderer);

		if (!menu)
		{
			SDL_RenderCopy(renderer, t1, NULL, NULL);//background
			SDL_RenderCopyEx(renderer, t2, NULL, &r, -angle, NULL, SDL_FLIP_NONE);//player
		}
		else 
			SDL_RenderCopy(renderer, t3, NULL, NULL);


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
