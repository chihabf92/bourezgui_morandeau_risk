#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>

using namespace std;

class Joueur
{
	public:
		int objectif;
		int couleur;
		int statut;
		int nombre_piece; 
		Joueur();
		~Joueur();
		
};
#endif
