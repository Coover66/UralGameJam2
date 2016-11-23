#include "Map.h"

Map::Map(SDL_Texture* wallTexture, SDL_Texture* windowTexture, SDL_Texture* openDoorTexture, SDL_Texture* closeDoorTexture, SDL_Texture* floorTexture):
	playerPosition(playerPosition.x, playerPosition.y)
{
	std::ifstream file;
	file.open("..\\Data\\DefaultMap.txt");
	readFromFile(file);
	for (int i = 0; i < map.size(); ++i)
	{
		entityMap.push_back(std::vector<Entity*>());
		for (int j = 0; j < map[i].size(); ++j)
		{
			switch (map[i][j])
			{
			case PointState::Free: entityMap[i].push_back(new Entity(j * cellHeight, i * cellWidth, floorTexture)); break;
			case PointState::Wall: entityMap[i].push_back(new Entity(j * cellHeight, i * cellWidth, wallTexture)); break;
			case PointState::Window: entityMap[i].push_back(new GlassWindow(j * cellHeight, i * cellWidth, floorTexture)); break;
			case PointState::CloseDoor:
			case PointState::OpenDoor: entityMap[i].push_back(new Door(j * cellHeight, i * cellWidth, floorTexture)); break;
			default:
				break;
			}
		}
	}
}

void Map::update(Point & playerDeltaPosition)
{	
	playerPosition += playerDeltaPosition;
	leftUpCellOnScreen = Point( ((playerPosition.x - SCREEN_WIDTH / 2) / cellWidth), ((playerPosition.y - SCREEN_HEIGHT / 2) / cellHeight) );
	rightDownCellOnScreen = Point(((playerPosition.x + SCREEN_WIDTH / 2) / cellWidth), ((playerPosition.y + SCREEN_HEIGHT / 2) / cellHeight));
	auto endY = entityMap.end();
	if (rightDownCellOnScreen.y < map.size())
		endY = entityMap.begin() + rightDownCellOnScreen.y;
	int entityNumberX = leftUpCellOnScreen.x;
	int entityNumberY = leftUpCellOnScreen.y;
	if (leftUpCellOnScreen.x < 0)
		leftUpCellOnScreen.x = 0;
	if (leftUpCellOnScreen.y < 0)
		leftUpCellOnScreen.y = 0;

	for (auto i = entityMap.begin() + leftUpCellOnScreen.y; i != endY; ++i, ++entityNumberY)
	{
		auto endX = i->end();
		if (rightDownCellOnScreen.y < i->size())
			endX = i->begin() + rightDownCellOnScreen.x;
		for (auto j = i->begin() + leftUpCellOnScreen.x;
			j != endX;
			++j, ++entityNumberX)
		{
			int posX = entityNumberX * cellWidth + playerDeltaPosition.x;
			int posY = entityNumberY * cellHeight + playerDeltaPosition.y;
			if (posX < 0)
				posX = 0;
			if (posY < 0)
				posY = 0;
			(*j)->moveTo(posX, posY);
		}
	}
}

void Map::render(SDL_Renderer * renderer)
{
	auto endY = entityMap.begin() + rightDownCellOnScreen.y;
	for (auto i = entityMap.begin() + leftUpCellOnScreen.y; i != endY; ++i)
	{
		auto endX = i->begin() + rightDownCellOnScreen.x;
		for (auto j = i->begin() + leftUpCellOnScreen.x; j != endX; ++j)
			(*j)->render(renderer);
	}
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
	for each (auto i in entityMap)
		i.~vector();
	for each (auto i in map)
		i.~vector();
}

void Map::readFromFile(std::ifstream & file)
{
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
		case 'P': 
		{
			playerPosition.y = i * cellHeight + cellHeight / 2;
			playerPosition.x = map[i].size() * cellWidth + cellWidth / 2;
			map[i].push_back(PointState::Free);
		}
		break;
		default: break;
		}
	}
}
