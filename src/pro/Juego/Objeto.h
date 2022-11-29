#ifndef OBJETO_H
#define OBJETO_H

#include <SFML/Graphics.hpp> 
#include <iostream>

using namespace std;
using namespace sf;

#include "Animacion.h" 

class Objeto{
private:
    int id; // Id para que si creamos un inventario podamoscrear un vector con todos los objetos.
    bool estado; // true , se ha recogido el objeto, false no se ha recogido
    //int Accion; // un int para crear diferentes acciones  y asignarle la accion correspondiente.
    float posicionX; // Posicion en X
    float posicionY; // Posicion en Y
    animacion* Anim;//clase anim para el sprite
    bool recogible; //variable que indica si se puede recoger o no;
    bool usable;
    String nombre;

public:
    Objeto(String);
    ~Objeto();

    void objetoInformacion(int, int, int); // metodo para asignar los parametros.
    void DibujaObjeto(sf::RenderWindow &); // dibuja el sprite en la posicion correspondiente.
    void CogerObjeto(); // metodo que borra el sprite y cambia el estado a true.

    String getNombre(); // devuelve el nombre del objeto
    
    bool getEstado(); //devuelve el estado del objeto
    int getPosicionX(); // devuelve la posicion X
    int getPosicionY(); //devuelve la posicion Y
    void setPosicion(float, float); // actualiza la posicion
    void setRecogible(bool);
    bool getRecogible();
    void setUsable(bool);
    bool getUsable();

};

#endif
