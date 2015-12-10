#include <cstdlib>
#include <iostream>
#include <cstring>
#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <ctime>

#include "Action.h"
#include "Attaquer.h"
#include "Controleur_graphique.hpp"
#include "Deplacer.h"
#include "Etat.h"
#include "Etape.h"
#include "Graphique_etape.hpp"
#include "Graphique_pays.hpp"
#include "Moteur.hpp"
#include "Pays.hpp"
#include "Plateau.hpp"
#include "Rendu.hpp"
#include "Renforcer.h"
using namespace sf;
using namespace std;
int main (void)
{
	// création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(1152, 1152), "risk");

	/*----------Initialisation----------*/

	Plateau p; //créaton  du plateau;
	Etape et; //initialisation de l'etape du jeu
	p.Initialisation ();
	et.etape=2;
	et.sous_etape=8;
	Etat e (p,et,3,0);
	






	return 0;
}