#ifndef ETAT_H
#define ETAT_H

class Etat
{
	public:
		int nombre_joueur;
		int temps_jeu;
		Etat();
		~Etat();
		void set_nombre_joueur(int a);
		int get_nombre_joueur();
		void set_temps_jeu(int a);
		int get_temps_jeu();
};
#endif
