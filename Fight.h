#pragma once
#include <SFML/Graphics.hpp>
class Fight
{
	

public:
	int enemydmgMin;
	int enemydmgMax;
	int enemyHp;
	int enemyAttack;
	int enemyParry; //����� ������� � ���������� � ���������
	sf::CircleShape pic;

	Fight();
	void changeHp(int _d);
};

