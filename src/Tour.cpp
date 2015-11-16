#include <cstdlib>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <ctime>

#include "Joueur.hpp"
#include "Etat_jeu.hpp"
#include "Territoire.hpp"
#include "Frontiere.hpp"
#include "Moteur_jeu.hpp"
#include "Etat.hpp"

using namespace sf;
using namespace std;

int main()
{
	//Initialisation
	Joueur j;
	Moteur_jeu action;
	int pionEnPlus;
	int pionDeplacement;
	int pionAttaque;

	while(1) //tant que la partie n'est pas finie, à modifier...
	{
		//Changement de joueur (possibilité d'optimiser en réalisant un seul case avec la suite)
		switch (j)
		{
			case joueur_1:
				j=joueur_2;
			break;

			case joueur_2:
				j=joueur_3;
			break;
			
			case joueur_3:
				j=joueur_1;
			break;	
				
			// on ne traite pas les autres types d'évènements
			default:
			break;
			}
		
		//Calcul du nombre de pion
		
		// on regarde le type de joueur
		switch (j)
		{
			// Cas d'un tour joué par l'utlisateur
			case joueur_1:
				//Choix d'un pays lui appartenant qu'on mettra en a
				a=;
				//Ajout de x pions à ce pays
				action.AjouterXpions(&j, &a, pionSupplementaire);
				//choix de 2 pays voisins appartenant au joueur ainsi que du nombre de pion à déplacer
				a=;
				b=;
				pionDeplacement=;
				//Déplacement
				action.DeplacerXPionsDeAversB(&j, &a, &b, pionDeplacement);
				//choix d'un pays appartenant au joueur, d'un voisin à attaquer et d'un nombre de pion
				a=;
				b=;				
				pionAttaque=;
				//Attaque
				action.AttaquerBavecXpionsDeA(&j, &a, &b, pionAttaque);
			break;

			// Cas d'un tour joué par l'IA
			case joueur_2 :
			case joueur_3 :
				//Choix d'un pays lui appartenant qu'on mettra en a
				a=;
				//Ajout de pionSupplementaire pions à ce pays
				action.AjouterXpions(&j, &a, pionSupplementaire);
				//choix de 2 pays voisins appartenant au joueur ainsi que du nombre de pion à déplacer
				a=;
				b=;
				pionDeplacement=rand()%(a->nombre_pion-1) +1; //afin qu'il en reste au minimum 1 et qu'il ne puisse pas choisir plus de pion qu'il n'a le droit
				//Déplacement
				action.DeplacerXPionsDeAversB(&j, &a, &b, pionDeplacement);
				//choix d'un pays appartenant au joueur, d'un voisin à attaquer et d'un nombre de pion
				a=;
				b=;				
				pionAttaque=rand()%(a->nombre_pion-1) +1; //afin qu'il en reste au minimum 1 et qu'il ne puisse pas choisir plus de pion qu'il n'a le droit
				//Attaque
				action.AttaquerBavecXpionsDeA(&j, &a, &b, pionAttaque);
			break;
					
			// on ne traite pas les autres types d'évènements
			default:
			break;
		}
		
	return -1;
}
