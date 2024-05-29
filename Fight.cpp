#include "Fight.h"

Fight::Fight()
{
	enemyAttack = 75;
	enemyParry = 10;
	enemyHp = 100;
	enemydmgMin = 5;
	enemydmgMax = 11;
	pic.setFillColor(sf::Color::Red);
	pic.setRadius(30);
}

void Fight::changeHp(int _d)
{
	enemyHp += _d;
}
