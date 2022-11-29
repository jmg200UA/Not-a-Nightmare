#ifndef GUSANILLO_H
#define GUSANILLO_H

#include "Rebotes.h"

class Gusanillo{
private:
sf::Texture *t1; //textura gusano
sf::Texture *t2; //textura fondo
sf::Texture *t3; //textura comida gusanillo
sf::Texture *t4; //textura cabeza
sf::Sprite *sSnake; //sprite gusano
sf::Sprite *sFondo; //sprite fondo
sf::Sprite *sComida; //sprite comida
sf::Sprite *sCabeza; //sprite cabeza
sf::Font *fuente; // fuente del texto final
sf::Text *texto; // texto final
float direccionx, direcciony; //direccion en x e y
float x, y; //posicion del gusanisho
int M; // fila en bloques
int N; // columna en bloques
int tam; // tamaño del bloque
int ancho; // largo
int alto; // alto 
int dir;
int num; // numero de direcciones
struct Snake{int x,y;}s[100];
struct Fruit{int x,y;}f;
int contlong; // contador de bloques
bool fin,pierde;
float temp, delay; // temporizador movimiento
Clock clock; // reloj minijuego


public:
Gusanillo();
~Gusanillo();
void cargarGusano();
void Tick();
void dibujarGusano(sf::RenderWindow &);
bool finGusano();
bool derrotaGusano();
};

#endif