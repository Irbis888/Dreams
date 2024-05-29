#include "Tile.h"
#include <random>

Tile::Tile()
{
	content = 0;
	f.enemyHp = 0;

	fillColor = Color::White;
}

Tile::Tile(int c)
{
	int r = rand() % 256;
	if (r % 128 == 0) content = 5;
	else if (r % 64 == 0) content = 4;
	else if (r % 32 == 0) content = 3;
	else if (r % 16 == 0) content = 2;
	else if (r % 8 == 0) content = 1;
	else content = 0;
	content = c;
	f.enemyHp = 0;

	redraw();
}

void Tile::redraw()
{
	switch (content) {
	case 0:
		fillColor = Color::White;
		break;
	case 1:
		fillColor = Color::Red; //trap
		break;
	case 2:
		fillColor = Color(150, 150, 0, 255); // wall	
		break;
	case 3:
		fillColor = Color::Yellow; // monster
		f.enemyHp = 100;
		break;
	case 4:
		fillColor = Color::Blue; // trapdoor
		break;
	case 5:
		fillColor = Color::Magenta; // ???
		break;
	default:
		fillColor = Color::Black;
		break;
	}
}

