#include "Enemigo.h"

class Rebotes{
private:
sf::Texture *t1; //textura ladrillos
sf::Texture *t2; //textura fondo
sf::Texture *t3; //textura bola
sf::Texture *t4; //textura tabla
sf::Sprite *sBackground; //sprite fondo
sf::Sprite *sBall; //sprite bola
sf::Sprite *sPaddle; // sprite tabla
sf::Sprite block[100]; //sprite ladrillos
sf::Font *fuente; // fuente del texto final
sf::Text *texto; // texto final
float direccionx, direcciony; //direccion en x e y para cuando choque con ladrillo o pared rebote
float x, y; //posicion de la bola
int contbloques; // contador de bloques
bool fin;
bool pierde=false;
int contfuera;

public:
Rebotes();
~Rebotes();
void cargarRebotes();
void dibujarRebotes(sf::RenderWindow &);
bool finRebotes();
bool derrotaRebotes();
};