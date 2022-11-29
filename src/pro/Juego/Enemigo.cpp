//Clase de la entidad Enemigo

#include "Enemigo.h" 

using namespace std;
using namespace sf;

//Constructor por defecto
Enemigo::Enemigo(string name){
    posicionX = 460; 
    posicionY = 340;
    velosidat = 4;
    dir=0;

    enemy.setPosition(posicionX,posicionY);
    anim->cargarTextura(name);
    anim->crearVectores(6);
    anim->posicionar(posicionX,posicionY);
    anim->getSprite().setPosition(posicionX,posicionY);
    anim->posicionar(posicionX,posicionY);

    arriba=anim->getUp();
    abajo=anim->getDown();
    derecha=anim->getRight();
    izquierda=anim->getLeft();
}

void Enemigo::dibujasion(sf::RenderWindow &ventana){
    enemy.setPosition(posicionX,posicionY);
    ventana.draw(enemy);
}

void Enemigo::setPosicion(float x, float y){
    posicionX = x;
    posicionY = y;
    enemy.setPosition(posicionX,posicionY);
}

void Enemigo::reiniciarEnemigo(){
    posicionX = -100; 
    posicionY = -100;
    velosidat = 0;
    dir=0;
}

void Enemigo::getPosicionJugY(Jugador jug){
    posjugy=jug.getPosicionY();
}

void Enemigo::getPosicionJugX(Jugador jug){
    posjugx=jug.getPosicionX();
}

void Enemigo::movimientoenemigo(){
    //se mueve arriba y abajo
    if(posicionY == 70){
        dir = 1;
    }
    if (posicionY == 370){
        dir = 0;
    }
    if(dir == 0){
        enemy=*arriba[posision];
        enemy.move(0,velosidat);
        posicionY = posicionY - 2;
    }
    if(dir == 1){
        enemy=*abajo[posision];
        enemy.move(0,-velosidat);
        posicionY = posicionY + 2;
    }
    /*if(posicionX > posjugx){
        enemy=*izquierda[posision];
        enemy.move(-velosidat,0);
        posicionX--;
    }
    if(posicionX < posjugx){
        enemy=*derecha[posision];
        enemy.move(velosidat,0);
        posicionX++;
        cout << posjugx << endl;
    }*/
    enemy.setPosition(posicionX,posicionY); 
}

void Enemigo::movimientoenemigo2(){
    //se mueve en cuadrado 
    if(posicionY == 110){
        dir = 1;
    }
    if(posicionX == 220){
        dir = 2;
    }
    if(posicionY == 250){
        dir = 3;
    }
    if(posicionX == 370 && comp==1){
        dir = 0;
    }
    if(dir == 0){
        enemy=*arriba[posision];
        enemy.move(0,velosidat);
        posicionY = posicionY - 2;
        comp=0;
    }
    if(dir == 1){
        enemy=*izquierda[posision];
        enemy.move(-velosidat,0);
        posicionX = posicionX - 2;
    }
    if(dir == 2){
        enemy=*abajo[posision];
        enemy.move(0,velosidat);
        posicionY = posicionY + 2;
    }
    if(dir == 3){
        enemy=*derecha[posision];
        enemy.move(velosidat,0);
        posicionX = posicionX + 2;
        comp=1;
    }
    enemy.setPosition(posicionX,posicionY); 
}

void Enemigo::movimientoenemigo3(){
    //enemigo que te sigue
    if(posicionX > posjugx){
        enemy=*izquierda[posision];
        enemy.move(-velosidat,0);
        posicionX = posicionX - 0.2;
    }

    if(posicionX < posjugx){
        enemy=*derecha[posision];
        enemy.move(velosidat,0);
        posicionX = posicionX + 0.2;
    }
    if(posicionY > posjugy){
        enemy=*arriba[posision];
        enemy.move(0,-velosidat);
        posicionY = posicionY - 0.2;
    }

    if(posicionY < posjugy){
        enemy=*abajo[posision];
        enemy.move(0,velosidat);
        posicionY = posicionY + 0.2;
    }
    enemy.setPosition(posicionX,posicionY); 
}

void Enemigo::movimientoenemigo4(){
    //se mueve derecha e izquierda
    if(posicionX == 10){
        dir = 1;
    }
    if (posicionX == 590){
        dir = 0;
    }
    if(dir == 0){
        enemy=*izquierda[posision];
        enemy.move(-velosidat,0);
        posicionX = posicionX - 2;
    }
    if(dir == 1){
        enemy=*derecha[posision];
        enemy.move(velosidat,0);
        posicionX = posicionX + 2;
    }
    enemy.setPosition(posicionX,posicionY); 
}

void Enemigo::movimientoenemigo5(){
    //se mueve en cuadrado 
    if(posicionY == 70){
        dir = 1;
    }
    if(posicionX == 230){
        dir = 2;
    }
    if(posicionY == 380){
        dir = 3;
    }
    if(posicionX == 340 && comp==1){
        dir = 0;
    }
    if(dir == 0){
        enemy=*arriba[posision];
        enemy.move(0,velosidat);
        posicionY = posicionY - 2;
        comp=0;
    }
    if(dir == 1){
        enemy=*izquierda[posision];
        enemy.move(-velosidat,0);
        posicionX = posicionX - 2;
    }
    if(dir == 2){
        enemy=*abajo[posision];
        enemy.move(0,velosidat);
        posicionY = posicionY + 2;
    }
    if(dir == 3){
        enemy=*derecha[posision];
        enemy.move(velosidat,0);
        posicionX = posicionX + 2;
        comp=1;
    }
    enemy.setPosition(posicionX,posicionY); 
}

void Enemigo::movimientoenemigo6(){
    //se mueve derecha e izquierda
    if(posicionX == 226){
        dir = 1;
    }
    if (posicionX == 433){
        dir = 0;
    }
    if(dir == 0){
        enemy=*izquierda[posision];
        enemy.move(-velosidat,0);
        posicionX--;
    }
    if(dir == 1){
        enemy=*derecha[posision];
        enemy.move(velosidat,0);
        posicionX++;
    }
    enemy.setPosition(posicionX,posicionY); 
}

float Enemigo::getPosicionEnemX(){
    return posicionX;
}

float Enemigo::getPosicionEnemY(){
    return posicionY;
}

Enemigo::~Enemigo(){
    delete anim;
}


