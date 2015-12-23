#include "Pays.hpp"

Pays::Pays()
{
	
}
Pays::Pays (int  a, int  b, int c, std::vector<int> d)
{
	int i;
	nombre_armee=a;
	joueur=b;
	identifiant_pays=c;
	for(i=0; i<d.size();i++)
	{
		voisin[i]=d[i];
	}

}

void Pays::Set_voisin (int a, int b, int c, int d, int  e, int f)
{
	voisin.resize(6);
	a=voisin[0];
	b=voisin[1];
	c=voisin[2];
	d=voisin[3];
	e=voisin[4];
	f=voisin[5];
}