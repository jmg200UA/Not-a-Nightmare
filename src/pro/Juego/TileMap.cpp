#include "TileMap.h"

TileMap::TileMap(const std::string& tileset)
{
    //ctor
    if (!m_tileset.loadFromFile(tileset))
        std::cout << "No se ha cargado el tileset" << std::endl;
}

TileMap::~TileMap()
{
    //dtor
}

bool TileMap::load(sf::Vector2u tileSize, int** tiles, unsigned int width, unsigned int height, unsigned int numlayers){
    
   /* colisiones = new int*[width];
    for(int i = 0; i < width;++i){
        colisiones[i] = new int [height];
    }

    for(int i = 0; i < width;++i){
        for(int j = 0; j < height;++j){
            colisiones[i][j] = 0;
        }
    }
*/
    //check if there's an image loaded to the texture variable
    if(m_tileset.getSize().x == 0 || m_tileset.getSize().y == 0)
        std::cout << "No existe una imagen cargada en la textura del tileset" << std::endl;

    // resize the vertex array to fit the level size
    m_vertices1.setPrimitiveType(sf::Quads);
    m_vertices1.resize(width * height * 4);

    m_vertices2.setPrimitiveType(sf::Quads);
    m_vertices2.resize(width * height * 4);

    m_vertices3.setPrimitiveType(sf::Quads);
    m_vertices3.resize(width * height * 4);

    m_vertices4.setPrimitiveType(sf::Quads);
    m_vertices4.resize(width * height * 4);

    m_vertices5.setPrimitiveType(sf::Quads);
    m_vertices5.resize(width * height * 4);

    m_vertices6.setPrimitiveType(sf::Quads);
    m_vertices6.resize(width * height * 4);

    // populate the vertex array, with one quad per tile
    for(unsigned int l = 0; l < numlayers; ++l)
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {

                // get the current tile number
                int tileNumber = tiles[l][i + j * width];
                //std::cout << "tileNumber: " << tiles[0][0] << std::endl; //ESTO LO SACA BIEN Y LAS OTRAS COSAS TAMBIEN LO HA HECHO POR TANTO ES SOLO QUE NO ESTA HACIENDO LO DE LOS QUADS BIEN  Y SOLO PINTA LA ULTIMA CAPA SE VA SOBREESCRIENDO TODO EN EL FOR O ALGO ASI
                // find its position in the tileset texture
                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                // get a pointer to the current tile's quad
                sf::Vertex* quad;
                switch(l) {
                    case 0:
                        //if(tiles[l][j][i]==2){
                            //colisiones[i][j] = 1;
                            //std::cout << tileNumber << std::endl;
                            //std::cout << colisiones[i][j] << std::endl;
                        //}
                        quad = &m_vertices1[(i + j * width) * 4];
                        break;
                    case 1:
                        quad = &m_vertices2[(i + j * width) * 4];
                        break;
                    case 2:
                        quad = &m_vertices3[(i + j * width) * 4];
                        break;
                    case 3:
                        quad = &m_vertices4[(i + j * width) * 4];
                        break;
                    case 4:
                        quad = &m_vertices5[(i + j * width) * 4];
                        break;
                    case 5:
                        //std::cout << tileNumber << std::endl;
                        quad = &m_vertices6[(i + j * width) * 4];
                        break;
                }

                // define its 4 corners
                quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                // define its 4 texture coordinates
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);


            }

    return true;
}

void TileMap::draw(sf::RenderWindow& ventana)
{
    // apply the transform
    //states.transform *= getTransform();

    // apply the tileset texture
    //states.texture = &m_tileset;

    // draw the vertex array
    //target.draw(m_vertices, states);
    ventana.draw(m_vertices1, &m_tileset);
    ventana.draw(m_vertices2, &m_tileset);
    ventana.draw(m_vertices3, &m_tileset);
    ventana.draw(m_vertices4, &m_tileset);
    ventana.draw(m_vertices5, &m_tileset);
    ventana.draw(m_vertices6, &m_tileset);
}

