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