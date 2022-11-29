#include "Gusanillo.h"
#include <time.h>
using namespace sf;
#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once

class Tetris{
private:
const int alto=20;
const int largo=10;
int matr[20][10]={0};
struct Point{int x; int y;}a[4]={{1,0},{1,1},{1,2},{1,3}} , copia[4];
Point figuras[7][4]=
{
    {{1,0},{1,1},{1,2},{1,3}},// Palo recto
    {{0,1},{1,1},{1,2},{2,2}},// Zeta
    {{0,1},{1,1},{2,1},{1,2}},// Zeta Inversa
    {{0,0},{1,0},{1,1},{1,2}},// T Inversa
    {{0,1},{1,1},{0,2},{1,2}},// L
    {{0,2},{1,1},{1,2},{2,1}},// L Inversa
    {{1,0},{1,1},{1,2},{2,0}} // Cubo

}; // Matriz para dibujar las figuras
sf::Texture *t1; //textura objetos
sf::Texture *t2; //textura fondo
sf::Texture *t3; //textura marco
sf::Sprite *s1; //sprite objetos
sf::Sprite *s2; //sprite fondo
sf::Sprite *s3; // sprite marco
sf::Font *fuente; // fuente del texto final
sf::Text *texto; // texto final
float temp, delay; // temporizador movimiento
Clock clock; // reloj minijuego
Clock clock2; // reloj minijuego
int direccion; // direccion movimiento eje x
int objeto; //numero que corresponde a un objeto segun el tile
int contfilas=0;
bool fin=false;
float tiempo=0;
int reloj=0;
bool pierde=false;


public:
Tetris();
~Tetris();
void cargarTetris();
void dibujarTetris(sf::RenderWindow &);
bool comprobarPos();
bool checkVictoria();
bool derrotaTetris();
};