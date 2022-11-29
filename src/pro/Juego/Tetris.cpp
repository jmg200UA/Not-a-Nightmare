#include "Tetris.h"

Tetris::Tetris(){
    t1=new sf::Texture;
    t2=new sf::Texture;
    t3=new sf::Texture;

    s1=new sf::Sprite;
    s2=new sf::Sprite;
    s3=new sf::Sprite;

    fuente= new sf::Font;
    texto = new sf::Text;
    temp=0;
    delay=0.7;

    direccion=0;

    objeto=0;
}

Tetris::~Tetris(){}

void Tetris::cargarTetris(){
    t1->loadFromFile("resources/tilestetris.png");
    t2->loadFromFile("resources/backgroundlevel0.png"); 
    t3->loadFromFile("resources/frame.png");

    s1->setTexture(*t1);
    s2->setTexture(*t2);
    s3->setTexture(*t3);

    fuente->loadFromFile("resources/pixel3.ttf");

    
}

bool Tetris::comprobarPos(){
    for (int i=0;i<4;i++)
      if (a[i].x<0 || a[i].x>=largo || a[i].y>=alto) return 0;
      else if (matr[a[i].y][a[i].x]) return 0;

   return 1;
}

void Tetris::dibujarTetris(sf::RenderWindow &ventana){
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    temp+=time; 
    if(reloj==0){
        clock2.restart();
        reloj=1;
    }
    tiempo=clock2.getElapsedTime().asSeconds();
    cout<< "Tiempo" << tiempo <<endl;

    if(contfilas==1){
        texto->setString("Victoria");
		texto->setFont(*fuente);
		texto->setCharacterSize(160);
		texto->setColor(sf::Color(255, 0, 0));
		sf::FloatRect textRect = texto->getLocalBounds();
		texto->setOrigin(textRect.width/2,textRect.height/2);
		texto->setPosition(sf::Vector2f(640/2.0f,480/2.0f-100));
        ventana.draw(*texto);
        fin=true;

    } 
    else if(tiempo>80){
        texto->setString("Derrota");
		texto->setFont(*fuente);
		texto->setCharacterSize(160);
		texto->setColor(sf::Color(255, 0, 0));
		sf::FloatRect textRect = texto->getLocalBounds();
		texto->setOrigin(textRect.width/2,textRect.height/2);
		texto->setPosition(sf::Vector2f(640/2.0f,480/2.0f-100));
        ventana.draw(*texto);
        pierde=true;
    }
    else{
        if (Keyboard::isKeyPressed(Keyboard::Left)) direccion=-1;   
        if (Keyboard::isKeyPressed(Keyboard::Right)) direccion=1;
        if (Keyboard::isKeyPressed(Keyboard::Down)) delay=0.05;

        // Movimiento piezas
        for (int i=0;i<4;i++)  { copia[i]=a[i]; a[i].x+=direccion; }
        if (!comprobarPos()) for (int i=0;i<4;i++) a[i]=copia[i];

        // Movimiento hacia abajo
        if (temp>delay)
        {
            for(int i=0; i<4 ; i++ )
            {
                copia[i]=a[i];
                a[i].y +=1;
            }
            if(!comprobarPos())
            {
                for(int i=0;i<4;i++)
                {
                matr[copia[i].y][copia[i].x]=objeto;
                }
                objeto= 1 + rand()%7;
                int n=rand()% 7;
                for(int i=0;i<4;i++)
                {
                a[i].x=figuras[n][i].x;
                a[i].y=figuras[n][i].y;
                }
            }

            temp = 0;
        }

        ///////check lines//////////
        int linea=alto-1;
        for (int i=alto-1;i>0;i--)
        {   
            int contador=0;
            for (int j=0;j<largo;j++)
            {   
                if (matr[i][j]){
                    contador++;
                } 
                matr[linea][j]=matr[i][j];
            }
            if (contador<largo){
                linea--;
            } 
            else contfilas ++;

            cout << "CONTFILAS: " << contfilas << endl;
        }

        direccion=0;
        delay=0.7;

        // Dibujado del tetris
        ventana.clear();    
        ventana.draw(*s2);
            
        for (int i=0;i<alto;i++)
        for (int j=0;j<largo;j++)
        {
            if (matr[i][j]==0) continue;
            s1->setTextureRect(IntRect(matr[i][j]*18,0,18,18));
            s1->setPosition(j*18,i*18);
            s1->move(28,31); //offset
            ventana.draw(*s1);
        }

        for (int i=0;i<4;i++)
        {
            s1->setTextureRect(IntRect(objeto*18,0,18,18));
            s1->setPosition(a[i].x*18,a[i].y*18);
            s1->move(28,31); //offset
            ventana.draw(*s1);
        }

        ventana.draw(*s3);
        }

    
}

bool Tetris::checkVictoria(){
        return fin;
}

bool Tetris::derrotaTetris(){
        return pierde;
}