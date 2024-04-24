#include "Game.h"

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

Game::Game()
{
	this->initVars();
	this->initWindow();
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

	this->window->display();
}


