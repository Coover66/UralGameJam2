#include "GameProcessScreen.h"
#include "MainMenuScreen.h"

GameProcessScreen::GameProcessScreen()
{
}


GameProcessScreen::~GameProcessScreen()
{
}

void GameProcessScreen::Start()
{
	input = game->GetInput();
	graphics = game->GetGraphics();
	renderer = graphics->gatRenderer();
	t1 = graphics->loadTexture("../Data/grass.bmp");
	t2 = graphics->loadTexture("../Data/WindowTmp.bmp");
	stone = graphics->loadTexture("../Data/stone.BMP");	
	wall = new Entity(200, 480/2, stone,0,50,200);	
	map = new Map(graphics->loadTexture("../Data/WallTmp.bmp"),
		graphics->loadTexture("../Data/WindowTmp.bmp"),
		graphics->loadTexture("../Data/DoorTmp.bmp"),
		graphics->loadTexture("../Data/DoorTmp.bmp"),
		graphics->loadTexture("../Data/FloorTmp.bmp"));
	map->update(Point(0, 0));
	player = new Player(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, graphics->loadTexture("../Data/SNOW.BMP"), *map, 0, 32, 32, wall);

	fpsTimer.start();
}

void GameProcessScreen::Update()
{
	capTimer.start();
	float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
	float  deltaTime = avgFPS / SCREEN_FPS;

	while (SDL_PollEvent(&input->evt)) {
		if (input->IsKeyDown(SDLK_ESCAPE) || input->IsExit()) game->Exit();		
		if (input->IsKeyUp(SDLK_RETURN)){ game->SetScreen(new MainMenuScreen()); return; }
		player->updateInput(input, deltaTime);	
	}

	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, t1, NULL, NULL);//background
	
	wall->render(renderer);
	map->render(renderer);
	player->render(renderer);
	graphics->Flip();
	
	countedFrames++;
	int frameTicks = capTimer.getTicks();
	if (frameTicks < SCREEN_TICKS_PER_FRAME)
		SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);	
}

void GameProcessScreen::Destroy()
{
}