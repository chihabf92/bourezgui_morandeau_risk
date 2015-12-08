#ifndef _GESTION_TOUR_H
#define _GESTION_TOUR_H

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <ctime>

#include "Joueur.hpp"
#include "Etat_jeu.hpp"
#include "Territoire.hpp"
#include "Frontiere.hpp"
#include "Moteur_jeu.hpp"
#include "Ia.hpp"
#include "IA_moyen.hpp"


class Gestion_tour
{
	public:
	
	
		Gestion_tour();
		~Gestion_tour();
		int tour joueur; //variable qui définit quelle personne joue
		void gestion_MacroTour(); //gestion d'un macro tour 
		void gestion_MicroTour(); //gestion d'un micro tour
	
};



#endif
