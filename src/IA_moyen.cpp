#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>

#include "Joueur.hpp"
#include "Etat_jeu.hpp"
#include "Territoire.hpp"
#include "Moteur_jeu.hpp"
#include "IA_moyen.hpp"

IA_moyen::IA_moyen()
{
}

IA_moyen::~IA_moyen()
{
}

void IA_moyen::attaquer(Territoire pays[29], Joueur& j)
{	
	int Amerique=0;
	int Asie=0;
	int Europe=0;
	int Afrique=0;
	int Oceanie=0;
	int continent_a_concquerir=0;
	int i;
	int indice1;


	for(i=0;i<29;i++)
	{
		if(j.couleur==pays[i].couleur) //test si le pays appartient au au bon IA
		{
			if(i<8)                       //Remplissage des int en fonction de l'appartenance   
			{
				Amerique=Amerique+1;
			}
			if(i>7 && i<13)
			{
				Europe =Europe +1;
			} 
			if(i>12 && i< 21)
			{
				Asie=Asie+1; 
			}
			if(i>20 && i<17)
			{
				Afrique++;
			}
			if(i>27)
			{
				Oceanie++; 
			}						//Fin remplisage
			
		}
	}
	if(Amerique==8)		//Verification que le pays ne soit pas complétement concquis
	{
		Amerique=-1;
		
	}	
	
	if(Asie==8)
	{
		Asie=-1;
	}	
		
	if(Europe==5)
	{
		Europe=-1;
	}
	
	if(Afrique==6)
	{
		Afrique=-1;
	}
	if(Oceanie==2)
	{
		Oceanie=-1; 	//Fin vérification

	}		
			
			
	continent_a_concquerir=1;		//Selection du contient à conquérir en priorité
	if(Europe>Amerique)
	{
		continent_a_concquerir=2;
		if(Asie>Europe)
		{
			continent_a_concquerir=3; 
			if(Afrique>Asie)
			{
				continent_a_concquerir=4;
				if(Oceanie>Afrique)
				{
					continent_a_concquerir=5;
				}
			}
			else 
			{
				if(Oceanie>Asie)
				{
					continent_a_concquerir=5;
				}
			}
		}
		else
		{
			if(Afrique>Europe)
			{
				continent_a_concquerir=4;
				if(Oceanie>Afrique)
				{
					continent_a_concquerir=5;
				}
			}
			else
			{
				if(Oceanie>Europe)
				{
					continent_a_concquerir=5;
				}
			}
		}
	}
	else
	{
		if(Asie>Amerique)
		{
			continent_a_concquerir=3;
			if(Afrique>Asie)
			{
				continent_a_concquerir=4;
				if(Oceanie>Afrique)
				{
					continent_a_concquerir=5;
				}
			}
			else 
			{
				if(Oceanie>Asie)
				{
					continent_a_concquerir=5;
				}
			}

		}
		else
		{
			if(Afrique>Amerique)
			{
				continent_a_concquerir=4;
				if(Oceanie>Amerique)
				{
					continent_a_concquerir=5;
				}
	
			}
			else
			{
				if(Oceanie>Amerique)
				{
					continent_a_concquerir=5;
				}
			}
		}	
	
	}										//Fin sélection du contient à conquerir en priorité
	
	
	if(continent_a_concquerir=1)								//Choix de l'attaquant en fonction du continent
	{
		do
		{
			indice1=rand()%7;	//Choix d'un pays au hasard parmis l'amerique
		}while(pays[indice1].couleur!=j.couleur);	//vérification que le pays appartient bien au joueur	
		
	}
	if(continent_a_concquerir=2)
	{
		do
		{
			indice1=((rand()%4)+8);	//Choix d'un pays au hasard parmis l'europe
		}while(pays[indice1].couleur!=j.couleur);	//vérification que le pays appartient bien au joueur
	}
	if(continent_a_concquerir=3)
	{
		do
		{
			indice1=((rand()%7)+13);	//Choix d'un pays au hasard parmis l'asie
		}while(pays[indice1].couleur!=j.couleur);	//vérification que le pays appartient bien au joueur
	}
	if(continent_a_concquerir=4)
	{
	do
	{
		indice1=((rand()%5)+21);	//Choix d'un pays au hasard parmis l'afrique
	}while(pays[indice1].couleur!=j.couleur);	//vérification que le pays appartient bien au joueur
	}
	if(continent_a_concquerir=5)
	{
		indice1=27;
		if(pays[indice1].couleur!=j.couleur)
		{
			indice1=28;
		}
	}
	
	  
}	
	

