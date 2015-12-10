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

	p[0].set_voisin(1,2,30,30,30,30); //Amerique Nord 1
	p[1].set_voisin(0,2,3,30,30,30); //USA gauche
	p[2].set_voisin(0,1,3,30,30,30); //USA droite
	p[3].set_voisin(1,2,4,30,30,30); //USA Bas
	p[4].set_voisin(3,5,6,30,30,30); //Haut
	p[5].set_voisin(4,6,7,30,30,30); //Gauche
	p[6].set_voisin(4,5,7,30,30,30); //Droit
	p[7].set_voisin(5,6,30,30,30,30); //Bas
	p[8].set_voisin(9,30,30,30,30,30); //France
	p[9].set_voisin(8,10,12,30,30,30); //Allemagne->Italie
	p[10].set_voisin(9,11,12,30,30,30); //Scandinavie
	p[11].set_voisin(13,11,12,30,30,30); //Debut Russie
	p[12].set_voisin(10,11,16,30,30,30); //Debut Moyen Orient
	p[13].set_voisin(11,14,16,17,18,30); //Russie Gauche
	p[14].set_voisin(13,15,18,19,30,30); //Sibérie ur
	p[15].set_voisin(14,19,20,30,30,30); //Chine Nord Droit
	p[16].set_voisin(23,12,13,17,30,30); //Arabie Saoudite
	p[17].set_voisin(13,16,18,30,30,30); //Iran
	p[18].set_voisin(13,14,17,19,30,30); //Inde
	p[19].set_voisin(14,15,18,20,30,30); //Chine Sud Centre
	p[20].set_voisin(15,19,30,30,30,30); //Chine Sud Droit
	p[21].set_voisin(22,24,30,30,30,30); //Maroc
	p[22].set_voisin(21,23,24,30,30,30); //Algerie
	p[23].set_voisin(22,24,25,16,30,30); //Egypte->Syrie
	p[24].set_voisin(21,22,23,25,26,30); //Afrique Centrale
	p[25].set_voisin(23,24,26,30,30,30); //Afrique Centrale Gauche
	p[26].set_voisin(25,30,30,30,30,30); //Afrique Sud
	p[27].set_voisin(28,30,30,30,30,30); //Oceanie 1
	p[28].set_voisin(27,30,30,30,30,30); //Oceanie 2
			

}