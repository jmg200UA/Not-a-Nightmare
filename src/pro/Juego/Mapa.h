#ifndef MAPA_H
#define MAPA_H




#include <SFML/Graphics.hpp>
#include <iostream>

#include <cstdlib>
#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <string>


#include "TileMap.h"
#include "tinyxml2.h"


using namespace std;
using namespace tinyxml2;


class Mapa{
private:
 TileMap* map = nullptr; // objeto Tilemap para cargar los mapas
 // Capas del mapa



 int ancho; // width map
 int alto; //height map
 int tiledAncho;
 int tiledAlto;
 int** tiles;
 int numlayers {0};

 vector<vector<int>> colisiones{};

 void cargarMapa(string);
 void clearMap();

public:

 explicit Mapa(string);
 void drawMapa(sf::RenderWindow&);
 bool colisionMap(int,int,int,int);
 bool reloadMap(string);
 


};
#endif