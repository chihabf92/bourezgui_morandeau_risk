#include "Plateau.hpp"

Plateau::Plateau ()
{
	
}
void Plateau::Initialisation ()
{
	int i;
	//std::vector<Pays> p;
	std::vector<Pays> pays(29);
	p=pays;
	for(i=0; i<29; i++)
	{
		this->p[i].nombre_armee=10;
		this->p[i].joueur=i%3;
		this->p[i].identifiant_pays=i;
	}

	/*---------- Instanciation des pays voisins ----------*/

	p[0].Set_voisin(1,2,30,30,30,30); //Amerique Nord 1
	p[1].Set_voisin(0,2,3,30,30,30); //USA gauche
	p[2].Set_voisin(0,1,3,30,30,30); //USA droite
	p[3].Set_voisin(1,2,4,30,30,30); //USA Bas
	p[4].Set_voisin(3,5,6,30,30,30); //Haut
	p[5].Set_voisin(4,6,7,30,30,30); //Gauche
	p[6].Set_voisin(4,5,7,30,30,30); //Droit
	p[7].Set_voisin(5,6,30,30,30,30); //Bas
	p[8].Set_voisin(9,30,30,30,30,30); //France
	p[9].Set_voisin(8,10,12,30,30,30); //Allemagne->Italie
	p[10].Set_voisin(9,11,12,30,30,30); //Scandinavie
	p[11].Set_voisin(13,11,12,30,30,30); //Debut Russie
	p[12].Set_voisin(10,11,16,30,30,30); //Debut Moyen Orient
	p[13].Set_voisin(11,14,16,17,18,30); //Russie Gauche
	p[14].Set_voisin(13,15,18,19,30,30); //Sibérie ur
	p[15].Set_voisin(14,19,20,30,30,30); //Chine Nord Droit
	p[16].Set_voisin(23,12,13,17,30,30); //Arabie Saoudite
	p[17].Set_voisin(13,16,18,30,30,30); //Iran
	p[18].Set_voisin(13,14,17,19,30,30); //Inde
	p[19].Set_voisin(14,15,18,20,30,30); //Chine Sud Centre
	p[20].Set_voisin(15,19,30,30,30,30); //Chine Sud Droit
	p[21].Set_voisin(22,24,30,30,30,30); //Maroc
	p[22].Set_voisin(21,23,24,30,30,30); //Algerie
	p[23].Set_voisin(22,24,25,16,30,30); //Egypte->Syrie
	p[24].Set_voisin(21,22,23,25,26,30); //Afrique Centrale
	p[25].Set_voisin(23,24,26,30,30,30); //Afrique Centrale Gauche
	p[26].Set_voisin(25,30,30,30,30,30); //Afrique Sud
	p[27].Set_voisin(28,30,30,30,30,30); //Oceanie 1
	p[28].Set_voisin(27,30,30,30,30,30); //Oceanie 2
	
}