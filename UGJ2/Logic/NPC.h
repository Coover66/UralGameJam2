#pragma once
#include <vector>
#include <stack>
#include <deque>
#include "Character.h"

class Map;

class NPC : public Character
{
public:
	NPC(int x, int y, Map & map, SDL_Texture* texture, double direction);
	std::stack<Point> findPath(const Point & finish) const;
private:
	Map & map;
};




