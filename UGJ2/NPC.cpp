#include "NPC.h"

NPC::NPC() : pole(VecVecBool())
{
}

std::stack<Point>& NPC::findPath(const Point & finish) const
{
	VecVecInt poleInt(pole.size());
	auto j = poleInt.begin();
	for (auto i = pole.begin(); i < pole.end(); ++i, ++j)
		j->_Construct_n(i->size(), 0);

	std::deque<Point> deque;
	deque.push_back(position);
	poleInt[position.x][position.y] = 0;
	do
	{
		Point currentPoint = deque.front();
		deque.pop_front();
		if (currentPoint == finish)
			break;
		for (int i = 0; i < 8; ++i)                    // проходим по всем непомеченным соседям
		{
			Point nextPoint(currentPoint.y + Point::dy[i], currentPoint.x + Point::dx[i]);
			uint nextLen = poleInt[nextPoint.x][nextPoint.y];
			uint currentLen = poleInt[currentPoint.x][currentPoint.y];
			if (!nextPoint.isValid(pole) || nextLen <= currentLen + 1)
				break;
			poleInt[nextPoint.x][nextPoint.y] = currentLen + 1;
			deque.push_back(nextPoint);
		}
	} while (!deque.empty() && poleInt[finish.x][finish.y] == 0);
	if (pole[finish.x][finish.y] == 0)
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

NPC::~NPC()
{
}



