#ifndef ENEMIGO_H
#define ENEMIGO_H


#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#include "Jugador.h"

class Enemigo
{
    private:
        float posicionX; // Posicion en X
        float posicionY; // Posicion en Y
        float velosidat;
        float posjugx;
        float posjugy;
        animacion* anim=new animacion();
        vector <sf::Sprite*> arriba;
        vector <sf::Sprite*> abajo;
        vector <sf::Sprite*> derecha;
        vector <sf::Sprite*> izquierda;
        sf::Sprite enemy;
        int posision=0;
        int dir = 0;
        int comp=0;
    public:
        Enemigo(string);
        ~Enemigo();
        void movimientoenemigo();//arriba abajo
        void movimientoenemigo2();// cuadrado
        void movimientoenemigo3();// sigue al jugador
        void movimientoenemigo4();// dercha izq
        void movimientoenemigo5();// rectangulo
        void movimientoenemigo6();// dercha izq más corto
        //bool getEstado(); //devuelve el estado del objeto
        void getPosicionJugX(Jugador); // devuelve la posicion X
        void getPosicionJugY(Jugador); //devuelve la posicion Y
        void dibujasion( sf::RenderWindow &);
        float getPosicionEnemX();
        float getPosicionEnemY();
        void reiniciarEnemigo();
        void setPosicion(float,float);
};

#endif