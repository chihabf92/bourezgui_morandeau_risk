#include "Etat.hpp"

Etat::Etat()
{
	
}
Etat::Etat (Plateau a, Etape b, int c, int d)
{
	p=a;
	e=b;
	nombre_joueur=c;
	joueur_en_cours=d;
}
