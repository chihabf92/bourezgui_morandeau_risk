#include "Moteur_jeu.hpp"

Moteur_jeu::Moteur_jeu()
{

}

Moteur_jeu::~Moteur_jeu()
{

}

void Moteur_jeu::DeplacerXPionsDeAversB(Joueur* j, Territoire* a, Territoire* b, int x)
{
	/*---------------veriier que le délacement est possible---------------*/

	if(j->couleur != a->couleur)
	{
		cout<<"Impossible: le territoire n'apaprtient pas au joueur"<<endl;
		return;
	}
	else if(j->couleur != b->couleur)
	{
		cout<<"Impossible: le territoire n'apaprtient pas au joueur"<<endl;
		return;

	}
	else if (x>0) 
	{
		cout<<"Impossible : les territoires ne sont pas voisins"<<endl;
		return; 
	}
	else if (x> a->nombre_pion)
	{
		cout<<"Impossible : pas assez de pion sur le territoire"<<endl;
		return;
	}
	/*--------------------action de déplacement---------------------*/
	else
	{
		a->nombre_pion=a->nombre_pion-x;
		b->nombre_pion=b->nombre_pion+x;
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
		int d;
		int tampon1, tampon2, tampon3;
		int perteA=0;
		int perteB=0;
		if (b.nombre_pion<2)
			{
				c=b.nombre_pion;
			}
		else
			{
				c=2;
			}
			for(i=0; i<3; i++) //simulation des lancés de dés pour l'attaquant
			{
				if(i<x)
				{	
					scoreA[i]=rand()%(6) +1;  //simulation d'un dé
				}
				else 
				{
					scoreA[i]=0;
				}
			} 

			for(i=0; i<3; i++) //simulation des lancés de dés pour l'attaquant
			{
				if(i<c)
				{	
					scoreB[i]=rand()%(6) +1;  //simulation d'un dé
				}
				else 
				{
					scoreB[i]=0;
				}
			} 
	/*Tri des dés attaquant*/		
		tampon1=scoreA[0];
		tampon2=scoreA[1];
		tampon3=scoreA[2];

		if (tampon1>=tampon2 && tampon1>=tampon3)
		{
			scoreA[0]=tampon1;
			if(tampon2>=tampon3)
			{
				scoreA[1]=tampon2;
				scoreA[2]=tampon3;
			}
			else 
			{
				scoreA[1]=tampon3;
				scoreA[2]=tampon2;
			}
		}
		else if(tampon2>=tampon1 && tampon2>=tampon3)
		{
			scoreA[0]=tampon2;
			if(tampon1>=tampon3)
			{
				scoreA[1]=tampon1;
				scoreA[2]=tampon3;
			}
			else
			{
				scoreA[1]=tampon3;
				scoreA[2]=tampon1;
			}
		}
		else 
		{
			scoreA[0]=tampon3;
			if(tampon1>=tampon2)
			{
				scoreA[1]=tampon1;
				scoreA[2]=tampon2;
			}
			else
			{
				scoreA[1]=tampon2;
				scoreA[2]=tampon1;				
			}
		}
/*Tri des dés défenseur*/		
		tampon1=scoreB[0];
		tampon2=scoreB[1];
		tampon3=scoreB[2];

		if (tampon1>=tampon2 && tampon1>=tampon3)
		{
			scoreB[0]=tampon1;
			if(tampon2>=tampon3)
			{
				scoreB[1]=tampon2;
				scoreB[2]=tampon3;
			}
			else 
			{
				scoreB[1]=tampon3;
				scoreB[2]=tampon2;
			}
		}
		else if(tampon2>=tampon1 && tampon2>=tampon3)
		{
			scoreB[0]=tampon2;
			if(tampon1>=tampon3)
			{
				scoreB[1]=tampon1;
				scoreB[2]=tampon3;
			}
			else
			{
				scoreB[1]=tampon3;
				scoreB[2]=tampon1;
			}
		}
		else 
		{
			scoreB[0]=tampon3;
			if(tampon1>=tampon2)
			{
				scoreB[1]=tampon1;
				scoreB[2]=tampon2;
			}
			else
			{
				scoreB[1]=tampon2;
				scoreB[2]=tampon1;				
			}
		}
//Détermination du nombre de dés à prendre en compte
			if (x<c)
			{
				d=x;
			}
			else
			{
				d=c;
			}
			for(i=0; i<d; i++)
			{
				if(scoreA[x-i]<scoreB[c-i])
					{
						perteA=perteA+1;
					}
				else
					{
						perteB=perteB+1;
					}
			}
			if(b.nombre_pion<perteB)
			{
			a.nombre_pion=a.nombre_pion-x;
			b.couleur=j.couleur;
			b.nombre_pion=x-perteA;
			cout<<"Vous venez d'obtenir ce territoire"<<endl;
			}
			else
			{
			a.nombre_pion=a.nombre_pion-perteA;
			b.nombre_pion=a.nombre_pion-perteB;
			cout<<"Fin du combat"<<endl;
			}

}

