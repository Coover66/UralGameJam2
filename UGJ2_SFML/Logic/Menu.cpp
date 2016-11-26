#include "Menu.h"
using namespace sf;

Menu::Menu(){}
Menu::~Menu(){}

void Menu::Start()
{
	window = game->GetWindow();
	tileSet = new Texture();
	tileSet->loadFromFile("../Data/grass.bmp");
	tile = new Sprite();
	tile->setTexture(*tileSet);
	tile->setTextureRect(IntRect(10, 10, 100, 100));

	clock.restart();
}

void Menu::Update()
{
	while (window->isOpen())
	{
		float time = clock.getElapsedTime().asMilliseconds();
		clock.restart();
		
			Event event1;
			while (window->pollEvent(event1))
			{
				if (event1.type == Event::Closed)
				{
					game->Exit();
					return;
				}
				if (event1.type == Event::KeyPressed)
				{
					if (event1.key.code == Keyboard::Escape)
					{
						game->Exit();
						return;
					}
					if (event1.key.code == Keyboard::Return)
					{
						game->SetScreen(new GameProcessScreen());
						return;
					}
				}
			}
			window->clear(Color(107, 140, 255));
			window->draw(*tile);
			window->display();
	}
}

void Menu::Destroy()
{
}
