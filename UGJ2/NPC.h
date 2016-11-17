#pragma once
#include <vector>
#include <stack>
#include <deque>
#include <Windows.h>
#include <WinBase.h>

typedef std::vector< std::vector<int> > VecVecInt;
typedef std::vector<std::vector <bool> > VecVecBool;

enum PointState
{
	Free = 0,
	Busy = -1
};

class Point
{
public:
	Point(unsigned int _x, unsigned int _y) :
		x(_x),
		y(_y)
	{}
	unsigned int x;
	unsigned int y;
};

bool operator ==(const Point  & l, const Point & r)
{
	if (l.x != r.x) return false;
	if (l.y != r.y) return false;
	return true;
}
bool operator !=(const Point  & l, const Point & r)
{
	return !(l == r);
}

class NPC
{
  	const int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };   // смещени€, соответствующие сосед€м €чейки
	const int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };

public:
	NPC();
	std::stack<Point> & findPath(const VecVecBool & input, const Point & start, const Point & finish) const;
	virtual ~NPC();
private:
	bool pointIsValid(const Point & p, const VecVecBool & pole) const;
	Point getBestNeighbor(const Point & p, const VecVecBool & pole) const;
};




