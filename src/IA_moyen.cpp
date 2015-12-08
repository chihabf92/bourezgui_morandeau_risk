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

void IA_moyen::attaquer(Joueur& j, Territoire* pays)
{	
	Moteur_jeu action;
	int Amerique=0;
	int Asie=0;
	int Europe=0;
	int Afrique=0;
	int Oceanie=0;
	int continent_a_concquerir=0;
	int i;
	int indice1;
	int indice2;
	int tab[6];
	int hasard;
	int count=0;
	int x;	


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
	
	//cout<<"CONTinent a conquerir"<<continent_a_concquerir<<endl;
	
	
	if(continent_a_concquerir==1)								//Choix du défenseur en fonction du continent
	{
		do
		{
			indice2=rand()%8;	//Choix d'un pays au hasard parmis l'amerique
			
		}while(pays[indice2].couleur==j.couleur);	//vérification que le pays appartient pas au joueur	
	
	}
	if(continent_a_concquerir==2)
	{
		do
		{
			indice2=((rand()%5)+8);	//Choix d'un pays au hasard parmis l'europe
		}while(pays[indice2].couleur==j.couleur);	//vérification que le pays appartient pas au joueur
	}
	if(continent_a_concquerir==3)
	{
		do
		{
			indice2=((rand()%8)+13);	//Choix d'un pays au hasard parmis l'asie
		}while(pays[indice2].couleur==j.couleur);	//vérification que le pays appartient pas au joueur
	}
	if(continent_a_concquerir==4)
	{
	do
	{
		indice2=((rand()%6)+21);	//Choix d'un pays au hasard parmis l'afrique
	}while(pays[indice2].couleur==j.couleur);	//vérification que le pays appartient pas au joueur
	}
	if(continent_a_concquerir==5)
	{
		indice2=27;
		if(pays[indice2].couleur==j.couleur)
		{
			indice2=28;
		}
	}
	//cout<<"pays a conquerir"<<indice2<<endl;
	
	do
	{
		//Choix d'un pays voisin  nous appartenant 
		//copie du tableau des voisins de a
		for(i=0;i<6;i++)
		{
			tab[i]=pays[indice2].voisin[i];  
		}
		do
		{	
			do
			{
				hasard=rand()%6;	//choix de l'indice qu'on va regarder
				indice1=tab[hasard]; //récupération de l'id d'un des pays voisins
			}while(tab[hasard]==30);
			
			count=count+1;	//on incrémente un compteur afin de ne pas tourner indéfiniment si on n'a pas de voisins nous appartenant...
		}while( pays[indice1].couleur==pays[indice2].couleur);	//on vérifie qu'ils appartiennent bien au même joueur ou qu'on ne tourne pas trop longtemps
		count=0;	//on remet la compteur à 0 au cas où il faut retourner dans la boucle
	}while(pays[indice1].couleur==pays[indice2].couleur); //on vérifie qu'on est sorti car on avait un voisin appartenant à l'IA et non pas à cause du count
	//cout<<"pays avec lequel on attaque"<<indice1<<endl;
	
	//Détermination du nombre de pions pour l'attaque
	x=rand()%(pays[indice1].nombre_pion-2)+1; //car il doit au moins rester un pion sur le territoire
	
	//Déplacement des pions
	action.AttaquerBavecXpionsDeA(j, &pays[indice1], &pays[indice2], x);
	
	
	
	  
}	
	
void IA_moyen::renforcer( Joueur& j,Territoire* pays, int pion)
{
	Moteur_jeu action;
	int i;
	int indice; //entier permerttant de sauvergarder l'indice du pays dans la première boucle for
	int valeur=1000000000;//entier permettant de comparer le nombre de valeurs, initialisation  grande	
	 /*Détermination du pays à renforcer*/
	 
	for(i=0;i<29; i++)
	{
		if (j.couleur==pays[i].couleur) //test si le pays appartient au au bon IA
		{
			if(pays[i].nombre_pion<valeur)//test si le territoire i a moins de pion que la valeur précedente.
			{
				indice=i;
				valeur=pays[i].nombre_pion;
			}	
		}
	} 
	action.AjouterXpions(j, &pays[indice], pion);	//ajout des pions à ce pays
	cout<<"Le joueur "<<j.couleur<<" a ajouté "<<pion<<" pions au territoire "<<pays[indice].nom<<endl;
	
	
}
