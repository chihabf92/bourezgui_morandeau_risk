#ifndef IA_H
#define IA_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>

#include "Joueur.hpp"
#include "Etat_jeu.hpp"
#include "Territoire.hpp"
#include "Moteur_jeu.hpp"

class Ia
{
	public :
	//Territoire ChoisirUnPaysAppartenant(Joueur j, Territoire a, Territoire* pays);
	void SeRenforcer(Joueur& j, Territoire *pays, int pion);
	void SeDeplacer(Joueur& j, Territoire* pays);
	void Attaquer(Joueur& j, Territoire* pays);
	//void ChoisirDeuxVoisinsAppartenant(Joueur j, Territoire* a, Territoire* b, Territoire* pays);
	//void ChoisirDeuxVoisinsAdverses(Joueur j, Territoire* a, Territoire* b, Territoire* pays);
	
};

#endif
