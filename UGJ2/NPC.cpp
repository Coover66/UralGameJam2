#include "NPC.h"

NPC::NPC()
{
}

std::stack<Point>& NPC::findPath(const VecVecBool & input, const Point & start, const Point & finish) const
{
	VecVecInt pole(input.size());
	auto j = pole.begin();
	for (auto i = input.begin(); i < input.end(); ++i, ++j)
		j->_Construct_n(i->size(), 0);

	std::deque<Point> deque;
	deque.push_back(start);
	int len = 0;
	pole[start.x][start.y] = len;
	do
	{
		Point currentPoint = deque.front();
		deque.pop_front();
		if (currentPoint == finish)
			break;
		for (int i = 0; i < 8; ++i)                    // проходим по всем непомеченным соседям
		{
			Point nextPoint(currentPoint.y + dy[i], currentPoint.x + dx[i]);
			if (!pointIsValid(nextPoint, input) || pole[nextPoint.x][nextPoint.y] <= pole[currentPoint.x][currentPoint.y] + 1)
				break;
			pole[nextPoint.x][nextPoint.y] = pole[currentPoint.x][currentPoint.y] + 1;
			deque.push_back(nextPoint);
		}
	} while (!deque.empty() && pole[finish.x][finish.y] == 0);
	if (pole[finish.x][finish.y] == 0)
		return std::stack<Point>();
	std::stack<Point> result;
	Point currentPoint = finish;
	result.push(currentPoint);
	while (currentPoint != start)
	{
		currentPoint = getBestNeighbor(currentPoint, input);
		result.push(currentPoint);
	}
	return result;
}


NPC::~NPC()
{
}

bool NPC::pointIsValid(const Point & p, const VecVecBool & pole) const
{
	if (p.x < 0 || p.x > pole.size())  return false;
	if (p.y < 0 || p.y > pole[p.x].size()) return false;
	if (pole[p.x][p.y] == false) return false;
	return true;
}

Point NPC::getBestNeighbor(const Point & p, const VecVecBool & pole) const
{
	auto len = pole[p.x][p.y];
	for (int i = 0; i < 8; ++i)                    // проходим по всем непомеченным соседям
	{
		Point nextPoint(p.y + dy[i], p.x + dx[i]);
		if (pointIsValid(nextPoint, pole) && pole[nextPoint.x][nextPoint.y] < len)
			return nextPoint;
	}
	OutputDebugString("Can't find neighbor");
	return Point(0, 0);
}

