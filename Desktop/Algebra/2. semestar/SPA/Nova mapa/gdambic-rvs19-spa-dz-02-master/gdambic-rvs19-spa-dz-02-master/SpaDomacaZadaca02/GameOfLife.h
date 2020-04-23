#pragma once
#include <SFML/Graphics.hpp>

class GameOfLife
{
private:
	sf::RenderWindow* window;
	static const unsigned int STUPACA = 200;
	static const unsigned int REDAKA = 150;
	bool _generacija[REDAKA][STUPACA];
	bool _sljedeca_generacija[REDAKA][STUPACA];
	bool slucajna_vrijednost();
	bool celija_zauzeta(int i, int j);
	int vrati_broj_zivta(int i, int j);

public:
	GameOfLife(sf::RenderWindow* window);
	void sljedeca_generacija();
	void iscrtaj();
};


