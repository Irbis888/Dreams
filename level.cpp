#include "level.h"
#include <iostream>
#include <ctime>
#include <fstream>


Level::Level()
{
	std::ifstream in("resources/rooms.txt");
	std::srand(std::time(0));
	std::string s;
	int c = std::rand() % 8;
	vector<vector<Tile>> v;
	v.resize(7);
	for (int i = 0; i < 7; i++) {
		v[i].resize(7);
		in >> s;
		for (int j = 0; j < 7; j++) {
			v[i][j].content = s[j] - '0';
			v[i][j].redraw();
		}
	}
	chunkMap[std::make_pair(0, 0)] = v;
}

void Level::generateChunk(int _x, int _y)
{
	std::ifstream in("resources/rooms.txt");
	std::srand(std::time(0));
	std::string s;
	int x = (_x + 3) / 7; //chunks
	int y = (_y + 3) / 7;
	int c = std::rand() % 8;
	if (!chunkMap.count(std::make_pair(x,y))) {
		vector<vector<Tile>> v;
		v.resize(7);
		for (int i = 0; i < (c - 1) * 8; i++) in >> s;
		for (int i = 0; i < 7; i++) {
			v[i].resize(7);
			in >> s;		
			for (int j = 0; j < 7; j++) {
				v[i][j].content = s[j] - '0';
				v[i][j].redraw();
			}
		}
		chunkMap[std::make_pair(x, y)] = v;
	}
}

Tile Level::getTile(int _x, int _y)
{
	if (!chunkMap.count(std::make_pair((_x + 3) / 7, (_y + 3) / 7)))
		generateChunk(_x, _y);
	int x = (_x + 3) % 7;
	int y = (_y + 3) % 7;
	if (x < 0) x += 7; if (y < 0) y += 7;
	return chunkMap[std::make_pair((_x + 3) / 7, (_y + 3) / 7)][x][y];
}

void Level::setTile(int _x, int _y, Tile t)
{
	int x = (_x + 3) % 7;
	int y = (_y + 3) % 7;
	if (x < 0) x += 7; if (y < 0) y += 7;
	chunkMap[std::make_pair((_x + 3) / 7, (_y + 3) / 7)][x][y] = t;
}


