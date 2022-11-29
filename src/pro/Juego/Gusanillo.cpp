#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;
#include "Gusanillo.h"

Gusanillo::Gusanillo(){
    //Texture t1,t2;
    t1=new sf::Texture;
    t2=new sf::Texture;
    t3=new sf::Texture;
    t4=new sf::Texture;

    sSnake=new sf::Sprite;
    sFondo=new sf::Sprite;
    sComida=new sf::Sprite;
    sCabeza=new sf::Sprite;

    fuente= new sf::Font;
    texto = new sf::Text;
    
	M = 30;
    N = 40;
    tam = 16;
    ancho = tam * N;
    alto = tam * M;
    num = 4;

    contlong=0;

    fin=false;
    pierde=false;
}

void Gusanillo::cargarGusano(){
    t1->loadFromFile("resources/backgroundlevel2.png");
    t2->loadFromFile("resources/cuerposnake.png"); 
    t3->loadFromFile("resources/eduradoraimon.png");
    t4->loadFromFile("resources/cabesasnake.png");

    sSnake->setTexture(*t2);
    sFondo->setTexture(*t1);
    sCabeza->setTexture(*t4);
    sComida->setTexture(*t3);

    fuente->loadFromFile("resources/pixel3.ttf");

    
    temp=0;
    delay=0.1;

    f.x=10;
    f.y=10;
}

void Gusanillo::Tick(){
    for (int i=num;i>0;--i)
    {
        s[i].x=s[i-1].x; 
        s[i].y=s[i-1].y;
    }

    if (dir==0) s[0].y+=1;      
    if (dir==1) s[0].x-=1;        
    if (dir==2) s[0].x+=1;         
    if (dir==3) s[0].y-=1;   

    if ((s[0].x==f.x) && (s[0].y==f.y))
    {
        num++; f.x=rand()%N; 
        f.y=rand()%M;
        contlong++;
        cout << "CONTLONG" << contlong << endl;
    }

    if (s[0].x>N) s[0].x=0; 
    if (s[0].x<0) s[0].x=N;
    if (s[0].y>M) s[0].y=0;  
    if (s[0].y<0) s[0].y=M;
 
    for (int i=1;i<num;i++)
    {
        if (s[0].x==s[i].x && s[0].y==s[i].y){
            num=i;
            contlong=num;
            if(i!=1){
                pierde = true;
            }
            cout << "NUMBLOQUES" << num << endl;
        }  
    }    
}

void Gusanillo::dibujarGusano(sf::RenderWindow &ventana){
    

    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    temp+=time; 

    if(contlong==7){
        s[0].y=0;
        s[0].x=0;
        texto->setString("Victoria");
		texto->setFont(*fuente);
		texto->setCharacterSize(160);
		texto->setColor(sf::Color(255, 0, 0));
		sf::FloatRect textRect = texto->getLocalBounds();
		texto->setOrigin(textRect.width/2,textRect.height/2);
		texto->setPosition(sf::Vector2f(640/2.0f,480/2.0f-100));
		fin=true;
        ventana.draw(*texto);
    } 
    else if(pierde){
        s[0].y=0;
        s[0].x=0;
        texto->setString("Derrota");
		texto->setFont(*fuente);
		texto->setCharacterSize(160);
		texto->setColor(sf::Color(255, 0, 0));
		sf::FloatRect textRect = texto->getLocalBounds();
		texto->setOrigin(textRect.width/2,textRect.height/2);
		texto->setPosition(sf::Vector2f(640/2.0f,480/2.0f-100));
		//fin=true;
        ventana.draw(*texto);
    } 
    else{
        if (Keyboard::isKeyPressed(Keyboard::Left)) dir=1;   
        if (Keyboard::isKeyPressed(Keyboard::Right)) dir=2;    
        if (Keyboard::isKeyPressed(Keyboard::Up)) dir=3;
        if (Keyboard::isKeyPressed(Keyboard::Down)) dir=0;

        if (temp>delay) {temp=0; Tick();}

        // Dibujamos los cuadrados que conforman el minijuego
        /*for (int i=0; i<N; i++)
        {
            for (int j=0; j<M; j++){
                sBack->setPosition(i*tam, j*tam);
                ventana.draw(*sBack);
            }      
        }*/
        ventana.draw(*sFondo);

        //Dibujamos el gusano
        for (int i=0;i<num;i++)
        { 
            sSnake->setPosition(s[i].x*tam, s[i].y*tam);  
            sCabeza->setPosition(s[i].x*tam, s[i].y*tam); 
            if(i==0){
                ventana.draw(*sCabeza);
            }
            else ventana.draw(*sSnake);
        }

        //Se acaba el juego y se imprime en pantalla el letrero de Victoria
        
        sSnake->setPosition(f.x*tam, f.y*tam);
        sComida->setPosition(f.x*tam, f.y*tam);  ventana.draw(*sComida); 
    }

     
}

bool Gusanillo::finGusano(){
    return fin;
}

bool Gusanillo::derrotaGusano(){
    return pierde;
}