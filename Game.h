#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
// Kinda Engine class
class Game
{
private:

	void initVars();
	void initWindow();

	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

public:
	Game();
	virtual ~Game();

	const bool running() const;


	void update();
	void render();
	void updateEvs();
};

