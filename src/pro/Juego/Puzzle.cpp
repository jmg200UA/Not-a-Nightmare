//Clase puzzle que gestiona como un index todos los puzzle
#include "Puzzle.h"

Puzzle::Puzzle(){}

Puzzle::~Puzzle(){}

void Puzzle::cargarPuzzle(int num){ // esta funcion se podria hacer, cargando directamente todos los Puzzle
    if(num==0){
        tet->cargarTetris();
    }// funciones para cargar el puzzle
    if(num==1){
        reb->cargarRebotes();
    }
    if(num==2){
        gus->cargarGusano();
    }

}

void Puzzle::dibujarPuzzle(int num,sf::RenderWindow &ventana){
    if(num==0){
        tet->dibujarTetris(ventana);
    }// funciones para dibujar el puzzle
    if(num==1){
        reb->dibujarRebotes(ventana);
    }
    if(num==2){
        gus->dibujarGusano(ventana);
        //gus->Tick();
    }
}

void Puzzle::cogeEvento(sf::Event evento){
    ev=evento;
}

bool Puzzle::checkVictoria(int num){
    bool dev=false;
    if(num==0) dev=tet->checkVictoria();
    if(num==1) dev=reb->finRebotes();
    if(num==2) dev=gus->finGusano();
    return dev;
}

bool Puzzle::checkDerrota(int num){
    bool dev=false;
    if(num==0) dev=tet->derrotaTetris();
    if(num==1) dev=reb->derrotaRebotes();
    if(num==2) dev=gus->derrotaGusano();
    return dev;
}
