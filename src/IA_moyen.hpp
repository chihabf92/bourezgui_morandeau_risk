#ifndef _IA_MOYEN_
#define _IA_MOYEN_

#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>

#include "Joueur.hpp"
#include "Etat_jeu.hpp"
#include "Territoire.hpp"
#include "Moteur_jeu.hpp"


class IA_moyen
{
	public:
		
		IA_moyen();
		~IA_moyen();
		void attaquer(Territoire pays[29], Joueur& j);
};

#endif
