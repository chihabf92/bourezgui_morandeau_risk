#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>

#include "Joueur.hpp"
#include "Etat_jeu.hpp"
#include "Territoire.hpp"
#include "Moteur_jeu.hpp"
#include "Ia.hpp"


void Ia::SeRenforcer(Joueur& j, Territoire *pays, int pion)
{
	Moteur_jeu action;
	int hasard;
	do
	{
		hasard=rand()%8;	//Choix d'un pays au hasard parmis les 8 pays d'Amerique
	}while(pays[hasard].couleur!=j.couleur);	//vérification que le pays appartient bien au joueur
	action.AjouterXpions(j, &pays[hasard], pion);	//ajout des pions à ce pays
	cout<<"Le joueur "<<j.couleur<<" a ajouté "<<pion<<" pions au territoire "<<pays[hasard].nom<<endl;
}

void Ia::SeDeplacer(Joueur& j, Territoire* pays)
{
	int indice1;
	int indice2;
	int hasard;
	int x;
	int i;
	int count=0;
	Moteur_jeu action;
	int tab[6];
	
	//Choix des 2 pays pour le transfert de pions
	do
	{	
		//Choix d'un pays nous appartenant	
		do
		{
			indice1=rand()%29;	//Choix d'un pays au hasard parmis les 8 pays d'Amerique
		}while(pays[indice1].couleur!=j.couleur);	//vérification que le pays appartient bien au joueur
		
		//Choix d'un pays voisin nous appartenant
		//copie du tableau des voisins de a
		for(i=0;i<6;i++)
		{
			tab[i]=pays[indice1].voisin[i];  
		}
		do
		{	
			do
			{
				hasard=rand()%6;	//choix de l'indice qu'on va regarder
				indice2=tab[hasard]; //récupération de l'id d'un des pays voisins
			}while(tab[hasard]==30);
			count=count+1;	//on incrémente un compteur afin de ne pas tourner indéfiniment si on n'a pas de voisins nous appartenant...
		}while( (pays[indice1].couleur!=pays[indice2].couleur) && count<5 );	//on vérifie qu'ils appartiennent bien au même joueur ou qu'on ne tourne pas trop longtemps
		count=0;	//on remet la compteur à 0 au cas où il faut retourner dans la boucle
	
	}while(pays[indice1].couleur!=pays[indice2].couleur); //on vérifie qu'on est sorti car on avait un voisin et non pas à cause du count
	
	//Détermination du nombre de pions à déplacer
	x=rand()%(pays[indice1].nombre_pion-1); //car il doit au moins rester un pion sur le territoire
	cout<<"Le joueur "<<j.couleur<<" a déplacé "<<x<<" pions du territoire "<<pays[indice1].nom<<" vers le territoire "<<pays[indice2].nom<<endl;
	
	//Déplacement des pions
	action.DeplacerXPionsDeAversB(j, &pays[indice1], &pays[indice2], x);
}

void Ia::Attaquer(Joueur& j, Territoire* pays)
{
	int indice1;
	int indice2;
	int x;
	int hasard;
	int count=0;
	Moteur_jeu action;
	int tab[6];
	int i;
	
	//Choix des 2 pays pour l'attaque de pions
	do
	{	
		//Choix d'un pays nous appartenant	
		do
		{
			indice1=rand()%29;	//Choix d'un pays au hasard parmis les 8 pays d'Amerique
		}while(pays[indice1].couleur!=j.couleur);	//vérification que le pays appartient bien au joueur
		
		//Choix d'un pays voisin nous appartenant
		//copie du tableau des voisins de a
		for(i=0;i<6;i++)
		{
			tab[i]=pays[indice1].voisin[i];  
		}
		do
		{	
			do
			{
				hasard=rand()%6;	//choix de l'indice qu'on va regarder
				indice2=tab[hasard]; //récupération de l'id d'un des pays voisins
			}while(tab[hasard]==30);
			count=count+1;	//on incrémente un compteur afin de ne pas tourner indéfiniment si on n'a pas de voisins nous appartenant...
		}while( (pays[indice1].couleur==pays[indice2].couleur) && count<5 );	//on vérifie qu'ils appartiennent bien au même joueur ou qu'on ne tourne pas trop longtemps
		count=0;	//on remet la compteur à 0 au cas où il faut retourner dans la boucle
	}while(pays[indice1].couleur==pays[indice2].couleur); //on vérifie qu'on est sorti car on avait un voisin adverse et non pas à cause du count
	
	//Détermination du nombre de pions pour l'attaque
	x=rand()%(pays[indice1].nombre_pion-2)+1; //car il doit au moins rester un pion sur le territoire
	
	//Déplacement des pions
	action.AttaquerBavecXpionsDeA(j, &pays[indice1], &pays[indice2], x);
}
