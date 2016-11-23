#include <Windows.h>
#include "Project.h"
#include "Logic\MainMenuScreen.h"
#include "Logic\GameProcessScreen.h"
#include "Logic\Map.h"
#include "Logic\NPC.h"
#include <fstream>

class MyScreen : public Screen
{
private:
	Input* input;
	Graphics* graphics;
	SDL_Renderer* renderer;
	SDL_Texture* t1;
public:
	void Start()
	{
		input = game->GetInput();
		graphics = game->GetGraphics();
		renderer = graphics->gatRenderer();
		t1 = graphics->loadTexture("../Data/obshaga6.bmp");
		//MessageBox(0,"Kek","KekMessage",MB_OK);
	}
	void Update()
	{
		
		if(input->IsKeyDown(SDLK_ESCAPE) || input->IsExit())
			game->Exit();

		SDL_RenderCopy( renderer, t1, NULL, NULL);

		graphics->Flip();
	}
};

int main(int argc, char** argv)
{
	/*const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Init(SDL_INIT_EVERYTHING);	
	window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	screenSurface = SDL_GetWindowSurface( window );
	SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
	SDL_UpdateWindowSurface( window );
	SDL_Delay( 2000 );
	SDL_DestroyWindow( window );	
	SDL_Quit();
	*/

	Game game;
	return game.Execute(new GameProcessScreen(), 640,480);//MainMenuScreen()
}