#pragma once
#include <vector>
#include <stack>
#include <deque>
#include "Point.h"

class NPC
{
public:
	NPC();
	Point position;
	std::stack<Point> & findPath(const Point & finish) const;
	void setPole(const VecVecBool & input);
	virtual ~NPC();
private:
	VecVecBool & pole;
};




