#pragma once
#include <vector>
#include <stack>
#include <deque>
#include "Point.h"

class NPC
{
public:
	NPC(int x, int y, VecVecBool & map);
	Point position;
	std::stack<Point> findPath(const Point & finish) const;
	void setPole(const VecVecBool & input);
private:
	VecVecBool pole;
};




