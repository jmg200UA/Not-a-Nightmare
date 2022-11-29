
#include "HUD.h"

HUD::HUD()
{
    contadorcito = 3;
    vidas = new sf::Texture;
    spriteVidas = new sf::Sprite;
}

int HUD::cargarHud()
{
    int salida=-1;

    switch (contadorcito)
    {
    case 1:

        if (!vidas->loadFromFile("resources/1vidas.png"))
        {
            return EXIT_FAILURE;
        }

        spriteVidas->setTexture(*vidas);
        spriteVidas->setPosition(470, 30);
        salida=0;
        break;

    case 2:

        if (!vidas->loadFromFile("resources/2vidas.png"))
        {
            return EXIT_FAILURE;
        }
        spriteVidas->setTexture(*vidas);
        spriteVidas->setPosition(470, 30);
        salida=0;

        break;
    case 3:

        if (!vidas->loadFromFile("resources/3vidas.png"))
        {
            return EXIT_FAILURE;
        }
        spriteVidas->setTexture(*vidas);
        spriteVidas->setPosition(470, 30);
        salida=0;

        break;

    default:
    salida=-1;
    break;


    }
    return salida;
}
void HUD::setContadorHUD(int contador)
{
    contadorcito = contador;
    cargarHud();
}


void HUD::drawHUD(sf::RenderWindow & ventana){
    ventana.draw(*spriteVidas);
}








HUD::~HUD()
{
}