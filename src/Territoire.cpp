#include "Territoire.hpp"

Territoire::Territoire()
{
	nom=0;
	couleur=0;
	nombre_pion=0;
	continent=0;	
}

Territoire::~Territoire()
{
}
void Territoire::set_nom(int a)
{
	nom=a;
}
int Territoire::get_nom()
{
	return nom;
}
void Territoire::set_couleur(int a)
{
	couleur=a;
}
int Territoire::get_couleur()
{
	return couleur;
}
void Territoire::set_nombre_pion(int a)
{
	nombre_pion=a;
}
int Territoire::get_nombre_pion()
{
	return nombre_pion;
}
void Territoire::set_continent(int a)
{
	continent=a;
}
int Territoire::get_continent()
{
	return continent;
}
