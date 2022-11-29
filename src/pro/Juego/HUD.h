

#include <SFML/Graphics.hpp> 
#include <iostream>
using namespace std;
using namespace sf;

class HUD
{
private:
     sf::Texture *vidas;
     sf::Sprite *spriteVidas;  
     int contadorcito;   
public:
    HUD();
    int cargarHud();
    void setContadorHUD(int);
    void drawHUD(sf::RenderWindow &);
    
    
    ~HUD();
};

