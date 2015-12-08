#ifndef MOTEUR_JEU
#define MOTEUR_JEU
#include <iostream>
#include "Territoire.hpp"
#include "Joueur.hpp"
#include "Frontiere.hpp"
#include <cstdio>
#include <cstdlib>
#include <ctime>

class Moteur_jeu
{
	public:
		Moteur_jeu();
		~Moteur_jeu();
		int VerificationSouris(int x, int y, int** test);
		void AjouterXpions(Joueur j, Territoire* a, int x);
		void DeplacerXPionsDeAversB(Joueur j, Territoire* a, Territoire* b, int x);
		void AttaquerBavecXpionsDeA(Joueur j, Territoire* a, Territoire* b, int x);
	
};

#endif

