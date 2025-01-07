#include <iostream>
#include "Game.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Shape Drawing");
	window.setFramerateLimit(60);

	Game game(window);
	game.Run();

	return 0;
}