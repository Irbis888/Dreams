#pragma once
#include <vector>
#include <map>
#include "Tile.h"

using std::vector;
using std::map;


class Level
{
public:
	
	Level();
	//~Level();
	Tile getTile(int _x, int _y);
	void setTile(int _x, int _y, Tile t);
private:
	// Dimensions of generated chuncks
	void generateChunk(int _x, int _y); //x & y here are coordinates of a TILE, not of a CHUNK
	map<std::pair<int, int>, vector<vector<Tile>>> chunkMap;
}; 
