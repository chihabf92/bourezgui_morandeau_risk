#ifndef TERRITOIRE_H
#define TERRITOIRE_H

#include <iostream>

class Territoire 
{
	public :
		int nom; //il sert plus a rien 
		int couleur; // à définir quelle joueur est présent sur le territoire
		int nombre_pion; // savoir le nombre de defenseur qui sont sur osn territoire
		int continent; // a faire plus tad
		int position; // a referencer la position dans le rendu "level" afin de pouvoir faire des modifications sur celui ci.
		Territoire();
		Territoire(int a, int b, int c, int d, int e);
		~Territoire();
		void set_nom(int a);
		int get_nom();
		void set_couleur(int a);
		int get_couleur();
		void set_nombre_pion(int a);
		int get_nombre_pion();
		void set_continent(int a);
		int get_continent();
		int get_position();
};

#endif
