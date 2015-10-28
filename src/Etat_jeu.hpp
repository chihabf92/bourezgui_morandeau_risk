#ifndef ETAT_H
#define ETAT_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
class Etat_jeu : public sf::Drawable, public sf::Transformable
{
	public:
		bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

	private:
		    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		    sf::VertexArray m_vertices;
   			sf::Texture m_tileset;

};

#endif