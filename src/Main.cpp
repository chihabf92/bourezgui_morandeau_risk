#include <cstdlib>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

int main ()
{
	//cout << "Hello world!" << endl;
	/*Creation d'une fenetre de rendu*/
	
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "RISK");
	while (true)
	{
		Image fond;
		Texture texture;
		if (!texture.loadFromFile("carte_risk.png"))
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
