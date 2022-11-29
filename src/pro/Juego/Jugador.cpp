//Todas las habilidades de la entidad Jugador , movimiento coger cosas etc etc .

#include "Jugador.h"

Jugador::Jugador(String name)
{
    posx =170;
    posy =120;
    velocidad = 50;
    contador = 0;

    posenemx = 0;
    posenemy = 0;

    choque = false;

    anim->cargarTextura(name);
    anim->crearVectores(9);
    anim->getSprite().setPosition(posx, posy);
    anim->posicionar(posx, posy);

   
    arriba = anim->getUp();
    abajo = anim->getDown();
    derecha = anim->getRight();
    izquierda = anim->getLeft();

    player = *derecha[pos];
    
    altoSprite=anim->getSpriteY();
    anchoSprite=anim->getSpriteX();

    minijuego=false;

    nivel=0;

    salausable=0;
    salarecogible=0;

}

void Jugador::accionesJugador(int opcion, Mapa &map)
{
    
    pos = pos + 1;

    if (pos >= anim->getRight().size())
    {
        pos = 0;
    }
    //compobar que no se pasa de los limites.
    switch (opcion)
    {

    case 1:
        //cambia el sprite y lo mueve arriba

        
        posy--;

        if (posy == -1)
        {
            posy++;
        }
        else
        {

            if (!map.colisionMap(posx, posy, anchoSprite, altoSprite))
            {

                if (comprobarColision() || comprobarColisionUsable())
                {
                    posy++;
                }
                if (comprobarColisionEnemigo())
                {
                    choqueTrue();
                }
                else
                {
                    player = *arriba[pos];
                }
            }
            else
            {
                posy++;
            }
        }

        break;

    case 2:
        //cambia el sprite y lo mueve abajo
        posy++;
        if (!map.colisionMap(posx, posy, anchoSprite, altoSprite))
        {

            if (comprobarColision() || comprobarColisionUsable())
            {
                posy--;
            }
            if (comprobarColisionEnemigo())
            {
                choqueTrue();
            }
            else
            {
                player = *abajo[pos];
            }
        }
        else
        {
            posy--;
        }

        break;

    case 3:
        //cambia el sprite y lo mueve derecha
        posx++;
        if (!map.colisionMap(posx, posy, anchoSprite, altoSprite))
        {
            if (comprobarColision() || comprobarColisionUsable())
            {
                posx--;
            }
            if (comprobarColisionEnemigo())
            {
                choqueTrue();
            }
            else
            {
                player = *derecha[pos];
            }
        }
        else
        {
            posx--;
        }

        break;

    case 4:
        //cambia el sprite y lo mueve izquierda
        posx--;
        if (!map.colisionMap(posx, posy, anchoSprite, altoSprite))
        {

            if (comprobarColision() || comprobarColisionUsable())
            {
                posx++;
            }
            if (comprobarColisionEnemigo())
            {
                choqueTrue();
            }
            else
            {
                player = *izquierda[pos];
            }
        }
        else
        {
            posx++;
        }

        break;

    case 5:

        //crear el vector de objetos para Jugador directamente, y cambiar estado cuando intersecte con el objeto
        
        if (comprobarCogerObj() != -1)
        {
            int num = 0;
            num = comprobarCogerObj();
            inventario.at(num)->CogerObjeto();
            inventario.at(num)->setRecogible(false);
            setContador();
        }
        if(comprobarUsable()!=-1){
            minijuego=true;
            int num=0;
            num= comprobarUsable();
            inventario2.at(num)->CogerObjeto();
            inventario2.at(num)->setRecogible(false);
            inventario2.at(num)->setUsable(false);
        } 
        break;

    default:
        cout << "Error tecla incorrecta" << opcion << endl;
        break;
    }
}

void Jugador::setInventario(Objeto *obj)
{

    inventario.push_back(obj);
}

void Jugador::setInventario2(Objeto *obj)
{

    inventario2.push_back(obj);
}

void Jugador::dibujar(sf::RenderWindow &ventana)
{

    anim->posicionar(posx, posy);
    player.setPosition(anim->getX(), anim->getY());
    ventana.draw(player);
}

vector<Objeto *> Jugador::getInventario()
{
    return inventario;
}

vector<Objeto *> Jugador::getInventario2()
{
    return inventario2;
}


void Jugador::setPosicion(float x, float y)
{
    antposx = posx;
    antposy = posy;
    posx = x;
    posy = y;
    player.setPosition(posx, posy);
}

bool Jugador::comprobarColisionEnemigo()
{
    bool compro = false;
    if (FloatRect(posx, posy, 12, 12).intersects(FloatRect(posenemx , posenemy -33 , 35, 60)))
        compro = true;
    return compro;
}

bool Jugador::comprobarColision()
{
    bool ret = false;
    if(nivel==0){
        for (int i = 0; i < 3; i++)
        {
            if (inventario.at(i)->getRecogible())
            {
                if (FloatRect(posx, posy, 12, 12).intersects(FloatRect(inventario.at(i)->getPosicionX() - 10, inventario.at(i)->getPosicionY() -38, 32, 25)))
                    ret = true;
            }
        }
    }
    else if(nivel==1){
        if (inventario.at(3)->getRecogible())
            {
                if (FloatRect(posx, posy, 12, 12).intersects(FloatRect(inventario.at(3)->getPosicionX() - 10, inventario.at(3)->getPosicionY() -38, 32, 25)))
                    ret = true;
            }
    }
    else if(nivel==2){
        if(salarecogible==3){
            if (inventario.at(4)->getRecogible())
            {
                if (FloatRect(posx, posy, 12, 12).intersects(FloatRect(inventario.at(4)->getPosicionX() - 10, inventario.at(4)->getPosicionY() -38, 32, 25)))
                    ret = true;
            }
        }
    }

    return ret;
}

int Jugador::comprobarCogerObj()
{
    int ret = -1;
    if(nivel==0){
        for (int i = 0; i < 3; i++)
        {   
            if (inventario.at(i)->getRecogible()){
                if (FloatRect(posx, posy, 15, 15).intersects(FloatRect(inventario.at(i)->getPosicionX() - 10, inventario.at(i)->getPosicionY() - 38, 37, 29)))
                ret = i;
            }
            
        }
    }
    else if(nivel==1){
        if (inventario.at(3)->getRecogible()){
            if (FloatRect(posx, posy, 15, 15).intersects(FloatRect(inventario.at(3)->getPosicionX() - 10, inventario.at(3)->getPosicionY() - 38, 37, 29)))
                    ret = 3;
        }
    }
    else if(nivel==2){
        if (inventario.at(4)->getRecogible()){
            if (FloatRect(posx, posy, 15, 15).intersects(FloatRect(inventario.at(4)->getPosicionX() - 10, inventario.at(4)->getPosicionY() - 38, 37, 29)))
                    ret = 4;
        }
    }
    
    return ret;
}

bool Jugador::comprobarColisionUsable()
{
    bool ret = false;
    if(nivel==0){
        if(salausable==1){
            if (inventario2.at(0)->getRecogible())
            {
                if (FloatRect(posx, posy, 12, 12).intersects(FloatRect(inventario2.at(0)->getPosicionX() - 10, inventario2.at(0)->getPosicionY() -38, 32, 25)))
                    ret = true;
            }
        }
        
    }
    else if(nivel==1){
        if(salausable==2){
            if (inventario2.at(1)->getRecogible())
        {
            if (FloatRect(posx, posy, 12, 12).intersects(FloatRect(inventario2.at(1)->getPosicionX() - 10, inventario2.at(1)->getPosicionY() -38, 32, 25)))
                ret = true;
        }
        }
        
    }
    else if(nivel==2){
        if(salausable==3){
            if (inventario2.at(2)->getRecogible())
            {
                if (FloatRect(posx, posy, 12, 12).intersects(FloatRect(inventario2.at(2)->getPosicionX() - 10, inventario2.at(2)->getPosicionY() -38, 32, 25)))
                    ret = true;
            }
        }
        
    }
        
    

    return ret;
}

int Jugador::comprobarUsable()
{
    int ret = -1;
    if(salausable!=0){
        for (int i = 0; i < 3; i++)
        {
            if (FloatRect(posx, posy, 15, 15).intersects(FloatRect(inventario2.at(i)->getPosicionX() - 10, inventario2.at(i)->getPosicionY() - 38, 37, 29)))
                ret = i;
        }
    }
    
    return ret;
}


void Jugador::setContador()
{
    contador++;
}

void Jugador::inicializaContador()
{
    contador = 0;
}

void Jugador::choqueTrue()
{
    choque = true;
}

void Jugador::choqueFalse()
{
    choque = false;
}

bool Jugador::returnChoque()
{
    return choque;
}

float Jugador::getPosicionY()
{
    return posy;
}

float Jugador::getPosicionX()
{
    return posx;
}

float Jugador::getPosicionAntX()
{
    return antposx;
}

float Jugador::getPosicionAntY()
{
    return antposy;
}

void Jugador::getPosicionEnemX(float x)
{
    posenemx = x;
}

void Jugador::getPosicionEnemY(float y)
{
    posenemy = y;
}

int Jugador::getContador()
{
    return contador;
}

int Jugador::getAnchoSprite(){
   
    return anchoSprite;
}
int Jugador::getAltoSprite(){
    
    return altoSprite;
}

bool Jugador::getMinijuego(){
    return minijuego;
}

void Jugador::setMinijuego(){
    minijuego=false;
}

void Jugador::setNivel(int niv){
    nivel=niv;
}

void Jugador::setSalaUsable(int sala){
    salausable=sala;
}

void Jugador::setSalaRecogible(int sala){
    salarecogible=sala;
}