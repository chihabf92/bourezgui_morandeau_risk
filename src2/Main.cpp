#include <cstdlib>
#include <iostream>
#include <cstring>
#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <ctime>

#include "Action.h"
//#include "Attaquer.h"
#include "Controleur_graphique.hpp"
//#include "Deplacer.h"
#include "Etat.h"
#include "Etape.h"
#include "Graphique_etape.hpp"
#include "Graphique_pays.hpp"
#include "Moteur.hpp"
#include "Pays.hpp"
#include "Plateau.hpp"
#include "Rendu.hpp"
//#include "Renforcer.h"

using namespace sf;
using namespace std;

int main (void)
{
	Plateau p;
	Etape et;
	et.etape=2;
	et.sous_etape=8;
	p.Initialisation();
	Etat e( p, et, 3, 1);
	Rendu r;
	/*cout<<p.p[0].nombre_armee<<", "<<p.p[2].joueur<<", "<<p.p[3].joueur<<", "<<p.p[24].identifiant_pays<<", "<<endl;
	cout<<e.p.p[0].nombre_armee<<", "<<e.p.p[2].joueur<<", "<<e.p.p[3].joueur<<", "<<e.p.p[24].identifiant_pays<<", "<<endl;
	cout<<e.nombre_joueur<<", "<<e.joueur_en_cours<<", "<<e.e.etape<<", "<<e.e.sous_etape<<endl;*/
	r.Initialisation_Rendu();
	//r.Affiche_etat (&e);
	
	/*Essai*/
	Action SeRenforcer(0);
	Action Deplacer(1);
	Action Attaquer(2);
	Moteur m;

	m.Resoudre_Action(Deplacer,&e);
	r.Affiche_etat (&e);
	
	return 0;
}
