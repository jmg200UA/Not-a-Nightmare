#include "SFML/Graphics.hpp"
#include <iostream>

#include "include/config.h"
//#include "Objeto.h"
//#include "Jugador.h"
//#include "Enemigo.h"
#include "Menu.h"
#include "Puzzle.h"
#include "Mapa.h"
#include "HUD.h"

//Main principal con los bucles y eventos principales del juego .

int main()
{
    bool DEBUG = false;

    //Crear ventana
    sf::RenderWindow ventana(sf::VideoMode(640, 480), "Not a Nightmare");
    ventana.setFramerateLimit(60);
    ventana.setVerticalSyncEnabled(true);

    

    Vector2f sizecuboo(3, 3);
    sf::RectangleShape cuboo;
    cuboo.setSize(sizecuboo);

    int contador=3;
    
    Mapa mapapa = Mapa("map/nvl0-1xml.tmx");
    Objeto *cubo = new Objeto("resources/cuadrado.png");
    Objeto *circulo = new Objeto("resources/circulo.png");
    Objeto *triangulo = new Objeto("resources/triangulo.png");
    Objeto *llave = new Objeto("resources/Pila.png");
    Objeto *enchufe = new Objeto("resources/Cable.png");
    Objeto *usable = new Objeto("resources/Consola.png");
    Objeto *usable2 = new Objeto("resources/recreatica.png");
    Objeto *usable3 = new Objeto("resources/Ordenador.png");

    //enemigos del nivel 1
    Enemigo enem = Enemigo("resources/ghost.png");

    //enemigos para el nivel 2
    Enemigo enem2 = Enemigo("resources/ghost.png");
    Enemigo enem8 = Enemigo("resources/ghost.png");
    Enemigo enem9 = Enemigo("resources/ghost.png");
    

    //enemigos para el nivel 3
    Enemigo enem3 = Enemigo("resources/ghost.png"); // sala1
    Enemigo enem4 = Enemigo("resources/ghost.png"); // sala3
    Enemigo enem5 = Enemigo("resources/ghost.png"); // sala3 
    Enemigo enem6 = Enemigo("resources/ghost.png"); // sala3
    //Enemigo enem7 = Enemigo("resources/ghost.png"); // sala0

    Jugador jug = Jugador("resources/Animacion.png");
    Puzzle puz = Puzzle();
    bool puzzleON = false;

    puz.cargarPuzzle(0);
    puz.cargarPuzzle(1);
    puz.cargarPuzzle(2);

    int Vermenu = 0; // si 0, menu activo, sino se cierra
    int VerOpciones = 0;
    int nivel = 0;  
    int sala = 0;    //numero de mapa
    bool terminado = false;
    string nombre = ""; //variable nombre del mapa

    //Menu
    Menu menu(ventana.getSize().x, ventana.getSize().y, 0);
    Menu menu2(ventana.getSize().x, ventana.getSize().y, 1);
    Menu menu3(ventana.getSize().x, ventana.getSize().y, 2);
    HUD vidas = HUD();

    sf::Font fuente;
    if (!fuente.loadFromFile("resources/pixel2.ttf"))
    {
        return EXIT_FAILURE;
    }

    sf::Texture texture;
    if (!texture.loadFromFile("resources/imagen.jpg"))
    {
        return EXIT_FAILURE;
    }

    sf::Texture texture2;
    if (!texture2.loadFromFile("resources/imagen2.jpg"))
    {
        return EXIT_FAILURE;
    }

    sf::Texture texture3;
    if (!texture3.loadFromFile("resources/Opciones.png"))
    {
        return EXIT_FAILURE;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);

     sf::Sprite spritego;
    spritego.setTexture(texture);// game over

    sprite.setPosition(sf::Vector2f(0.f, 0.f));
    spritego.setPosition(sf::Vector2f(0.f, 0.f));// game over

    sf::Text texto("Not A Nightmare", fuente, 90);
    sf::Text textogo("VICTORIA", fuente, 120);// game over

    texto.setOrigin(texto.getLocalBounds().width / 2, 0);
    textogo.setOrigin(texto.getLocalBounds().width / 2, 0);// game over

    texto.setPosition(320, 70);
    textogo.setPosition(420, 70);

    texto.setColor(sf::Color(0, 0, 0));
    textogo.setColor(sf::Color(0, 0, 0));

    sf::Font fuente2;
    if (!fuente2.loadFromFile("resources/pixel3.ttf"))
    {
        return EXIT_FAILURE;
    }

    sf::Text texto2("Not A Nightmare", fuente2, 90);
    sf::Text textogo2("VICTORIA", fuente2, 120);
    sf::Text texto5("GAME OVER", fuente, 90);
    sf::Text texto6("GAME OVER", fuente2, 90);

    texto5.setPosition(420, 70);
    texto6.setPosition(423, 70);
    texto5.setOrigin(texto2.getLocalBounds().width / 2, 0);
    texto6.setOrigin(texto2.getLocalBounds().width / 2, 0);

    
    texto5.setColor(sf::Color(0, 0, 0));
    texto6.setColor(sf::Color(255, 255, 255));

    texto2.setOrigin(texto2.getLocalBounds().width / 2, 0);
    textogo2.setOrigin(texto2.getLocalBounds().width / 2, 0);

    texto2.setPosition(318, 70);
    textogo2.setPosition(423, 70);

    texto2.setColor(sf::Color(255, 255, 255));
    textogo2.setColor(sf::Color(255, 255, 255));

    sf::Text texto3("PAUSA", fuente, 90);

    texto3.setOrigin(texto3.getLocalBounds().width / 2, 0);

    texto3.setPosition(320, 70);

    texto3.setColor(sf::Color(0, 0, 0));

    sf::Text texto4("PAUSA", fuente2, 90);

    texto4.setOrigin(texto4.getLocalBounds().width / 2, 0);

    texto4.setPosition(318, 70);

    texto4.setColor(sf::Color(255, 255, 255));

    sf::Sprite sprite2;
    sprite2.setTexture(texture2);

    sprite2.setPosition(sf::Vector2f(0.f, 0.f));

    sf::Sprite sprite3;
    sprite3.setTexture(texture3);

    sprite3.setPosition(sf::Vector2f(0.f, 0.f));

    while (ventana.isOpen())
    {

        sf::Event Evento;
        puz.cogeEvento(Evento);
        cubo->objetoInformacion(1, 200.00, 200.00);
        circulo->objetoInformacion(2, 250.000, 300.00);
        triangulo->objetoInformacion(3, 180.000, 400.00);
        llave->objetoInformacion(4, 300.000, 200.00);
        enchufe->objetoInformacion(8, 310.000, 230.00);
        usable->objetoInformacion(5, 280.000, 300.00);
        usable->setUsable(true);
        usable2->objetoInformacion(6, 305.000, 205.00);
        usable2->setUsable(true);
        usable3->objetoInformacion(7, 310.00, 150.00);
        usable3->setUsable(true);
        jug.setInventario(cubo);
        jug.setInventario(circulo);
        jug.setInventario(triangulo);
        jug.setInventario(llave);
        jug.setInventario(enchufe);
        jug.setInventario2(usable);
        jug.setInventario2(usable2);
        jug.setInventario2(usable3);

        if(contador==0){
            cout<<"FIN PARTIDA"<<endl;
            Vermenu=3;

           
            
        }

        cuboo.setFillColor(sf::Color::Blue);

        //       Puzzle puzzle = Puzzle(Evento);

        while (ventana.pollEvent(Evento))
        {
                switch (Evento.type)
                {
                case sf::Event::Closed:

                    ventana.close();
                    break;

                default:
                    break;
                    //Se pulsó una tecla, imprimo su codigo
                case sf::Event::KeyPressed:

                    //Verifico si se pulsa alguna tecla de movimiento
                    switch (Evento.key.code)
                    {

                    //Mapeo del cursor
                    case sf::Keyboard::W:

                        jug.accionesJugador(1, mapapa);

                        break;

                    case sf::Keyboard::S:
                        jug.accionesJugador(2, mapapa);

                        break;   

                    case sf::Keyboard::D:
                        jug.accionesJugador(3, mapapa);

                        break;

                    case sf::Keyboard::A:
                        jug.accionesJugador(4, mapapa);

                        break;

                    case sf::Keyboard::Up:
                        if (VerOpciones == 0)
                        {
                            menu.MoverArriba();
                            menu2.MoverArriba();
                        }

                        break;

                    case sf::Keyboard::Down:
                        if (VerOpciones == 0)
                        {
                            menu.MoverAbajo();
                            menu2.MoverAbajo();
                        }

                        break;

                    case sf::Keyboard::E:
                        jug.accionesJugador(5, mapapa);
                        break;

                    case sf::Keyboard::M:
                        if (Vermenu != 0)
                        {
                            Vermenu = 1;
                        }

                        break;

                        // VOLVER HACIA ATRAS DESDE EL MENU
                    case sf::Keyboard::Escape:

                        if (VerOpciones == 1)
                        {
                            VerOpciones = 0;
                        }

                        if (Vermenu == 1)
                        {
                            Vermenu = 2;
                        }

                        break;
                    case sf::Keyboard::Return:
                        if (Vermenu == 0)
                        {
                            switch (menu.GetItemPresionado())
                            {
                            case 0:
                                if (VerOpciones == 0)
                                {
                                    std::cout << "Boton Jugar ha sido pulsado" << std::endl;
                                    Vermenu = 4;
                                }
                                break;
                            case 1:
                                if (VerOpciones == 0)
                                {
                                    std::cout << "Boton Opciones ha sido pulsado" << std::endl;
                                    VerOpciones = 1;
                                }
                                break;
                            case 2:
                                if (VerOpciones == 0)
                                {
                                    ventana.close();
                                }
                                break;
                            }
                        }
                        else if (Vermenu == 1)
                        {
                            switch (menu2.GetItemPresionado())
                            {
                            case 0:
                                if (VerOpciones == 0)
                                {
                                    std::cout << "Boton Jugar ha sido pulsado" << std::endl;
                                    Vermenu = 4;
                                }
                                break;
                            case 1:
                                if (VerOpciones == 0)
                                {
                                    std::cout << "Boton Opciones ha sido pulsado" << std::endl;
                                    VerOpciones = 1;
                                }
                                break;
                            case 2:
                                if (VerOpciones == 0)
                                {
                                    ventana.close();
                                }
                                break;
                            }
                        } else if(Vermenu == 3 || terminado){
                             switch (menu3.GetItemPresionado())
                            {
                            case 0:
                               
                                std::cout << "Salir GAME OVER" << std::endl;
                                
                                ventana.close();
                            break;
                            }

                        }

                        break;

                    //Cualquier tecla desconocida se imprime por pantalla su código
                    default:
                        break;
                    }
                }
        }

        cout << "Posicion player: " << jug.getPosicionX() <<" " << jug.getPosicionY() << endl;
        cout << "Objetos: " << jug.getContador() << endl;
        switch (nivel)
        {
        case 0:
            
            if (sala == 0)
            {
                enem.getPosicionJugX(jug);
                enem.getPosicionJugY(jug);
                enem.movimientoenemigo();

                //comprueba posicion del enemigo y colision
                jug.getPosicionEnemX(enem.getPosicionEnemX());
                jug.getPosicionEnemY(enem.getPosicionEnemY());

                if (jug.comprobarColisionEnemigo() || jug.returnChoque())
                {
                    jug.setPosicion(100, 100);
                    jug.choqueFalse();
                    contador--;
                }

                ventana.clear();

                if (jug.getContador() == 3 && jug.getPosicionX() > 600 && jug.getPosicionY() > 224 && jug.getPosicionY() < 237)
                {
                    cout << "ENTRA MAPA" << endl;
                    jug.setPosicion(5, 230);
                    mapapa.reloadMap("map/nvl0-2xml.tmx");
                    jug.inicializaContador();
                    enem.reiniciarEnemigo();
                    sala = 1;
                }
            }

            else if (sala == 1)
            {
                jug.setSalaUsable(1);
                if (jug.getMinijuego())
                {
                    puzzleON = true;
                }
                if(puz.checkVictoria(0)){
                    cout << "NIVEL TERMINADO" << endl;
                    nivel=1;
                    sala=0;
                    jug.setPosicion(550, 370);
                    jug.setNivel(1);
                    jug.setMinijuego();
                    jug.inicializaContador();
                    enem8.setPosicion(310,320);
                    enem9.setPosicion(400,150);
                    mapapa.reloadMap("map/nvl1-1xml.tmx");
                    jug.setSalaUsable(0);
                    puzzleON=false;
                }else if(puz.checkDerrota(0)){
                    contador=0;
                }
            }
            break;
        
        case 1:
            
            // CAMBIOS DE SALA

                //PARA ENTRAR AL BOSQUE
                if (sala == 0 && jug.getPosicionX() < 2 && jug.getPosicionY() > 352  && jug.getPosicionY() < 397){
                    jug.setPosicion(576, 320);
                    enem2.setPosicion(370,170);
                    mapapa.reloadMap("map/nvl1-2xml.tmx");
                    sala = 1;
                    jug.setSalaUsable(0);
                    jug.setSalaRecogible(1);
                }
                
                //PARA VOLVER DEL BOSQUE
                if (sala == 1 && jug.getPosicionX() > 606 && jug.getPosicionY() < 365  && jug.getPosicionY() > 160){
                    jug.setPosicion(3, 363);
                    mapapa.reloadMap("map/nvl1-1xml.tmx");
                    sala = 0;
                    jug.setSalaUsable(0);
                    jug.setSalaRecogible(0);
                }

                //PARA ENTRAR A LA SALA RECREATIVA
                if (sala == 0 && jug.getPosicionY() < 43 && jug.getPosicionX() > 512  && jug.getPosicionX() < 544 && jug.getContador()==1){
                    cout << "CONTADOR" << jug.getContador() << endl;
                    jug.setSalaUsable(2);
                    jug.setPosicion(303, 360);
                    mapapa.reloadMap("map/nvl1-3xml.tmx");
                    sala = 2;
                    jug.setSalaRecogible(2);
                }
                //PARA SALIR DE LA SALA RECREATIVA
                if (sala == 2 && jug.getPosicionY() > 425){
                    jug.setPosicion(530, 43);
                    mapapa.reloadMap("map/nvl1-1xml.tmx");
                    sala = 0;
                    jug.setSalaUsable(0);
                    jug.setSalaRecogible(0);
                }


            // CODIGO PARA CADA SALA
                if(sala == 0){
                    enem8.getPosicionJugX(jug);
                    enem8.getPosicionJugY(jug);
                    enem8.movimientoenemigo6();

                    //comprueba posicion del enemigo y colision
                    jug.getPosicionEnemX(enem8.getPosicionEnemX());
                    jug.getPosicionEnemY(enem8.getPosicionEnemY());

                    if (jug.returnChoque() || jug.comprobarColisionEnemigo())
                    {   
                        jug.setPosicion(550, 370);
                        jug.choqueFalse();
                        contador--;
                    }

                    enem9.getPosicionJugX(jug);
                    enem9.getPosicionJugY(jug);
                    enem9.movimientoenemigo6();

                    //comprueba posicion del enemigo y colision
                    jug.getPosicionEnemX(enem9.getPosicionEnemX());
                    jug.getPosicionEnemY(enem9.getPosicionEnemY());

                    if (jug.returnChoque() || jug.comprobarColisionEnemigo())
                    {   
                        jug.setPosicion(550, 370);
                        jug.choqueFalse();
                        contador--;
                    }
                }
                if(sala == 1){
                    enem2.getPosicionJugX(jug);
                    enem2.getPosicionJugY(jug);
                    enem2.movimientoenemigo2();

                    //comprueba posicion del enemigo y colision
                    jug.getPosicionEnemX(enem2.getPosicionEnemX());
                    jug.getPosicionEnemY(enem2.getPosicionEnemY());

                    if (jug.returnChoque() || jug.comprobarColisionEnemigo())
                    {   
                        jug.setPosicion(550, 370);
                        jug.choqueFalse();
                        mapapa.reloadMap("map/nvl1-1xml.tmx");
                        sala = 0;
                        contador--;
                    }
                }
                if(sala == 2){
                    if (jug.getMinijuego())
                    {
                        puzzleON = true;
                    }
                    if(puz.checkVictoria(1)){
                        cout << "NIVEL TERMINADO" << endl;
                        nivel=2;
                        sala=0;
                        jug.setPosicion(312, 232);
                        //enem7.setPosicion(290, 10);
                        jug.setNivel(2);
                        jug.setMinijuego();
                        mapapa.reloadMap("map/nvl2-1xml.tmx");
                        jug.setSalaUsable(0);
                        puzzleON=false;
                        jug.inicializaContador();
                    }else if(puz.checkDerrota(1)){
                        contador=0;
                    }
                }
                
                

            break;
        
        case 2:
            // CAMBIOS DE SALA

                //PARA ENTRAR AL PASILLO
                if (sala == 0 && jug.getPosicionY() < 5 && jug.getPosicionX() > 256  && jug.getPosicionX() < 384){
                    jug.setPosicion(288, 384);
                    enem3.setPosicion(360,340);
                    mapapa.reloadMap("map/nvl2-2xml.tmx");
                    sala = 1;
                    jug.setSalaUsable(0);
                    jug.setSalaRecogible(1);
                }
                //PARA VOLVER AL PATIO
                if (sala == 1 && jug.getPosicionY() > 425){
                    jug.setPosicion(288, 32);
                    mapapa.reloadMap("map/nvl2-1xml.tmx");
                    sala = 0;
                    jug.setSalaUsable(0);
                    jug.setSalaRecogible(0);
                    enem3.reiniciarEnemigo();
                }

                //PARA ENTRAR A LA BIBLIOTECA
                if (sala == 1 && jug.getPosicionY() < 64 && jug.getContador()==1){
                    jug.setPosicion(288, 384);
                    mapapa.reloadMap("map/nvl2-3xml.tmx");
                    sala = 2;
                    jug.setSalaUsable(3);
                    jug.setSalaRecogible(2);
                }
                //PARA SALIR DE LA BIBLIOTECA
                if (sala == 2 && jug.getPosicionY() > 425){
                    jug.setPosicion(545, 100);
                    mapapa.reloadMap("map/nvl2-2xml.tmx");
                    sala = 1;
                    jug.setSalaUsable(0);
                }
                //PARA ENTRAR A LA CLASE
                if (sala == 1 && jug.getPosicionY() > 352 && jug.getPosicionY() <397 && jug.getPosicionX() < 2){
                    jug.setPosicion(544, 397);
                    enem4.setPosicion(10,300);
                    enem5.setPosicion(500,150);
                    enem6.setPosicion(270,340);
                    mapapa.reloadMap("map/nvl2-4xml.tmx");
                    sala = 3;
                    jug.setSalaUsable(0);
                    jug.setSalaRecogible(3);
                }
                //PARA SALIR DE LA CLASE
                if (sala == 3 && jug.getPosicionY() > 352 && jug.getPosicionY() < 448 && jug.getPosicionX() > 600){
                    jug.setPosicion(5, 380);
                    mapapa.reloadMap("map/nvl2-2xml.tmx");
                    sala = 1;
                    jug.setSalaRecogible(1);
                }

                // CODIGO PARA CADA SALA

                
                if(sala == 0){
                    /*enem7.getPosicionJugX(jug);
                    enem7.getPosicionJugY(jug);
                    enem7.movimientoenemigo3();

                    //comprueba posicion del enemigo y colision
                    jug.getPosicionEnemX(enem7.getPosicionEnemX());
                    jug.getPosicionEnemY(enem7.getPosicionEnemY());

                    if (jug.returnChoque() || jug.comprobarColisionEnemigo())
                    {   
                        jug.setPosicion(312, 232);
                        enem7.setPosicion(290, 10);
                        jug.choqueFalse();
                    }*/
                }
                if(sala == 1){
                    enem3.getPosicionJugX(jug);
                    enem3.getPosicionJugY(jug);
                    enem3.movimientoenemigo4();

                    //comprueba posicion del enemigo y colision
                    jug.getPosicionEnemX(enem3.getPosicionEnemX());
                    jug.getPosicionEnemY(enem3.getPosicionEnemY());

                    if (jug.returnChoque() || jug.comprobarColisionEnemigo())
                    {   
                        jug.setPosicion(288, 384);
                        jug.choqueFalse();
                        contador--;
                    }
                }
                if(sala == 2){
                    if (jug.getMinijuego())
                    {
                        puzzleON = true;
                    }
                    if(puz.checkVictoria(2)){
                        cout << "JUEGO TERMINADO" << endl;
                        jug.setMinijuego();
                        jug.setSalaUsable(0);
                        puzzleON=false;
                        terminado=true;
                    }else if(puz.checkDerrota(2)){
                        contador=0;
                    }
                }
                if(sala == 3){

                    //colision enemigo 4
                    enem4.getPosicionJugX(jug);
                    enem4.getPosicionJugY(jug);
                    enem4.movimientoenemigo4();

                    //comprueba posicion del enemigo y colision
                    jug.getPosicionEnemX(enem4.getPosicionEnemX());
                    jug.getPosicionEnemY(enem4.getPosicionEnemY());

                    if (jug.returnChoque() || jug.comprobarColisionEnemigo())
                    {   
                        jug.setPosicion(544, 397);
                        jug.choqueFalse();
                        contador--;
                    }

                    //colision enemigo 5
                    enem5.getPosicionJugX(jug);
                    enem5.getPosicionJugY(jug);
                    enem5.movimientoenemigo4();

                    //comprueba posicion del enemigo y colision
                    jug.getPosicionEnemX(enem5.getPosicionEnemX());
                    jug.getPosicionEnemY(enem5.getPosicionEnemY());

                    if (jug.returnChoque() || jug.comprobarColisionEnemigo())
                    {   
                        jug.setPosicion(544, 397);
                        jug.choqueFalse();
                        contador--;
                    }

                    //colision enemigo 6
                    enem6.getPosicionJugX(jug);
                    enem6.getPosicionJugY(jug);
                    enem6.movimientoenemigo5();

                    //comprueba posicion del enemigo y colision
                    jug.getPosicionEnemX(enem6.getPosicionEnemX());
                    jug.getPosicionEnemY(enem6.getPosicionEnemY());

                    if (jug.returnChoque() || jug.comprobarColisionEnemigo())
                    {   
                        jug.setPosicion(544, 397);
                        jug.choqueFalse();
                        contador--;
                    }
                }

            break;

        default:
            break;
        }
        mapapa.drawMapa(ventana);
        vidas.setContadorHUD(contador);
        vidas.drawHUD(ventana);

        

        //DIBUJAR SALAS

            
            switch (nivel)
            {
            //NIVEL 0
            case 0:
                if(sala == 0){
                    for (int i = 0; i < 3; i++)
                    {
                        jug.getInventario().at(i)->DibujaObjeto(ventana);
                    }
                    enem.dibujasion(ventana);
                }else if(sala == 1){
                    jug.getInventario2().at(0)->DibujaObjeto(ventana);
                    if(puzzleON){
                        puz.dibujarPuzzle(0, ventana);
                    }
                }
                break;

            //NIVEL 1
            case 1:
                if(sala == 0){
                    enem8.dibujasion(ventana);
                    enem9.dibujasion(ventana);
                }
                else if(sala == 1){
                    jug.getInventario().at(3)->DibujaObjeto(ventana);
                    enem2.dibujasion(ventana);
                }
                else if(sala == 2){
                    jug.getInventario2().at(1)->DibujaObjeto(ventana);
                    if(puzzleON){
                        puz.dibujarPuzzle(1, ventana);
                    }
                }
                break;

            //NIVEL 2
            case 2:
                if(sala == 0){
                    //enem7.dibujasion(ventana);
                }
                if(sala == 1){
                    enem3.dibujasion(ventana);
                }
                else if(sala == 2){
                    jug.getInventario2().at(2)->DibujaObjeto(ventana);
                    if(puzzleON){
                        puz.dibujarPuzzle(2, ventana);
                    }
                    if(terminado){
                        ventana.draw(spritego);
                        ventana.draw(textogo);
                        ventana.draw(textogo2);
                        jug.setPosicion(-100,-100);
                        menu3.dibujar(ventana);
                    }
                }
                else if(sala==3){
                    jug.getInventario().at(4)->DibujaObjeto(ventana);
                    enem4.dibujasion(ventana);
                    enem5.dibujasion(ventana);
                    enem6.dibujasion(ventana);
                }
                break;
            default:
                break;
            }
            
        if(!puzzleON){
            jug.dibujar(ventana);
        }
        
        if (Vermenu == 0)
        {
            ventana.draw(sprite);
            ventana.draw(texto);
            ventana.draw(texto2);
            menu.dibujar(ventana);
        }
        else if (Vermenu == 1)
        {
            ventana.draw(sprite2);
            ventana.draw(texto3);
            ventana.draw(texto4);
            menu2.dibujar(ventana);
        }else if (Vermenu == 3)
        {
            ventana.draw(sprite);
            ventana.draw(texto5);
            ventana.draw(texto6);
            menu3.dibujar(ventana);
        }

        if (VerOpciones == 1)
        {
            ventana.draw(sprite3);
        }
      



        if (DEBUG == true)
        {

            for (int i = 0; i < 480; i++)
            {
                for (int j = 0; j < 640; j++)
                {

                    if (mapapa.colisionMap(j, i, jug.getAnchoSprite(), jug.getAltoSprite()))
                    {

                        cuboo.setPosition(j, i);
                        ventana.draw(cuboo);
                    }
                }
            }
        }

        ventana.display();
    }
}
