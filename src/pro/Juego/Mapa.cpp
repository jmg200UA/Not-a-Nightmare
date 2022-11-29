//Cargador de mapas.

#include "Mapa.h"

Mapa::Mapa(string nomMapa)
{

  ancho = -1;
  alto = -1;
  tiledAncho = -1;
  tiledAlto = -1;
  map = new TileMap("map/aaa.png");
  tiles = nullptr;
  cargarMapa(nomMapa);
}

void Mapa::cargarMapa(string nomMapa)
{

  //Creamos un documento xml
  XMLDocument doc;

  // Comprobamos si existe algun tipo de error
  XMLError comprueba = doc.LoadFile(nomMapa.c_str());

  if (comprueba != XML_SUCCESS)
    return;

  XMLElement *mapita = doc.FirstChildElement("map");

  //Calculamos las capas totales

  for (XMLElement *child = mapita->FirstChildElement("layer"); child != NULL; child = child->NextSiblingElement("layer"))
  {
    numlayers++;
  }

  // Asignamos variables del mapa
  ancho = stoi(mapita->Attribute("width"));
  alto = stoi(mapita->Attribute("height"));
  tiledAncho = stoi(mapita->Attribute("tilewidth"));
  tiledAlto = stoi(mapita->Attribute("tileheight"));

  cout << " Mapa cargado con::   Alto  : " << alto << " Ancho : " << ancho << "   tileds : " << tiledAncho << " NumsLayer  : " << numlayers << endl;

  //primer parametro del load tamaño de los tiles en vector2u
  sf::Vector2u tilesize{static_cast<unsigned int>(tiledAncho), static_cast<unsigned int>(tiledAlto)};

  //Lector de matrices
  int columna = 0;
  int fila = 0;
  string gid{};
  tiles = new int *[numlayers];

  string namelayer{}; //para colisiones

  for (int i = 0; i < numlayers; ++i)
  {
    tiles[i] = new int[ancho * alto];
  }
  vector<int> mascaraColision{};

  for (XMLElement *child2 = mapita->FirstChildElement("layer"); child2 != NULL; child2 = child2->NextSiblingElement("layer"))
  {

    namelayer = child2->Attribute("name");

    for (XMLElement *child = child2->FirstChildElement("data")->FirstChildElement(); child != NULL; child = child->NextSiblingElement("tile"))
    {

      if (child->Attribute("gid") != NULL)
      {

        gid = child->Attribute("gid");
      }
      else
      {
        gid = "0";
      }

      //Compruebo si la capa es la de colisiones en cuyo caso entonces relleno el vector

      if (namelayer == "Colisiones")
        mascaraColision.push_back(stoi(gid));

      tiles[fila][columna] = stoi(gid) - 1; // -1 por que va de 1 a 15 en el gris pero en array es de 0 a 14
      columna++;
    }

    columna = 0;

    fila++;
  }

  size_t contador = -1;

  for (int i = 0; i < alto; i++)
  {
    vector<int> aux{};
    for (int j = 0; j < ancho; j++)
    {
      contador++;
      if (contador < mascaraColision.size())
      {
        aux.push_back(mascaraColision.at(contador));
      }
    }
    colisiones.push_back(aux);
  }

  map->load(tilesize, tiles, ancho, alto, numlayers);
}

void Mapa::drawMapa(sf::RenderWindow &ventana)
{

  map->draw(ventana);
}

void Mapa::clearMap()
{

  if (tiles != nullptr)
  {
    for (int i = 0; i < numlayers; i++)
    {
      delete[] tiles[i];
    }
    delete[] tiles;
    tiles = nullptr;
  }

  ancho = -1;
  alto = -1;
  tiledAncho = -1;
  tiledAlto = -1;
  numlayers = 0;

  for (int i = colisiones.size()-1; i > -1; i--)
  {
    colisiones.at(i).clear();
  }
  colisiones.clear();
}

bool Mapa::reloadMap(string nomMap)
{
  if (nomMap != "")
  {
    clearMap();
    cargarMapa(nomMap);
    return true;
  }
  return false;
}

bool Mapa::colisionMap(int posXentity, int posYentity, int spriteAncho,int spriteAlto)
{
  // 4 puntos  

  int posXxentity = posXentity+spriteAncho;
  int posYyentity = posYentity+spriteAlto;
  

 

  bool hayColision = true; 

  bool CoprobacionEsquina1 = true;
  bool CoprobacionEsquina2 = true;
  bool CoprobacionEsquina3 = true;
  bool CoprobacionEsquina4 = true;

  //Comprobacion 1a esquina sup - Izqu

  
  int x=0;
  int y=0;

  if (posXentity > -1 && posXentity < 641 && posYentity > -1 && posYentity < 481)
  {
     x = posXentity / 32;
     y = posYentity / 32;   

    if (x > -1 && x < ancho && y > -1 && y < alto )
    {
      
      if (colisiones.at(y).at(x) == 0)
      {
        CoprobacionEsquina1=false;
      }
    }
  }

  //Comprobacion 2a esquina Inf - Izq

  x=0;
  y=0;

  if (posXentity > -1 && posXentity < 641 && posYyentity > -1 && posYyentity < 481)
  {
     x = posXentity / 32;
     y = posYyentity / 32;   

    if (x > -1 && x < ancho && y > -1 && y < alto )
    {
      
      if (colisiones.at(y).at(x) == 0)
      {
        CoprobacionEsquina2=false;
      }
    }
  }


//Comprobacion 3a Esquina Sup - Der

x=0;
y=0;

if (posXxentity > -1 && posXxentity < 641 && posYentity > -1 && posYentity < 481)
  {
     x = posXxentity / 32;
     y = posYentity / 32;   

    if (x > -1 && x < ancho && y > -1 && y < alto )
    {
      
      if (colisiones.at(y).at(x) == 0)
      {
        CoprobacionEsquina3=false;
      }
    }
  }


//Comprobacion 4a Esquina Inf - Der

x=0;
y=0;

if (posXxentity > -1 && posXxentity < 641 && posYyentity > -1 && posYyentity < 481)
  {
     x = posXxentity / 32;
     y = posYyentity / 32;   

    if (x > -1 && x < ancho && y > -1 && y < alto )
    {
      
      if (colisiones.at(y).at(x) == 0)
      {
        CoprobacionEsquina4=false;
      }
    }
  }


// Comprobar colision

if( !CoprobacionEsquina1 && !CoprobacionEsquina2 && !CoprobacionEsquina3 && !CoprobacionEsquina4 ){

  hayColision=false;

}

/*

cout <<posXentity<<endl;
cout <<posYentity<<endl;
cout <<spriteAncho<<endl;
cout <<spriteAlto<<endl;
cout <<posXxentity<<endl;
cout <<posYyentity<<endl;

cout << " EXISTE COLISION ??? "<<hayColision<<endl;

cout << " ESQUINA 1"<<CoprobacionEsquina1<<endl; 
cout << " ESQUINA 2"<<CoprobacionEsquina2<<endl; 
cout << " ESQUINA 3"<<CoprobacionEsquina3<<endl; 
cout << " ESQUINA 4"<<CoprobacionEsquina3<<endl; 
*/



  return hayColision;
}