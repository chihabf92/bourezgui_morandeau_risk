#include "Moteur.hpp"
#include <iostream>
using namespace std;
bool Moteur::Resoudre_Action (Action a, Etat * e)
{

	if(a.type==2) /* Attaquer*/
	{
		int tampon=0;
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
		while(tampon==0)
		{
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
