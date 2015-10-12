#include "Pion.hpp"

Pion::Pion()
{
	couleur=0;
	type=0;
	nombre_pion=0;
	puissance=0;	
}
Pion::~Pion()
{
}
void Pion::set_couleur(int a)
{
	couleur=a;
}
int Pion::get_couleur()
{
	return couleur;
}
void Pion::set_type(int a)
{
	type=a;
}
int Pion::get_type()
{
	return type;
}
void Pion::set_nombre_pion(int a)
{
	nombre_pion=a;
}
int Pion::get_nombre_pion()
{
	return nombre_pion;
}
void Pion::set_puissance(int a)
{
	puissance=a;
}
int Pion::get_puissance()
{
	return puissance;
}
