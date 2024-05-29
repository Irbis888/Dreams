#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Fight.h"

using namespace sf;

class Tile
{

public:
	Tile();
	Tile(int c);
	Color fillColor;
	Fight f;
	int content;
	void redraw();

};

