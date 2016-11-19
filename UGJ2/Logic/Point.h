#pragma once
#include <vector>

typedef std::vector< std::vector<int> > VecVecInt;
typedef std::vector<std::vector <bool> > VecVecBool;
typedef unsigned int uint;

class Map;

class Point
{
public:
	Point() : x(0), y(0) {};
	Point(int _x, int _y) :
		x(_x),
		y(_y){}

	bool isValid(const VecVecBool & pole) const;
	Point getBestNeighbor(const Map & map, const VecVecInt & input) const;
	int x;
	int y;
	static const int *dx;   // смещени€, соответствующие сосед€м €чейки
	static const int *dy;
};

bool operator ==(const Point  & l, const Point & r);
bool operator !=(const Point  & l, const Point & r);

