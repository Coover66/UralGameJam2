#include "SDL.h"
#include "graphics.h"

int main(int argc, char** argv)
{
	SDL_Window* window;
	SDL_Renderer* renderer;

	
	graphics g(640,640);
	g.run();
	g.~graphics();
	/*
	window = SDL_CreateWindow("kek", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512,512,0);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 128,255,0,255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(2000);
	SDL_SetRenderDrawColor(renderer, 128,255,255,255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(2000);
	SDL_Quit();
	*/
	return 0;
}