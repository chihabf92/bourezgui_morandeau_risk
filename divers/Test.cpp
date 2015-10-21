#include <cstdlib>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
using namespace sf;
int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");
	
	// création d'un quad
	sf::VertexArray quad(sf::Quads, 4);

	// on le définit comme un rectangle, placé en (10, 10) et de taille 100x100
	quad[0].position = sf::Vector2f(10, 10);
	quad[1].position = sf::Vector2f(194, 10);
	quad[2].position = sf::Vector2f(194, 322);
	quad[3].position = sf::Vector2f(10, 322);

	// et on définit la zone de texture à lui appliquer comme étant le rectangle de 25x50 démarrant en (0, 0)
	quad[0].texCoords = sf::Vector2f(0, 0);
	quad[1].texCoords = sf::Vector2f(184, 0);
	quad[2].texCoords = sf::Vector2f(184, 312);
	quad[3].texCoords = sf::Vector2f(0, 312);
	
	// définition de la texture avec le pays 1
	sf::Texture texture;
	texture.loadFromFile("../bin/Asie1");
	
	while (window.isOpen())
	{
		
	sf::Event event;
	while (window.pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
			window.close();
	}
	
	window.clear();
	window.draw(quad, &texture);
	window.display();
	
	}
	
	return 0;
}
	
	
