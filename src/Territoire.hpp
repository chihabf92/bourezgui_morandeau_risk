#ifndef TERRITOIRE_H
#define TERRITOIRE_H

#include <iostream>

class Territoire 
{
	public :
		int nom;
		int couleur;
		int nombre_pion;
		int continent;
		Territoire();
		~Territoire();
		void set_nom(int a);
		int get_nom();
		void set_couleur(int a);
		int get_couleur();
		void set_nombre_pion(int a);
		int get_nombre_pion();
		void set_continent(int a);
		int get_continent();
};

#endif
