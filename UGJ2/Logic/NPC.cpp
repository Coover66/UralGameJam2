#include "NPC.h"
#include "Map.h"


NPC::NPC(int x, int y, Map & _map, SDL_Texture * texture, double direction = 0): Character(x, y, texture, direction), map(_map) {}


std::stack<Point> NPC::findPath(const Point & finish) const
{
	VecVecInt poleInt(map.getYSize(), std::vector<int>(map.getXSize(), -1));
	std::deque<Point> deque;
	deque.push_back(position);
	poleInt[position.y][position.x] = 0;
	do
	{
		Point currentPoint = deque.front();
		deque.pop_front();
		if (currentPoint == finish)
			break;
		for (int i = 0; i < 8; ++i)                    // проходим по всем непомеченным соседям
		{
			Point nextPoint = map.getNeighbor(currentPoint, i);
			if (!map.isPointValid(nextPoint))
				continue;
			uint nextLen = poleInt[nextPoint.y][nextPoint.x];
			uint currentLen;
			if (i < 4)
				currentLen = poleInt[currentPoint.y][currentPoint.x] + 10;
			else 
				currentLen = poleInt[currentPoint.y][currentPoint.x] + 14;
			if (nextLen > currentLen || nextLen == -1)
			{
				poleInt[nextPoint.y][nextPoint.x] = currentLen;
				deque.push_back(nextPoint);
			}
		}
	} while (!deque.empty() && poleInt[finish.y][finish.x] == -1);
	if (poleInt[finish.y][finish.x] == -1)
		return std::stack<Point>();
	std::stack<Point> result;
	Point currentPoint = finish;
	result.push(currentPoint);
	while (currentPoint != position)
	{
		currentPoint = currentPoint.getBestNeighbor(map, poleInt);
		result.push(currentPoint);
	}
	return result;
}



