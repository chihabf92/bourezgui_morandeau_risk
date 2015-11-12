#ifndef MOTEUR_JEU
#define MOTEUR_JEU
#include "Territoire.hpp"
#include "Frontiere.hpp"
#include "Joueur.hpp"

class Moteur_jeu
{
public:
	Moteur_jeu();
	~Moteur_jeu();
	void DeplacerXPionsDeAversB(Joueur j, Territoire a, Territoire b, int x);
	void AttaquerBavecXpionsDeA(Joueur j, Territoire a, Territoire b, int x);
};

#endif