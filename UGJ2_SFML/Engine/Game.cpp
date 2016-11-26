#include "Game.h"

Game::Game(void){	run = true; }
Game::~Game(void){}

int Game::Execute(Screen* _screen, int width, int height)
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), sf::String("kek"));
	screen = _screen;

	screen->SetController(this);
	this->screen->Start();

	while(run)
		screen->Update();

	delete screen;
	//SDL_Quit();
	return 0;
}

sf::RenderWindow*  Game::GetWindow()
{
	return window;
}

Screen* Game::GetScreen()
{
	return screen;
}
	
void Game::SetScreen(Screen* _screen)
{
	this->screen->Destroy();
	delete this->screen;
	this->screen = _screen;
	this->screen->SetController(this);
	this->screen->Start();
}

void Game::Exit()
{
	run = false;
	screen->Destroy();
}

