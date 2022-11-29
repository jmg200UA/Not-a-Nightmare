//Clase objeto 

#include   "Objeto.h" 


using namespace std;
using namespace sf;


//Constructor por defecto
Objeto::Objeto(String nom){
    id=-1;
    estado = false;
    //Accion = false; //por ahora no voy a aplicar ninguna accion al objeto
    posicionX = 0; 
    posicionY = 0;
    Anim= new animacion();
    nombre=nom;
    recogible=true;
    usable=false;


}
//Clases
void Objeto::objetoInformacion(int ident, int posx, int posy){

    if(ident>=0){
        id=ident;
    }else{
        id=-1;
    }
    posicionX = posx; 
    posicionY = posy;

}

String Objeto::getNombre(){
    return nombre;
}

void Objeto::DibujaObjeto(sf::RenderWindow &ventana){
    
    Anim->cargarTextura(nombre);
    Anim->posicionar(posicionX,posicionY);
    ventana.draw(Anim->getSprite());

}


void Objeto::CogerObjeto(){
    estado=true;
    Anim->volverInvisible();
    posicionX = 0; 
    posicionY = 0;
}

//Destructor
Objeto::~Objeto()
{
 delete Anim;
}

//geters
bool Objeto::getEstado(){
 return estado;
}
int Objeto::getPosicionX(){
 return posicionX;
}
int Objeto::getPosicionY(){
 return posicionY;
}

void Objeto::setPosicion(float x, float y){
    posicionX=x;
    posicionY=y;
}

void Objeto::setRecogible(bool b){
    recogible=b;
}

bool Objeto::getRecogible(){
    return recogible;
}

void Objeto::setUsable(bool us){
    usable=us;
}

bool Objeto::getUsable(){
    return usable;
}