#pragma once
#include <vector>
#include <fstream>
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
	bool isPointValid(const Point & p) const;
	PointState getPoint(const uint x, const uint y) const;
	size_t getXSize() const;
	size_t getYSize() const;
	Point getNeighbor(const Point & p, const uint i) const; //получить i-го соседа
	virtual ~Map();
private:
	VecVecPointState map;
	const int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
	const int dy[8] = { 1, -1, 0, 0, -1, 1, 1, -1 };
};

