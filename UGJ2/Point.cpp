#include "Point.h"
static const int dx_data[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
const int * Point::dx = dx_data;
static const int dy_data[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int *Point::dy = dy_data;

bool Point::isValid(const VecVecBool & pole) const
{
	if (x < 0 || x > pole.size())  return false;
	if (y < 0 || y > pole[x].size()) return false;
	if (pole[x][y] == false) return false;
	return true;
}

Point Point::getBestNeighbor(const VecVecBool & inputPole, const VecVecInt & input) const
{
	auto len = input[x][y];
	for (int i = 0; i < 8; ++i)                    // проходим по всем непомеченным соседям
	{
		Point nextPoint(y + dy[i], x + dx[i]);
		if (nextPoint.isValid(inputPole) && input[nextPoint.x][nextPoint.y] < len)
			return nextPoint;
	}
	//OutputDebugString("Can't find neighbor");
	return Point(0, 0);
}

bool operator==(const Point & l, const Point & r)
{

	if (l.x != r.x) return false;
	if (l.y != r.y) return false;
	return true;

}

bool operator!=(const Point & l, const Point & r)
{
	return !(l == r);
}

Point::~Point()
{
}


