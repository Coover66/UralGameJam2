#include "NPC.h"


NPC::NPC(int x, int y, VecVecBool & map):position(x, y), pole(map)
{
}

std::stack<Point> & NPC::findPath(const Point & finish) const
{
	VecVecInt poleInt(pole.size(), std::vector<int>(pole[0].size(), -1));
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
			Point nextPoint(currentPoint.x + Point::dx[i], currentPoint.y + Point::dy[i]);
			if (!nextPoint.isValid(pole))
				continue;
			
			uint nextLen = poleInt[nextPoint.y][nextPoint.x];
			uint currentLen = poleInt[currentPoint.y][currentPoint.x];
			if (nextLen > currentLen + 1 || nextLen == -1)
			{
				poleInt[nextPoint.y][nextPoint.x] = currentLen + 1;
				deque.push_back(nextPoint);
			}
		}
	} while (!deque.empty() && poleInt[finish.y][finish.x] == -1);
	if (pole[finish.y][finish.x] == 0)
		return std::stack<Point>();
	std::stack<Point> result;
	Point currentPoint = finish;
	result.push(currentPoint);
	while (currentPoint != position)
	{
		currentPoint = currentPoint.getBestNeighbor(pole, poleInt);
		result.push(currentPoint);
	}
	return result;
}

void NPC::setPole(const VecVecBool & input)
{
	pole.resize(input.size());
	auto j = pole.begin();
	for (auto i = input.begin(); i < input.end(); ++i, ++j)
		j->assign(i->begin(), i->end());	
}



