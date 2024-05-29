#pragma once

class Player
{
	int HP;
	int STR;
	int INT;
	int LUCK;
	int damageMin;
	int damageMax;
	int attack;
	int parry;
	

public:
	Player();
	int getHP() { return HP; };
	int getSTR() { return STR; };
	void setSTR(int s) { STR = s; };
	void setHP(int hp_) { HP = hp_; };
	void changeHP(int hp_) { HP += hp_; };
	//std::vector<Item> inventory;
};

