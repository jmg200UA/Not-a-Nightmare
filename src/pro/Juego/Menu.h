#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
	Menu(float, float, int);
	~Menu();

	void dibujar(sf::RenderWindow &window);
	void MoverArriba();
	void MoverAbajo();
	int GetItemPresionado() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};