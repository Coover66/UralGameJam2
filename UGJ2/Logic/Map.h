#pragma once
#include <vector>
#include "Point.h"
#include "Door.h"
#include "GlassWindow.h"
enum PointState
{
	Free = -1,
	OpenDoor = -2,
	CloseDoor = -3,
	Wall = -4,
	Window = -5
};

typedef std::vector< std::vector <PointState> >VecVecPointState;

class Map
{
public:
	Map();
	Map(VecVecPointState & _map);
	bool isPointValid(Point & p);
	Point getValidNeighbor(Point & p, uint i); //получить i-го валидного (по которому можно пройти) соседа (начиная с клетки сверху и двигаясь по часовой)
	virtual ~Map();
private:
	VecVecPointState map;
	const int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	const int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
};

