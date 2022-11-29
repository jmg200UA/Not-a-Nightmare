#include "Rebotes.h"

Rebotes::Rebotes(){
    //Texture t1,t2,t3,t4;
    t1=new sf::Texture;
    t2=new sf::Texture;
    t3=new sf::Texture;
    t4=new sf::Texture;

    sBackground=new sf::Sprite;
    sBall=new sf::Sprite;
    sPaddle=new sf::Sprite;

    fuente= new sf::Font;

    texto = new sf::Text;
    
	//direccion en x e y para cuando choque con ladrillo o pared rebote
    direccionx=3, direcciony=3;
	//posicion inicial de la bola
    x=500, y=300;
    // contador bloques
    contbloques=0;
    //booleano que indica si acabó el juego
    fin=false;
    contfuera=0;
}

Rebotes::~Rebotes(){}

void Rebotes::cargarRebotes(){
    t1->loadFromFile("resources/ladrillofantasmaesc.jpeg");
    t2->loadFromFile("resources/backgroundlevel1.png");
    t3->loadFromFile("resources/ballguasona.png");
    t4->loadFromFile("resources/hueso.png");

    //*sBackground(*t2), sBall(*t3), sPaddle(*t4);
    sBackground->setTexture(*t2);
    sBall->setTexture(*t3);
    sPaddle->setTexture(*t4);
    sPaddle->setPosition(300,440);

    //Sprite block[100];
	int contbloques=0;

	//dibujo los 100 bloques
    int n=0;
    for (int i=1;i<=10;i++)
    for (int j=1;j<=10;j++)
      {
         block[n].setTexture(*t1);
         block[n].setPosition(i*55,j*25);
         n++;
      }

    fuente->loadFromFile("resources/pixel3.ttf");
	
}

void Rebotes::dibujarRebotes(sf::RenderWindow &ventana){
    //int contbloques=0;
    x+=direccionx;
    for (int i=0;i<100;i++)
		//floatrect -> posicion de la bola en un radio de 6*6 intersecta un bloque
        if ( FloatRect(x+3,y+3,6,6).intersects(block[i].getGlobalBounds()) ) 
             {block[i].setPosition(-100,0); direccionx=-direccionx; contbloques++;}

	//aumentamos posicion en y según su dirección
    y+=direcciony;
    for (int i=0;i<100;i++)
        if ( FloatRect(x+3,y+3,6,6).intersects(block[i].getGlobalBounds()) ) 
             {block[i].setPosition(-100,0); direcciony=-direcciony; contbloques++;}

	//limites colisiones paredes
    if (x<0 || x>640)  direccionx=-direccionx;
    if (y<0 || y>480)  direcciony=-direcciony;
    if(y>=480) contfuera++;

	//movimiento plataforma izda-dcha 
    if (Keyboard::isKeyPressed(Keyboard::Right)) sPaddle->move(10,0);
    if (Keyboard::isKeyPressed(Keyboard::Left)) sPaddle->move(-10,0);

	//rebote con la plataforma
    if ( FloatRect(x,y,12,12).intersects(sPaddle->getGlobalBounds()) ) direcciony=-5;

	if(contbloques==100){
		direccionx=0;
		direcciony=0;
		texto->setString("Victoria");
		texto->setFont(*fuente);
		texto->setCharacterSize(160);
		texto->setColor(sf::Color(255, 0, 0));
		sf::FloatRect textRect = texto->getLocalBounds();
		texto->setOrigin(textRect.width/2,textRect.height/2);
		texto->setPosition(sf::Vector2f(640/2.0f,480/2.0f-100));
		fin=true;
	}

    else if(contfuera>8){
        direccionx=0;
		direcciony=0;
		texto->setString("Derrota");
		texto->setFont(*fuente);
		texto->setCharacterSize(160);
		texto->setColor(sf::Color(255, 0, 0));
		sf::FloatRect textRect = texto->getLocalBounds();
		texto->setOrigin(textRect.width/2,textRect.height/2);
		texto->setPosition(sf::Vector2f(640/2.0f,480/2.0f-100));
		//fin=true;
        pierde=true;
    }

	//posicion que va adoptando la bola con los rebotes
    sBall->setPosition(x,y);
    cout << y << endl;
    

    //ventana.clear();
	//dibujamos
	ventana.draw(*texto);
    ventana.draw(*sBackground);
    ventana.draw(*sBall);
    ventana.draw(*sPaddle);
	ventana.draw(*texto);

    for (int i=0;i<100;i++)
    ventana.draw(block[i]);
}

bool Rebotes::finRebotes(){
    return fin;
}

bool Rebotes::derrotaRebotes(){
    return pierde;
}