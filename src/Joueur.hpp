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
		void set_objectif(int a);
		int get_objectif();
		void set_couleur(int a);
		int get_couleur();
		void set_statut(int a);
		int get_statut();
		void set_nombre_piece(int a);
		int get_nombre_piece();
};
#endif
