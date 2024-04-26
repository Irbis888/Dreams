
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




