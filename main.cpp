
#include "Game.h"
#include <cmath>
#include <ctime>
//#include "level.h"
#include <cstdlib>
#include <vector>

using std::vector;
using namespace sf;
std::string resourcesDir()
{
    return "resources/";
}
using namespace sf;
int main()
{
	Game game;


    while (game.running())
    {
		game.update();
		game.render();
    }
    return EXIT_SUCCESS;
}




/*class Level
{
public:
	vector<vector<int>> map;
	int tilesize = 90;
	int align = 10;
	int width;
	int height;
	sf::RenderWindow window;
	Level(int x, int y, sf::RenderWindow w) {
		window = w;
		width = x;
		height = y;
		for (int i = 0; i < x; i++) {
			vector<int> v;
			map.push_back(v);
			for (int j = 0; j < y; j++) {
				map[i].push_back(0);
			}
		}
	}
	~Level();
	void Show() {
		for (int i = 0; i < width; i++) {
			sf::RectangleShape rect(sf::Vector2f(tilesize, tilesize));
			for (int j = 0; j < height; j++) {

				rect.setFillColor(sf::Color::Cyan);
				rect.setPosition((tilesize + align) * j + align, (tilesize + align) * i + align);
				window.draw(rect);
			}
		}
	}



private:

};*/