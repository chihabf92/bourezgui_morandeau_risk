#include <cstdlib>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Joueur.hpp"
#include "Pion.hpp"
#include "Territoire.hpp"
#include "Etat.hpp"
#include "Frontiere.hpp"
using namespace std;
using namespace sf;

int main ()

{
	/*Création de trois joueurs*/
	
	//joueur_1 = new Joueur;

	
	/*Creation d'une fenetre de rendu*/
		
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "RISK");
	while (true)
	{
		Image fond;
		Texture texture;
		if (!texture.loadFromFile("../res/carte_risk.png"))
		{
			cout << "\n erreur chargement image\n " << endl;
		}
		Sprite sprite;
		sprite.setTexture(texture);
		window.clear();
		window.draw(sprite);
		window.display();
	}	
	
	return 0;
}
