#include <SFML/Graphics.hpp>
#include"GameOfLife.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	GameOfLife cvijet(&window);

	sf::Clock frameClock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		sf::Time elapsed = frameClock.getElapsedTime();

		//OTKOMENTIRATI DA SE SLIKA MIJENJA SVAKE 2 SEKUNDE
		//if (elapsed.asSeconds() > 2) {
		cvijet.sljedeca_generacija();
		//	frameClock.restart().asSeconds();
		//}

		cvijet.iscrtaj();
		window.display();
	}

	return 0;
}