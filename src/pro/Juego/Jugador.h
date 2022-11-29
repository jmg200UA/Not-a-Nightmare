#ifndef JUGADOR_H
#define JUGADOR_H

#include <SFML/Graphics.hpp> 
#include <iostream>
#include <cmath>

using namespace std;
using namespace sf;

#include "Animacion.h" 
#include "Objeto.h"
#include "Mapa.h"




class Jugador
{
private:
    vector<Objeto*> inventario;
    vector<Objeto*> inventario2;
    int posx;
    int posy;
    int antposx;
    int antposy;
    int contador;
    float velocidad;
    float posenemx;
    float posenemy;
    bool choque;
    bool minijuego;
    int nivel;
    int salausable; // para saber en la sala que hay un usable y poder trabajar en base a ello
    int salarecogible;

    float anchoSprite;
    float altoSprite;
    animacion* anim = new animacion();
    vector <sf::Sprite*> arriba;
    vector <sf::Sprite*> abajo;
    vector <sf::Sprite*> derecha;
    vector <sf::Sprite*> izquierda;
    sf::Sprite player;
    size_t pos=0;

public:
    Jugador(String);
    //~Jugador();
    void accionesJugador(int, Mapa&); //acciones de movimiento y coger objeto del jugador
    void setInventario(Objeto *); // función para agregar los objetos al vector
    void setInventario2(Objeto *); // función para agregar los objetos al vector
    //vector<Objeto> getInventario();
    vector<Objeto*> getInventario(); // devuelve el inventario de objetos
    vector<Objeto*> getInventario2(); // devuelve el inventario de objetos
    bool comprobarColision(); // función que comprueba si hay colisión con un objeto recogible
    int comprobarCogerObj(); //función que detecta que el jugador está en rango para poder coger un objeto
    bool comprobarColisionUsable();
    int comprobarUsable();
    void dibujar( sf::RenderWindow &);
    float getPosicionX(); // devuelve la posicion X
    float getPosicionY(); //devuelve la posicion Y
    void setPosicion(float, float); // actualiza la posición
    int getContador(); //devuelve el numero de objetos en posesión
    void setContador(); //actualiza el contador de objetos en posesión
    void inicializaContador(); // pone contador de objetos a 0
    void getPosicionEnemX(float);
    void getPosicionEnemY(float);
    bool comprobarColisionEnemigo(); // comprueba la colision con el enemigo
    void choqueTrue(); // si colisiona pone "choque" a true
    void choqueFalse(); // si colisiona pone "choque" a false
    bool returnChoque(); // devuelve la variable choque
    float getPosicionAntX();
    float getPosicionAntY();
    int getAnchoSprite();
    int getAltoSprite();
    bool getMinijuego(); //devuelve el estado de la variable minijuego
    void setMinijuego();
    void setNivel(int); // cambia el nivel al actual pasado por parametro
    void setSalaUsable(int); // cambia a la sala del usable pasado por parametro
    void setSalaRecogible(int); // cambia de sala para la comprobación correcta de colisiones con objetos
};

#endif