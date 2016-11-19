#pragma once
#include <vector>
#include <stack>
#include <deque>
#include "Character.h"

class NPC : public Character
{
public:
	NPC(int x, int y, VecVecBool & map, SDL_Texture* texture, double direction);
	std::stack<Point> findPath(const Point & finish) const;
	void setPole(const VecVecBool & input);
private:
	VecVecBool pole;
};




