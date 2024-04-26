#include "level.h"

Level::Level()
{
	chunkMap[std::make_pair(0, 0)] = *(new vector<vector<Tile>>(7, *(new vector<Tile>(7))));
	for (int i = 0; i < 7; i++) for (int j = 0; j < 7; j++) chunkMap[std::make_pair(0, 0)][i][j] = new Tile());
}

void Level::generateChunk(int _x, int _y)
{
	int x = (_x + 3) / 7; //chunks
	int y = (_y + 3) / 7;
	if (!chunkMap.count(std::make_pair(x,y))) {
		chunkMap[std::make_pair(x, y)] = *(new vector<vector<Tile>>(7, *(new vector<Tile>(7, *(new Tile())))));
	}
}

Tile Level::getTile(int _x, int _y)
{
	return chunkMap[std::make_pair((_x+3)/7, (_y+3)/7)][(_x + 3) % 7][(_y + 3) % 7];
}
