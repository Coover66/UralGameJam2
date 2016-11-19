#include "Map.h"

Map::Map()
{
	std::ifstream file;
	file.open("..\\Data\\DefaultMap.txt");
	if (!file.good())
		return;
	map.push_back(std::vector<PointState>());
	char c;	
	uint i = 0;
	while (!file.eof())
	{
		
		file >> c;
		switch (c)
		{
		case '.': map[i].push_back(PointState::Free); break;
		case '#': map[i].push_back(PointState::Window); break;
		case '$': map[i].push_back(PointState::OpenDoor); break;
		case '|': map[i].push_back(PointState::Wall); break;
		case 'E': 
		{
			map.push_back(std::vector<PointState>());
			++i;
		}
		break;
		default: break;
		}
		
	}
}

Map::Map(VecVecPointState & _map) : map(_map)
{
}

bool Map::isPointValid(const Point & p) const
{
	if (p.y < 0 || p.y >= map.size())  return false;
	if (p.x < 0 || p.x >= map[p.y].size()) return false;
	return  (map[p.y][p.x] == PointState::Free || map[p.y][p.x] == PointState::OpenDoor);
}

PointState Map::getPoint(const uint x, uint y) const
{
	return map[y][x];
}

size_t Map::getXSize() const
{
	if (map.empty())
		return 0;
	return map[0].size();
}

size_t Map::getYSize() const
{
	return map.size();
}

Point Map::getNeighbor(const Point & p, const uint i) const
{
	return Point(p.x + dx[i], p.y + dy[i]);
}


Map::~Map()
{
}
