#ifndef PION_H
#define PION_H

#include <iostream>

class Pion 
{
	public:
		int couleur;
		int type;
		int nombre_pion;
		int puissance;
		Pion();
		~Pion();
		void set_couleur(int a);
		int get_couleur();
		void set_type(int a);
		int get_type();
		void set_nombre_pion(int a);
		int get_nombre_pion();
		void set_puissance(int a);
		int get_puissance();
};

#endif
