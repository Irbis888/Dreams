#pragma once
#include <vector>
#include <map>
#include "Tile.h"

using std::vector;
using std::map;


class Level
{
public:
	map<std::pair<int, int>, vector<vector<Tile>>> chunkMap;
	Level();
	Tile getTile(int _x, int _y);
private:
	// Dimensions of generated chuncks
	void generateChunk(int _x, int _y); //x & y here are coordinates of a TILE, not of a CHUNK
	

}; 
