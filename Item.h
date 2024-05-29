#pragma once
#include <SFML/Graphics.hpp>

class Item
{

public:
	Item();
	std::string name;
	sf::RectangleShape pic;
	std::vector<int> use;
};

