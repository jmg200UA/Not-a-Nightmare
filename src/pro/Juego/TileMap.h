#ifndef TILEMAP_H
#define TILEMAP_H
#include <SFML/Graphics.hpp>
#include <iostream>

class TileMap //Herencia de clases Drawable y Transformable de sfml
{
    public:
        TileMap(const std::string& tileset);
        ~TileMap();
        bool load(sf::Vector2u tileSize, int** tiles, unsigned int width, unsigned int height, unsigned int numlayers);
        void draw(sf::RenderWindow& ventana);
        bool cargado;

    protected:
    private:
        sf::VertexArray m_vertices1;
        sf::VertexArray m_vertices2;
        sf::VertexArray m_vertices3;
        sf::VertexArray m_vertices4;
        sf::VertexArray m_vertices5;
        sf::VertexArray m_vertices6;
        sf::Texture m_tileset;
        //int **colisiones;
};

#endif // TILEMAP_H
