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
	t2 = graphics->loadTexture("../Data/SNOW.BMP");
	SDL_SetTextureBlendMode(t2, SDL_BLENDMODE_ADD);
	r = { 10,10,100,100 };
	
	player = new Player(55, 55, t2, 0);

	fpsTimer.start();
}

void GameProcessScreen::Update()
{
	capTimer.start();
	float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
	if (avgFPS > 2000000)
	{
		//avgFPS = 0;
	}

	while (SDL_PollEvent(&input->evt)) {

		if (input->IsKeyDown(SDLK_ESCAPE) || input->IsExit())
			game->Exit();
		SDL_RenderClear(renderer);

		if (input->IsKeyUp(SDLK_RETURN))
		{
			game->SetScreen(new MainMenuScreen());
			return;
		}
		//------------------------------
		if (input->evt.type == SDL_KEYDOWN && input->evt.key.keysym.sym == (Uint8)'w') { 
			player->move(input->evt.motion.x, input->evt.motion.y, avgFPS / SCREEN_FPS);

			//r.x += mX / kek1; r.y += mY / kek1; 
		}
		if (input->evt.type == SDL_KEYDOWN && input->evt.key.keysym.sym == (Uint8)'s') { r.x -= mX / kek1; r.y -= mY / kek1; }
		if (input->evt.type == SDL_KEYDOWN && input->evt.key.keysym.sym == (Uint8)'a') r.x--;
		if (input->evt.type == SDL_KEYDOWN && input->evt.key.keysym.sym == (Uint8)'d') r.x++;
		if (input->evt.type == SDL_MOUSEMOTION)
		{
			
			mX = input->evt.motion.x - r.x - r.h / 2;
			mY = input->evt.motion.y - r.y - r.w / 2;
			player->move(input->evt.motion.x, input->evt.motion.y, avgFPS/SCREEN_FPS);

			
			if (mY != 0 && mY != 0)
			{
				kek1 = sqrt((double)abs(mX*mX + mY*mY)) / 10*avgFPS/SCREEN_FPS;
				angle = atan2(mX, mY) / M_PI * 180;
			}//нет else, т.е. может упасть, если долго не будет изменений
			std::cout << mX << " " << mY << " " << angle << std::endl;
		}
		//------------------------------
	}
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, t1, NULL, NULL);//background
	//SDL_RenderCopyEx(renderer, t2, NULL, &r, -angle, NULL, SDL_FLIP_NONE);//player
	player->render(renderer);
	graphics->Flip();

	std::cout << " " << avgFPS << std::endl;
	countedFrames++;
	int frameTicks = capTimer.getTicks();
	if (frameTicks < SCREEN_TICKS_PER_FRAME)
	{
		//Wait remaining time
		SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
	}
}

void GameProcessScreen::Destroy()
{


}