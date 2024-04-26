#include "Game.h"
#include <iostream>

using namespace sf;
// Privates
void Game::initVars()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 720;
	this->videoMode.width = 1280;

	this->window = new sf::RenderWindow(this->videoMode, "Dreams Coming True", Style::Titlebar | Style::Close);
}

void Game::initLevel()
{

}

void Game::showLevel()
{
	float tilesize = 90;
	int align = 10;
	sf::RectangleShape t;
	Vector2f center(640, 360);
	for (int i = posX - 3; i <= posX + 3; i++) {
		for (int j = posY - 3; j <= posY + 3; j++) {
			t.setSize(Vector2f(tilesize, tilesize));
			t.setPosition(center + Vector2f((tilesize + align) * i, (tilesize + align) * j));
			t.setFillColor(Color(0,0,0,255));
			//std::cout << curLevel.getTile(i, j) << "0";
			
			this->window->draw(t);
		}
	}
}

Game::Game()
{
	this->initVars();
	this->initWindow();
	this->initLevel();
	posX = 0;
	posY = 0;
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
		default:
			break;
		}
	}
}

void Game::update()
{
	this->updateEvs();
}

void Game::render()
{
	this->window->clear(Color::Magenta);
	//draw here
	showLevel();
	this->window->display();
}


