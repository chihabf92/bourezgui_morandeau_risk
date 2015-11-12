#include "Moteur_jeu.hpp"

Moteur_jeu::Moteur_jeu()
{

}

Moteur_jeu::~Moteur_jeu()
{

}

void Moteur_jeu::DeplacerXPionsDeAversB(Joueur j, Territoire a, Territoire b, int x)
{
	/*---------------veriier que le délacement est possible---------------*/

	if(j.couleur != a.couleur)
	{
		cout<<"Impossible: le territoire n'apaprtient pas au joueur"<<endl;
		return;
	}
	else if(j.couleur != b.couleur)
	{
		cout<<"Impossible: le territoire n'apaprtient pas au joueur"<<endl;
		return;

	}
	else if (x>0) 
	{
		cout<<"Impossible : les territoires ne sont pas voisins"<<endl;
		return; 
	}
	else if (x>a.nombre_pion)
	{
		cout<<"Impossible : pas assez de pion sur le territoire"<<endl;
		return;
	}
	/*--------------------action de déplacement---------------------*/
	else
	{
		a.nombre_pion=a.nombre_pion-x;
		b.nombre_pion=b.nombre_pion+x;
		cout<<"le déplacement a été éffectué"<<endl;
	}


}

void Moteur_jeu::AttaquerBavecXpionsDeA(Joueur j, Territoire a, Territoire b, int x)
{
	/*---------------veriier que l'attaque  est possible---------------*/
	if(a.couleur==b.couleur)
	{
		cout<<"Impossible: territoire deja concquis"<<endl;
		return;
	}
	else if (x<1 || x>3)
	{
		cout<<"Attaque impossible : le nombre d'armée attaquant n'est pas valide, il doit être compris entre 1 et 3"<<endl;
		return;
	}
	else if (x>a.nombre_pion-1)  //il doit toujours rester au moins 1 pion sur le territoire attaquant
	{		
		cout<<"Attaque impossible : il n'y a pas assez de pions disponible pour attaquer"<<endl;
		return;
	}	
	else if (j.couleur!=a.couleur)
	{
		cout<<"Attaque impossible : le territoire de départ n'appartient pas au joueur"<<endl;
		return;
	}
	else if (x>0)//frontiere ( a concevoir)
	{
		cout<<"Attaque impossible : les 2 territoires ne sont pas voisins"<<endl;
		return;
	}
	else if (x>a.nombre_pion)
	{
		cout<<"Déplacement impossible : vous n'avez pas assez de pions disponible à déplacer"<<endl;
		return;
	}
		/*---------------Action attaque---------------*/
		int scoreA[3];
		int scoreB[3];
		int i;
		int c;

}

