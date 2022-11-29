//Clase animacion para los sprites de personaje y enemigos.



#include   "Animacion.h" 


using namespace std;
using namespace sf;

//constructor
animacion::animacion(){

textura= new sf::Texture;
sprite=new sf::Sprite;


}

//Cargar una textura con un nombre dado.
void animacion::cargarTextura(string nombreImg){
    //recordatorio: tengo que concatenar con "" el nombre de la imagen.

    

    if(!textura->loadFromFile(nombreImg)){
        std::cout<<"Ha habido un error al cargar la imagen "+ nombreImg <<endl;

    }else{
        sprite->setTexture(*textura);
    }
}



void animacion::crearVectores(int x){
    int y=4;

    int tamanyoX = textura->getSize().x/x;
    int tamanyoY = textura->getSize().y/y;

    AnchoX=tamanyoX;
    AltoY=tamanyoY;

    cout<< "tamaño x es : "<<tamanyoX<< " tamanyo y es :"<<tamanyoY<<endl;


    int posx=0;
    int posy =0;

    for(int i=0; i<y;i++){ // altura
        for (int j=0; j<x;j++){ //ancho

            posx=tamanyoX*j;
            posy=tamanyoY*i;

            sf::IntRect cubo= IntRect(posx,posy,tamanyoX,tamanyoY);
            
            switch (i)
            {
                case 0 :

                    moveUp.push_back(new sf::Sprite(*textura, cubo));

                    break;

                case 1 :

                    moveLeft.push_back(new sf::Sprite(*textura, cubo));

             
                    break;

                case 2 :

                    moveDown.push_back(new sf::Sprite(*textura, cubo));

                    break;

                case 3 :

                    moveRight.push_back(new sf::Sprite(*textura, cubo));

                    break;
                
                default:

                    cout<<"Ha surgido un error con los tamaños de y"<<endl;

                    break;
            }
        }
    }
}

void animacion::posicionar(int xx, int yy ){

x=xx;
y=yy;

    sprite->setPosition(x,y);

}

void animacion::volverInvisible(){
    
    sprite->setColor(sf::Color::Transparent);
}

std::vector<sf::Sprite*> animacion::getUp(){

    return moveUp;
}

std::vector<sf::Sprite*> animacion::getDown(){

    return moveDown;
}

std::vector<sf::Sprite*> animacion::getRight(){

    return moveRight;
}

std::vector<sf::Sprite*> animacion::getLeft(){

    return moveLeft;
}

sf::Sprite animacion::getSprite(){
    return *sprite;
}

animacion::~animacion(){
    //Meter clear para limpiar vectores
    delete textura;
    delete sprite;
}
int animacion::getX(){
    return x;
}

int animacion::getY(){
    return y;
}
int animacion::getSpriteX(){
    return AnchoX;
}

int animacion::getSpriteY(){
    return AltoY;
}