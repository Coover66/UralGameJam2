#include "Map.h"



Map::Map()
{
}

Map::Map(VecVecPointState & _map) : map(_map)
{
}

bool Map::isPointValid(Point & p)
{
	if (p.y < 0 || p.y >= map.size())  return false;
	if (p.x < 0 || p.x >= map[p.y].size()) return false;
	return  (map[p.y][p.x] == PointState::Free || map[p.y][p.x] == PointState::OpenDoor);
}

Point Map::getValidNeighbor(Point & p, uint i)
{
	Point neighbor(p.x + dx[i], p.y + dy[i]);
	if (isPointValid(neighbor))
		return neighbor;
	return Point(-1, -1);
}


Map::~Map()
{
}
