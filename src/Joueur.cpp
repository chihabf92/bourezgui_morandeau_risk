#include "Joueur.hpp"

Joueur::Joueur()
{
	objectif=0;
	couleur=0;
	statut=0;
	nombre_piece=0;
}
Joueur::~Joueur()
{
}
void Joueur::set_objectif(int a)
{
	objectif=a;
}
int Joueur::get_objectif()
{
	return objectif;
}
void Joueur::set_couleur(int a)
{
	couleur=a;
}
int Joueur::get_couleur()
{
	return couleur;
}
void Joueur::set_statut(int a)
{
	statut=a;
}
int Joueur::get_statut()
{
	return statut;
}
void Joueur::set_nombre_piece(int a)
{
	statut=a;
}
int Joueur::get_nombre_piece()
{
	return statut;
}



