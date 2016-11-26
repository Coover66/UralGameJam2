#include "Engine\Game.h"
#include "Logic\Menu.h"
int main()
{
	Game game;
	return game.Execute(new Menu(), 640, 480);
}

