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
}

void Menu::Update()
{
	while (window->isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 500;  // здесь регулируем скорость игры
		if (time > 20) time = 20;

		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				game->Exit();
		}
		window->clear(Color(107, 140, 255));
		window->draw(*tile);
		window->display();
	}
}

void Menu::Destroy()
{
	window->close();
}
