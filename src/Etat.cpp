#include "Etat.hpp"

Etat::Etat()
{
	nombre_joueur=0;
	temps_jeu=0;
}
Etat::~Etat()
{
}
void Etat::set_nombre_joueur(int a)
{
	nombre_joueur=a;
}
int Etat::get_nombre_joueur()
{
	return nombre_joueur;
}
void Etat::set_temps_jeu(int a)
{
	temps_jeu=a;
}
int Etat::get_temps_jeu()
{
	return temps_jeu;
}

