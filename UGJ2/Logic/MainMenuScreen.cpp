#include "MainMenuScreen.h"
#include "GameProcessScreen.h"

MainMenuScreen::MainMenuScreen()
{
}


MainMenuScreen::~MainMenuScreen()
{
}

void MainMenuScreen::Start()
{
	input = game->GetInput();
	graphics = game->GetGraphics();
	renderer = graphics->gatRenderer();
	t1 = graphics->loadTexture("../Data/obshaga6.bmp");

}

void MainMenuScreen::Update()
{
	while (SDL_PollEvent(&input->evt)) {
		if (input->IsKeyDown(SDLK_ESCAPE) || input->IsExit())
			game->Exit();
		if (input->IsKeyUp(SDLK_RETURN))
		{
			game->SetScreen(new GameProcessScreen());
			return;
		}
	}
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, t1, NULL, NULL);

	graphics->Flip();
}

void MainMenuScreen::Destroy()
{
	SDL_DestroyTexture(t1);

}