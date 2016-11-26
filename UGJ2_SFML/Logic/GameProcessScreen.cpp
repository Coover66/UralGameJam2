#include "GameProcessScreen.h"
#include "Menu.h"
using namespace sf;

GameProcessScreen::GameProcessScreen()
{
}


GameProcessScreen::~GameProcessScreen()
{
}

void GameProcessScreen::Start()
{
	window = game->GetWindow();
	std::ofstream s("kek.txt");
	t1 = new Texture();
	t1->loadFromFile("../Data/grass.bmp");
	t2 = new Texture();
	t2->loadFromFile("../Data/SNOW.BMP");
	stone = new Texture();
	stone->loadFromFile("../Data/stone.BMP");

	//SDL_SetTextureBlendMode(t2, SDL_BLENDMODE_ADD);
	
	wall = new Entity(200, 480/2, stone,0,50,200);
	player = new Player(640 / 2, 480 / 2, t2, 0, 100, 100, wall);
	
	clock.restart();
}

void GameProcessScreen::Update()
{
	/*capTimer.start();
	float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
	float  deltaTime = avgFPS / SCREEN_FPS;

	while (SDL_PollEvent(&input->evt)) {
		if (input->IsKeyDown(SDLK_ESCAPE) || input->IsExit()) game->Exit();		
		if (input->IsKeyUp(SDLK_RETURN)){ game->SetScreen(new MainMenuScreen()); return; }
		player->updateInput(input, deltaTime);	
	}

	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, t1, NULL, NULL);//background
	player->render(renderer);
	wall->render(renderer);

	graphics->Flip();

	countedFrames++;
	int frameTicks = capTimer.getTicks();
	if (frameTicks < SCREEN_TICKS_PER_FRAME)
		SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);	*/
	while (window->isOpen())
	{
		float time = clock.getElapsedTime().asMilliseconds();
		clock.restart();
			Event event;
			while (window->pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					game->Exit();
					return;
				}
				if (event.type == Event::KeyPressed)
				{
					if (event.key.code == Keyboard::Escape)
					{
						game->Exit();
						return;
					}
					if (event.key.code == Keyboard::Return)
					{
						game->SetScreen(new Menu());
						return;
					}
				}
				player->updateInput(&event, time);
			}
			
			window->clear(Color(107, 140, 255));
			player->render(window);
			window->display();
			clock.restart();
	}
}

void GameProcessScreen::Destroy()
{
}