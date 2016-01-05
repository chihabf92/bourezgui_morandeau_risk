#include "Moteur.hpp"
#include <iostream>
using namespace std;
bool Moteur::Resoudre_Action (Action a, Etat * e)
{

	if(a.type==2) /* Attaquer*/
	{
		int scoreA[3];
		int scoreB[3];
		int tampon=0;
		int tampon1=0;
		int tampon2,tampon3;
		int perteA=0;
		int perteB=0;
		int i;
		int c;
		int bloubloublou;

		while(tampon1==0)
		{
			/*Choix de l'attaquant*/
			while(tampon==0)
			{
				cout<<"choisir un pays avec lequelle attaquer"<<endl;
				cin>>a.parametre_1;
				if (e->joueur_en_cours!=e->p.p[a.parametre_1].joueur)
				{
					cout<<"Le pays n'appartient pas au bon joueur, recommencez"<<endl;
				}
				else
				{
					tampon=1;
				}
			}
			/*choix du défenseur*/
			while(tampon==1)
			{
				cout<<"choisir un pays a attaquer"<<endl;
				cin>>a.parametre_2;
				if (e->joueur_en_cours ==e->p.p[a.parametre_2].joueur)
				{
					cout<<"Le pays appartient au joueur, recommencez"<<endl;
				}
				else 
				{
					tampon=0;
				}
			}	
			/*Vérification si les pays sont voisin*/
			
			for(i=0;i<6;i++)
			{
				if(e->p.p[a.parametre_1].voisin[i]==e->p.p[a.parametre_3].identifiant_pays)
				{
					tampon1=1;
				}
			}
			if(tampon1==0)
			{
				cout<<"les pays ne sont pas voisin, recommencez"<<endl;
			}

		}
		while(tampon==0)
		{
			/*choix du nombre d'armée*/
			cout<<"choisir le nombre d'armée avec lequelle attaquer"<<endl;
			cin>>a.parametre_3;
			if(a.parametre_3>4 || a.parametre_3> e->p.p[a.parametre_1].nombre_armee+1)
			{
				cout<<"mauvaise entrée, recommencez"<<endl;
			}
			else
			{
				tampon=1;
			}

		}
		/*choix du nombre d'armée du défenseur*/
		if(e->p.p[a.parametre_2].nombre_armee<2)
		{
			c=e->p.p[a.parametre_2].nombre_armee;
		}
		else
		{
			c=2;
		}
		/*simulation des dées pour l'attaquant*/

		for(i=0; i<3; i++) 
		{
			if(i<a.parametre_3)
			{	
				scoreA[i]=rand()%(6) +1;  //simulation d'un dé
			}
			else 
			{
				scoreA[i]=0;
			}	
		} 
		/*simulation des dées pour le défenseur*/
		for(i=0; i<3; i++) 
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
		/*Algorithme de tri des dés d'un attaquant*/ 
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

		/*Algorithme de tri des dés du défenseur*/
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
		/*Dans le cas, pour la bataille, ou il y a moins d'attaquant que de défenseur*/
		if (a.parametre_3<c)
		{
			c=a.parametre_3;
		}
		for(i=0; i<c; i++)
		{
			if(scoreB[i]<scoreA[i])
				{
					perteB=perteB+1;
				}
			else
				{
					perteA=perteA+1;
				}
		}
		/*Affichage du résultat*/
		cout<<"Résultat du combat : le territoire "<<e->p.p[a.parametre_1].identifiant_pays<<" a perdu "<<perteA<<" pions et le territoire "<<e->p.p[a.parametre_3].identifiant_pays<<" en a perdu "<<perteB<<endl;
		if(e->p.p[a.parametre_2].nombre_armee<=perteB)
		{
			e->p.p[a.parametre_1].nombre_armee=e->p.p[a.parametre_1].nombre_armee-a.parametre_3;
			e->p.p[a.parametre_2].joueur=e->p.p[a.parametre_1].joueur;
			e->p.p[a.parametre_2].nombre_armee=a.parametre_3-perteA;
			cout<<"Le territoire "<<e->p.p[a.parametre_2].identifiant_pays<<" viens d'être conquis par le joueur "<<e->p.p[a.parametre_1].joueur<<" et y possède maintenat "<<e->p.p[a.parametre_2].nombre_armee<<" pions dessus."<<endl;
		}
		else
		{
			e->p.p[a.parametre_1].nombre_armee=e->p.p[a.parametre_1].nombre_armee-perteA;
			e->p.p[a.parametre_2].nombre_armee=e->p.p[a.parametre_2].nombre_armee-perteB;
		}	


	}
	

	if(a.type==1) /* Deplacer */
	{

		int tampon=0;
		while(tampon==0)
		{
			cout<<"choisir un pays de départ"<<endl;
			cin>>a.parametre_1;
			if (e->joueur_en_cours!=e->p.p[a.parametre_1].joueur)
			{
				cout<<"Le pays n'appartient pas au bon joueur, recommencez"<<endl;
			}
			else
			{
				tampon=1;
			}
		}

		while(tampon==1)
		{
			cout<<"choisir un pays d'arrivé"<<endl;
			cin>>a.parametre_2;
			if (e->joueur_en_cours!=e->p.p[a.parametre_2].joueur)
			{
				cout<<"Le pays n'appartient pas au bon joueur, recommencez"<<endl;
			}
			else
			{
				tampon=0;
			}

		}


		while(tampon==0)
		{
			cout<<"Veuillez selectionner un nombre d'armée à sélectionner"<<endl;
			cin>>a.parametre_3;
			if(e->p.p[a.parametre_1].nombre_armee<=a.parametre_3)
			{
				cout<<"vous avez pas assez d'armée sur le territoire initiale, recommencez"<<endl;
			}
			else
			{
				tampon=1;
			}
		}
		e->p.p[a.parametre_1].nombre_armee=e->p.p[a.parametre_1].nombre_armee-a.parametre_3;
		e->p.p[a.parametre_2].nombre_armee=e->p.p[a.parametre_2].nombre_armee+a.parametre_3;
		cout<<"le changement a bien été effectué"<<endl;
		return true;
	}	

	if(a.type==0) /* Renforcer */
	{

		int tampon=0;
		while(tampon==0)
		{
			/* But: choisir un pays a renforcer*/
			cout<<"choisir un pays a renforcer"<<endl;
			cin>>a.parametre_1;
			if (e->joueur_en_cours!=e->p.p[a.parametre_1].joueur)
			{
				cout<<"Le pays n'appartient pas au bon joueur, recommencez"<<endl;
			}
			else
			{
				tampon=1;
			}
		}
		e->p.p[0].nombre_armee+=2;
		cout<<"le renforcement a été effectuer"<<endl;
		return true;
	}

	
}
