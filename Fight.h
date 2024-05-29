#pragma once
#include <SFML/Graphics.hpp>
class Fight
{
	

public:
	int enemydmgMin;
	int enemydmgMax;
	int enemyHp;
	int enemyAttack;
	int enemyParry; //шансы попасть и увернуться в процентах
	sf::CircleShape pic;

	Fight();
	void changeHp(int _d);
};

