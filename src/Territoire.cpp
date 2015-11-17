#include "Territoire.hpp"

Territoire::Territoire()
{
	id=0;
	couleur=0;
	nombre_pion=0;	
	continent=0;
	nom=' ';

}
Territoire::Territoire(int a, int b, int c, int d, int e, string f, int g, int h, int a1, int a2, int a3, int a4, int a5, int a6)
{
	id=a;
	couleur=b;
	nombre_pion=c;
	continent=d;
	position=e;
	nom=f;
	x=g;
	y=h;
	voisin[0]=a1;
	voisin[1]=a2;
	voisin[2]=a3;
	voisin[3]=a4;
	voisin[4]=a5;
	voisin[5]=a6;	

}

Territoire::~Territoire()
{
}
void Territoire::set_id(int a)
{
	id=a;
}
int Territoire::get_id()
{
	return id;
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
int Territoire::get_position()
{
	return position;
}