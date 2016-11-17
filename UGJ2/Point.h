#pragma once
#include <vector>
//#include <WinBase.h>

typedef std::vector< std::vector<int> > VecVecInt;
typedef std::vector<std::vector <bool> > VecVecBool;
typedef unsigned int uint;

class Point
{
public:
	Point() : x(0), y(0) {};
	Point(unsigned int _x, unsigned int _y) :
		x(_x),
		y(_y){}

	bool isValid(const VecVecBool & pole) const;
	Point getBestNeighbor(const VecVecBool & inputPole, const VecVecInt & input) const;
	uint x;
	uint y;
	virtual ~Point();
	static const int *dx;   // смещени€, соответствующие сосед€м €чейки
	static const int *dy;
};

bool operator ==(const Point  & l, const Point & r);
bool operator !=(const Point  & l, const Point & r);

