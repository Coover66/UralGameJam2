#include "Point.h"
#include "Map.h"

bool Point::isValid(const VecVecBool & pole) const
{
	if (y < 0 || y >= pole.size())  return false;
	if (x < 0 || x >= pole[y].size()) return false;
	return  pole[y][x];
}

Point Point::getBestNeighbor(const Map & map, const VecVecInt & input) const
{
	auto len = input[y][x];
	for (int i = 0; i < 8; ++i)                    // проходим по всем непомеченным соседям
	{
		Point nextPoint(x + map.dx[i], y + map.dy[i]);
		if (!map.isPointValid(nextPoint))
			continue;
		int nextLen = input[nextPoint.y][nextPoint.x];
		if (nextLen != -1 && nextLen < len)
			return nextPoint;
	}
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

Point operator+(const Point & l, const Point & r)
{
	return Point(l.x + r.x, l.y + r.y);
}

Point & operator+=(Point & l, const Point & r)
{
	l.x += r.x;
	l.y += r.y;
	return l;
}

Point & operator-=(Point & l, const Point & r)
{
	l.x -= r.x;
	l.y -= r.y;
	return l;
}


