#include "Tile.h"
#include <random>

Tile::Tile()
{

	pic.setFillColor(Color(rand()%256, rand() % 256, rand() % 256, 255));
}
