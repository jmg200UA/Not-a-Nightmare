//clase que muestra todos los menus y eventos

#include "Menu.h"


Menu::Menu(float width, float height, int tipo)
{
	if (!font.loadFromFile("resources/pixel.ttf"))
	{
		// handle error
	}

	if(tipo == 0){
		menu[0].setFont(font);
		menu[0].setScale(1.2,1);
		menu[0].setColor(sf::Color::Yellow);
		menu[0].setString("Nueva Partida");
		menu[0].setPosition(sf::Vector2f(width / 3.5, height / (MAX_NUMBER_OF_ITEMS + 0.25) * 1.5));

		menu[1].setFont(font);
		menu[1].setColor(sf::Color::White);
		menu[1].setString("Controles");
		menu[1].setPosition(sf::Vector2f(width / 3.5, height / (MAX_NUMBER_OF_ITEMS + 0.25) * 2));

		menu[2].setFont(font);
		menu[2].setColor(sf::Color::White);
		menu[2].setString("Salir");
		menu[2].setPosition(sf::Vector2f(width / 3.5, height / (MAX_NUMBER_OF_ITEMS + 0.25) * 2.5));

		selectedItemIndex = 0;
	}else if(tipo == 1){
		menu[0].setFont(font);
		menu[0].setScale(1.2,1);
		menu[0].setColor(sf::Color::Yellow);
		menu[0].setString("Seguir jugando");
		menu[0].setPosition(sf::Vector2f(width / 3.5, height / (MAX_NUMBER_OF_ITEMS + 0.25) * 1.5));

		menu[1].setFont(font);
		menu[1].setColor(sf::Color::White);
		menu[1].setString("Controles");
		menu[1].setPosition(sf::Vector2f(width / 3.5, height / (MAX_NUMBER_OF_ITEMS + 0.25) * 2));

		menu[2].setFont(font);
		menu[2].setColor(sf::Color::White);
		menu[2].setString("Salir");
		menu[2].setPosition(sf::Vector2f(width / 3.5, height / (MAX_NUMBER_OF_ITEMS + 0.25) * 2.5));

		selectedItemIndex = 0;
	}else if(tipo==2){

		menu[0].setFont(font);
		menu[0].setScale(1.2,1);
		menu[0].setColor(sf::Color::Yellow);
		menu[0].setString("Salir del juego");
		menu[0].setPosition(sf::Vector2f(width / 3.5, height / (MAX_NUMBER_OF_ITEMS + 0.25) * 1.5));
	}
}


Menu::~Menu()
{
}

void Menu::dibujar(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoverArriba()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		menu[selectedItemIndex].setScale(1,1);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Yellow);
		menu[selectedItemIndex].setScale(1.2,1);
	}
}

void Menu::MoverAbajo()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		menu[selectedItemIndex].setScale(1,1);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Yellow);
		menu[selectedItemIndex].setScale(1.2,1);
	}
}