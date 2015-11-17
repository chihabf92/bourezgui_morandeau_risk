#ifndef TERRITOIRE_H
#define TERRITOIRE_H

#include <iostream>
#include <string> 

using namespace std;

class Territoire 
{
	public :
		int id; //il sert plus a rien 
		int couleur; // à définir quelle joueur est présent sur le territoire
		int nombre_pion; // savoir le nombre de defenseur qui sont sur osn territoire
		int continent; // a faire plus tad
		int position; // a referencer la position dans le rendu "level" afin de pouvoir faire des modifications sur celui ci.
		int voisin[6];
		int x;
		int y;
		string nom;
		Territoire();
		Territoire(int a, int b, int c, int d, int e, string f, int g, int h, int a1, int a2, int a3, int a4, int a5, int a6);
		~Territoire();
		void set_id(int a);
		int get_id();
		void set_couleur(int a);
		int get_couleur();
		void set_nombre_pion(int a);
		int get_nombre_pion();
		void set_continent(int a);
		int get_continent();
		int get_position();
};

#endif
