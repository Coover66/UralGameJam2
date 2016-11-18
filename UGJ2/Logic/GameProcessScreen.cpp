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
	
	player = new Character(55, 55, t2, 0);

}

void GameProcessScreen::Update()
{
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
		if (input->evt.type == SDL_KEYDOWN && input->evt.key.keysym.sym == (Uint8)'w') { r.x += mX / kek1; r.y += mY / kek1; }
		if (input->evt.type == SDL_KEYDOWN && input->evt.key.keysym.sym == (Uint8)'s') { r.x -= mX / kek1; r.y -= mY / kek1; }
		if (input->evt.type == SDL_KEYDOWN && input->evt.key.keysym.sym == (Uint8)'a') r.x--;
		if (input->evt.type == SDL_KEYDOWN && input->evt.key.keysym.sym == (Uint8)'d') r.x++;
		if (input->evt.type == SDL_MOUSEMOTION)
		{
			mX = input->evt.motion.x - r.x - r.h / 2;
			mY = input->evt.motion.y - r.y - r.w / 2;
			
			if (mY != 0 && mY != 0)
			{
				kek1 = sqrt((double)abs(mX*mX + mY*mY)) / 10;
				angle = atan2(mX, mY) / M_PI * 180;
			}//нет else, т.е. может упасть, если долго не будет изменений
			std::cout << mX << " " << mY << " " << angle << std::endl;
		}
		//------------------------------
	}
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, t1, NULL, NULL);//background
	SDL_RenderCopyEx(renderer, t2, NULL, &r, -angle, NULL, SDL_FLIP_NONE);//player

	graphics->Flip();
}

void GameProcessScreen::Destroy()
{


}