#include "GameOfLife.h"

bool GameOfLife::slucajna_vrijednost()
{
	if ((rand() % (100 - 1 + 1) + 1) <= 25) return true;
	else return false;
}

bool GameOfLife::celija_zauzeta(int i, int j)
{
	if (_generacija[i][j] == 1) return true;
	else return false;
}

int GameOfLife::vrati_broj_zivta(int i, int j)
{
	int  brojac = 0;

	if (i - 1 >= 0 && j - 1 >= 0)			if (celija_zauzeta(i - 1, j - 1))	brojac++;
	if (i - 1 >= 0)							if (celija_zauzeta(i - 1, j))		brojac++;
	if (i - 1 >= 0 && j + 1 < STUPACA)		if (celija_zauzeta(i - 1, j + 1))	brojac++;
	if (j - 1 >= 0)							if (celija_zauzeta(i, j - 1))		brojac++;
	if (j + 1 < STUPACA)					if (celija_zauzeta(i, j + 1))		brojac++;
	if (i + 1 < REDAKA && j - 1 >= 0)		if (celija_zauzeta(i + 1, j - 1))	brojac++;
	if (i + 1 < REDAKA)						if (celija_zauzeta(i + 1, j))		brojac++;
	if (i + 1 < REDAKA && j + 1 < STUPACA)	if (celija_zauzeta(i + 1, j + 1))	brojac++;

	return brojac;
}

GameOfLife::GameOfLife(sf::RenderWindow* window)
{
	this->window = window;
	srand(time(nullptr));
	for (int i = 0; i < REDAKA; i++)
		for (int j = 0; j < STUPACA; j++)
			_generacija[i][j] = slucajna_vrijednost();
}

void GameOfLife::sljedeca_generacija()
{
	//RACUNANJE SLJEDECE GENERACIJE
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {

			int stanje_okoline = vrati_broj_zivta(i, j);

			if (_generacija[i][j]) {

				if (stanje_okoline == 2 || stanje_okoline == 3) {
					_sljedeca_generacija[i][j] = true;
				}
				else _sljedeca_generacija[i][j] = false;
			}

			else {

				if (stanje_okoline == 3) {
					_sljedeca_generacija[i][j] = true;
				}
				else _sljedeca_generacija[i][j] = false;

			}

		}
	}

	//SLJEDECA GENERACIJA JE SADA STARA GENERACIJA
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {

			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

void GameOfLife::iscrtaj()
{
	sf::CircleShape circle(2);
	circle.setPointCount(6);

	float x = 0, y = 0;

	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			if (_generacija[i][j]) {


				if (j < 50) {

					if (j < 25) {
						circle.setFillColor(sf::Color(255, 255, 0));
					}
					else {
						circle.setFillColor(sf::Color(255, 200, 0));
					}
				}

				else if (j < 100) {

					if (j < 75) {
						circle.setFillColor(sf::Color(255, 150, 0));
					}
					else {
						circle.setFillColor(sf::Color(255, 95, 0));
					}
				}

				else if (j < 150) {

					if (j < 125) {
						circle.setFillColor(sf::Color(255, 50, 0));
					}
					else {
						circle.setFillColor(sf::Color(255, 0, 130));
					}
				}

				else if (j < 200) {

					if (j < 175) {
						circle.setFillColor(sf::Color(255, 0, 210));
					}
					else {
						circle.setFillColor(sf::Color(200, 0, 255));
					}
				}

				circle.setPosition(sf::Vector2f(x, y));
				window->draw(circle);
			}

			x += 4;
		}
		y += 4;
		x = 0;
	}
}
