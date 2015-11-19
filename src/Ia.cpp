#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>

#include "Joueur.hpp"
#include "Etat_jeu.hpp"
#include "Territoire.hpp"
#include "Moteur_jeu.hpp"
#include "Ia.hpp"

Territoire Ia::ChoisirUnPaysAppartenant(Joueur j, Territoire a, Territoire* pays)
{
	int hasard;
	do
	{
		hasard=rand()%8;	//Choix d'un pays au hasard parmis les 29
	}while(pays[hasard].couleur!=j.couleur);	//vérification que le pays appartient bien au joueur
	a=pays[hasard];
	return a;
}

/*void Ia::ChoisirDeuxVoisinsAppartenant(Joueur j, Territoire* b, Territoire* pays)
{
	Ia ia;
	int count;	
	int hasard;
	int tab[6];
	int indice;
	do
	{
		a=ia.ChoisirUnPaysAppartenant(j, a, pays[29])
		do
		{
			tab[6]=a->voisin[6];  //copie du tableau des voisins de a
			hasard=rand()%6;	//choix de l'indice qu'on va regarder
			indice=tab[indice]; //récupération de l'id d'un des pays voisins
			b=pays[indice];	//le pays b reçoit un des voisins random de a
			count=count+1;	//on incrémente un compteur afin de ne pas tourner indéfiniment si on n'a pas de voisins nous appartenant...
		}while(a->couleur!=b->couleur || count=5)	//on vérifie qu'ils appartiennent bien au même joueur ou qu'on ne tourne pas trop longtemps
		count=0;	//on remet la compteur à 0 au cas où il faut retourner dans la boucle
	}while(a->couleur!=b->couleur) //on vérifie qu'on est sorti car on avait un voisin et non pas à cause du count
}

void Ia::ChoisirDeuxVoisinsAdverses(Joueur j, Territoire* a, Territoire* b, Territoire* pays)
{
	Ia ia;
	int count;	
	int hasard;
	int tab[6];
	int indice;
	do
	{
		a=ia.ChoisirUnPaysAppartenant(j, a, pays[29])
		do
		{
			tab[6]=a->voisin[6];  //copie du tableau des voisins de a
			hasard=rand()%6;	//choix de l'indice qu'on va regarder
			indice=tab[indice]; //récupération de l'id d'un des pays voisins
			b=pays[indice];	//le pays b reçoit un des voisins random de a
			count=count+1;	//on incrémente un compteur afin de ne pas tourner indéfiniment si on n'a pas de voisins nous appartenant...
		}while(a->couleur=b->couleur || count=5)	//on vérifie qu'ils appartiennent bien au même joueur ou qu'on ne tourne pas trop longtemps
		count=0;	//on remet la compteur à 0 au cas où il faut retourner dans la boucle
	}while(a->couleur=b->couleur) //on vérifie 
}
*/
