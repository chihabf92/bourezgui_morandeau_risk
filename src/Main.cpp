#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include "Joueur.hpp"
#include "Etat.hpp"

using namespace sf;
using namespace std;


int main()
{
    // création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "risk");
    
    //créaton de l'arrière plan
    sf::Texture arriere_plan;
    if (!arriere_plan.loadFromFile("../res/carte_risk.png"))
    {
        cout<<"erreur lors du chargement de l'image"<<endl;// erreur...
    }
    sf::Sprite sprite;
    sprite.setTexture(arriere_plan);

    /*-----INITIALISATION JOUEUR-----*/

    Joueur joueur_1;
    Joueur joueur_2;
    Joueur joueur_3;

    joueur_1.set_couleur(1);
    joueur_2.set_couleur(2);
    joueur_3.set_couleur(3);

    /*-----INITIALISATION ETAT DE JEU----*/

    Etat etat_de_jeu;
    etat_de_jeu.set_nombre_joueur(3);
    

    // on fait tourner le programme tant que la fenêtre n'a pas été fermée
    while (window.isOpen())
    {
        // on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
        sf::Event event;
        while (window.pollEvent(event))
        {
            // fermeture de la fenêtre lorsque l'utilisateur le souhaite
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // effacement de la fenêtre en noir
        window.clear(sf::Color::Black);

        // c'est ici qu'on dessine tout
        // On dessine l'arrière plan
        window.draw(sprite);

        // fin de la frame courante, affichage de tout ce qu'on a dessiné
        window.display();
    }

    return 0;
}