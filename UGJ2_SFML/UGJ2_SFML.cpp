#include "Engine\Game.h"
#include "Logic\Menu.h"
int WinMain()
{
	Game game;
	return game.Execute(new Menu(), 640, 480);
}

