#include "Graphique_pays.hpp"

Graphique_pays::Graphique_pays ()
{
	
}
Graphique_pays::Graphique_pays (int a, int b, int c, int d)
{
	x_pion=a;
	y_pion=b;
	x_text=c;
	y_text=d;
}
void Graphique_pays::Set_coordonnes (int a, int b, int c, int d)
{
	x_pion=a;
	y_pion=b;
	x_text=c;
	y_text=d;
}