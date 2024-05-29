#include "Game.h"
#include <iostream>
#include <fstream>

using namespace sf;
// Privates
void Game::initVars()
{
	this->window = nullptr;
	onMap = true;
	levelNum = 1;
	turnCounter = 0;
	font.loadFromFile("resources/tuffy.ttf");
}

void Game::initWindow()
{
	this->videoMode.height = 720;
	this->videoMode.width = 1280;

	this->window = new sf::RenderWindow(this->videoMode, "Dreams Coming True", Style::Titlebar | Style::Close);
}

void Game::initLevel()
{
	curLevel = new Level();
}

void Game::showLevel()
{
	float tilesize = 90;
	int align = 5;
	sf::RectangleShape t;
	Vector2f center(640, 300);
	for (int i = posX - 3; i <= posX + 3; i++) {
		for (int j = posY - 3; j <= posY + 3; j++) {
			t.setFillColor(curLevel->getTile(i,j).fillColor);
			t.setSize(Vector2f(tilesize, tilesize));
			t.setPosition(center + Vector2f((tilesize + align) * (i - posX), (tilesize + align) * (j - posY)));	
			this->window->draw(t);
		}
	}

}

void Game::checkTile()
{
	if (!turnMade) return;
	Tile t = curLevel->getTile(posX, posY);
	int c = t.content;
	if (c == 1) { player.changeHP(-10); }
	else if (c == 3) {
		if (t.f.enemyHp > 0) {
			fight = t.f;
			isFighting = true;
			onMap = false;
		}
	}
	else if (c == 4) {
		delete curLevel;
		curLevel = new Level();
		levelNum++;
		if (levelNum == goalDepth) {
			Tile t = curLevel->getTile(goalX, goalY);
			t.content = 5;
			t.redraw();
			curLevel->setTile(goalX, goalY, t);
		}
	}
	else if (c == 5) {
		won = true;
		onMap = false;
	}
}

bool Game::checkWall(int x, int y)
{
	if (curLevel->getTile(x, y).content == 2) {
		return true;
	}
	return false;
}


void Game::showFight()
{
	fight.pic.setPosition(800, 315);
	window->draw(fight.pic);
	
	Text text;
	text.setFont(font);
	text.setFillColor(Color::Black);
	text.setPosition(10, 10);
	text.setString("Fight a monster");
	window->draw(text);

	text.setPosition(100, 400);
	text.setString("Your health: " + std::to_string(player.getHP()));
	window->draw(text);

	text.setPosition(800, 400);
	text.setString("Monster's health: " + std::to_string(fight.enemyHp));
	window->draw(text);
}

void Game::getItem()
{
	
	int c = std::rand() % 6 +1;
	std::ifstream in("resources/items.txt");
	std::string s;
	Item it;
	std::string t = "";
	for (int i = 0; i < c; i++) {
		std::getline(in, s);
	}
	int mark = 0;
	for (int i = 0; i < 3; i++) {
		while (s[mark] != ' ') {
			t += s[mark];
			mark++;
		}
		mark++;
		it.use.push_back(std::stoi(t));
		t = "";
	}
	while (mark < s.size()) {
		t += s[mark];
		mark++;
	}
	it.name = t;
	inventory.push_back(it);
	curItem = inventory.size() - 1;
}

void Game::useItem(Item it)
{
	player.changeHP(it.use[1]);
	player.setSTR(it.use[2]+player.getSTR());
	Tile t = curLevel->getTile(posX, posY);
	switch (it.use[0]) {
	case 1:
		t.content = 4;
		t.redraw();
		curLevel->setTile(posX, posY, t);
		break;
	case 2:
		t.content = 0;
		t.redraw();
		curLevel->setTile(posX+1, posY, t);
		curLevel->setTile(posX-1, posY, t);
		curLevel->setTile(posX, posY+1, t);
		curLevel->setTile(posX, posY-1, t);
		curLevel->setTile(posX + 1, posY+1, t);
		curLevel->setTile(posX - 1, posY-1, t);
		curLevel->setTile(posX-1, posY + 1, t);
		curLevel->setTile(posX+1, posY - 1, t);
		curLevel->setTile(posX + 2, posY, t);
		curLevel->setTile(posX - 2, posY, t);
		curLevel->setTile(posX, posY + 2, t);
		curLevel->setTile(posX, posY - 2, t);
		break;
	default:
		break;
	}
	
}

Game::Game()
{
	std::srand(std::time(0));
	this->initVars();
	this->initWindow();
	this->initLevel();
	posX = 0;
	posY = 0;
	goalDepth = std::rand() % 10 + 1;
	goalX = std::rand() % 300 + -150;
	goalY = std::rand() % 300 + -150;
	if (levelNum == goalDepth) {
		Tile t = curLevel->getTile(goalX, goalY);
		t.content = 5;
		t.redraw();
		curLevel->setTile(goalX, goalY, t);
	}
	getItem();
	getItem();
	getItem();
}

Game::~Game()
{
	delete this->window; 
}

const bool Game::running() const
{
	return this->window->isOpen();

}

// Publics
void Game::updateEvs()
{
	while (this->window->pollEvent(this->event))
	{
		this->window->display();
		switch (event.type)
		{
		case Event::Closed:
			this->window->close();
		case Event::KeyPressed:
			if (event.key.code == Keyboard::Escape)
				this->window->close();
			if (onMap){
				if (event.key.code == Keyboard::Up and not checkWall(posX, posY-1)) {
					posY--; turnMade = true; turnCounter++;
				}
				if (event.key.code == Keyboard::Down and not checkWall(posX, posY + 1)) { posY++; turnMade = true; turnCounter++;
				}
				if (event.key.code == Keyboard::Left and not checkWall(posX - 1, posY)) { posX--; turnMade = true; turnCounter++;
				}
				if (event.key.code == Keyboard::Right and not checkWall(posX+1, posY)) { posX++; turnMade = true; turnCounter++;
				}
				if (event.key.code == Keyboard::H and !inventory.empty()) {
					useItem(inventory.at(curItem));
					Item it = inventory.at(curItem);
					inventory[curItem] = inventory[inventory.size() - 1];
					inventory[inventory.size() - 1] = it;
					inventory.pop_back();
					if (curItem > inventory.size() - 1) curItem--;
					turnMade = true; turnCounter++;
				}
				if (event.key.code == Keyboard::Numpad2 and !inventory.empty() and curItem < inventory.size()-1) {
					curItem++;
				}
				if (event.key.code == Keyboard::Numpad8 and !inventory.empty() and curItem > 0) {
					curItem--;
				}
			}
			if (isFighting) {
				if (event.key.code == Keyboard::Num1) {
					fight.changeHp(-player.getSTR());
					turnMade = true;
				}
			}
		default:
			break;
		}
	}
}

void Game::update()
{
	turnMade = false;
	updateEvs();
	if(onMap)
	checkTile();
	if (isFighting and turnMade) {
		player.changeHP(-fight.enemydmgMin);
		if (fight.enemyHp <= 0)
		{
			Tile t = curLevel->getTile(posX, posY);
			t.f = fight;
			curLevel->setTile(posX, posY, t);
			isFighting = false;
			onMap = true;
			getItem();
		}

	}

	if (player.getHP() <= 0) {
		onMap = false;
		lost = true;
	}
}

void Game::render()
{
	window->clear(Color::Magenta);
	//draw here
 	CircleShape plPic;
	plPic.setRadius(30);
	plPic.setFillColor(Color::Black);
	if (onMap) {
		showLevel();
		plPic.setPosition(655, 315);
		window->draw(plPic);


		Text text;
		text.setFont(font);
		text.setFillColor(Color::Black);
		text.setPosition(10, 10);
		text.setString("Level: " + std::to_string(levelNum));
		window->draw(text);
		text.setPosition(10, 40);
		text.setString("HP: " + std::to_string(player.getHP()));
		window->draw(text);
		text.setPosition(10, 70);
		text.setString("Turn made: " + std::to_string(turnCounter));
		window->draw(text);

		text.setPosition(10, 370);
		text.setString(goalDepth > levelNum ? "Deeper" : "Deep enough");
		window->draw(text);
		text.setPosition(10, 400);
		text.setString(goalX > posX ? ">" : "<=");
		window->draw(text);
		text.setPosition(10, 430);
		text.setString(goalY > posY ? "V" : "^");
		window->draw(text);
		if (!inventory.empty()) {
			text.setString("!");
			text.setPosition(1030, 70+curItem*30);
			window->draw(text);
		}

		for (int i = 0; i < inventory.size(); i++) {
			text.setPosition(1040, 70+i*30);
			text.setString(inventory[i].name);
			window->draw(text);
		}
	}
	else if (isFighting) {
		showFight();
		plPic.setPosition(200, 315);
		window->draw(plPic);
		
	}
	else if (won) {
		Text text;
		text.setFont(font);
		text.setFillColor(Color::Black);
		text.setPosition(10, 10);
		text.setString("You won!");
		window->draw(text);
	}
	else if (lost) {
		Text text;
		text.setFont(font);
		text.setFillColor(Color::Black);
		text.setPosition(10, 10);
		text.setString("You died!");
		window->draw(text);
	}
	
	window->display();
}


