//control de Puzzle en plan ! nivel 1 , final ? puzzle 1 y asi 
//#include "Rebotes.h"
//#include "Gusanillo.h"
#ifndef PUZZLE_H
#define PUZZLE_H


#include "Tetris.h"

class Puzzle{
private:
Rebotes *reb=new Rebotes();
Gusanillo *gus=new Gusanillo();
Tetris *tet=new Tetris();
sf::Event ev;

public:
Puzzle();
~Puzzle();
void cogeEvento(sf::Event);
void cargarPuzzle(int); // funcion para cargar los Puzzle
void dibujarPuzzle(int, sf::RenderWindow &); // funcion para dibujar los Puzzle
bool checkVictoria(int); // checkea la victoria
bool checkDerrota(int); // checkea la derrota

};

#endif