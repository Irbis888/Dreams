#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include "level.h"
#include "player.h"
#include "Item.h"
#include "fight.h"
// Kinda Engine class
class Game
{
private:

	void initVars();
	void initWindow();
	void initLevel();
	void showLevel();
	void checkTile();
	bool checkWall(int x, int y);
	void showFight();
	void getItem();
	void useItem(Item it);



	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;
	Level* curLevel;
	Player player;
	Fight fight;
	Font font;
	vector<Item> inventory;

	int posX;
	int posY;
	int goalDepth;
	int goalX;
	int goalY;
	int levelNum;
	int turnCounter;
	int curItem;

	bool turnMade;
	bool isFighting;
	bool onMap;
	bool won;
	bool lost;

public:
	Game();
	virtual ~Game();

	const bool running() const;
	bool exitRq;


	void update();
	void render();
	void updateEvs();
	
};

