#ifndef ANIMACION_H
#define ANIMACION_H

#include <SFML/Graphics.hpp> 
#include <iostream>
using namespace std;
using namespace sf;

class animacion{

private:
    sf::Texture *textura;
    sf::Sprite *sprite;

    // Los 4 vectores de moviemiento
    vector<sf::Sprite*> moveUp {};
    vector<sf::Sprite*> moveDown {};
    vector<sf::Sprite*> moveLeft {};
    vector<sf::Sprite*> moveRight {};

    int x;
    int y;
    int AnchoX{-1};
    int AltoY{-1};
   
    

public:

    animacion();
    ~animacion();
    void cargarTextura(string);//carga la textura.
    void crearVectores(int); // crea los vectores.
    void posicionar(int , int ); // clase que dibuja un objeto en una posicion
    void volverInvisible();

    int getX();
    int getY();
    int getSpriteX();
    int getSpriteY();


    //devolucion de los vectores
    std::vector<sf::Sprite*> getUp();
    std::vector<sf::Sprite*> getDown();
    std::vector<sf::Sprite*> getRight();
    std::vector<sf::Sprite*> getLeft();
    sf::Sprite getSprite();
    

};
#endif