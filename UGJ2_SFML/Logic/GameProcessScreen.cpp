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

	wallTexture = new Texture();
	windowTexture = new Texture();
	door = new Texture();
	door1 = new Texture();
	floor = new Texture();

	wallTexture->loadFromFile("../Data/WallTmp.bmp");
	windowTexture->loadFromFile("../Data/WindowTmp.bmp");
	door->loadFromFile("../Data/DoorTmp.bmp");
	door1->loadFromFile("../Data/DoorTmp.bmp");
	floor->loadFromFile("../Data/FloorTmp.bmp");

	//SDL_SetTextureBlendMode(t2, SDL_BLENDMODE_ADD);
	
	wall = new Entity(200, 480/2, stone,0,50,200);
	map = new Map(wallTexture, windowTexture, door, door1, floor);

	player = new Player(640 / 2, 480 / 2, t2, *map, 0, 100, 100, wall);
	
	
	map->update(Point(0, 0));
	clock.restart();
}

void GameProcessScreen::Update()
{
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
			map->render(window);
			player->render(window);
			window->display();
			clock.restart();
	}
}

void GameProcessScreen::Destroy()
{
}