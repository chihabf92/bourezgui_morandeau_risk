#include "Gestion_tour.hpp"

Gestion_tour::Gestion_tour
{
	tour_joueur=0;
}
Gestion_tour::~Gestion_tour()
{
}
void Gestion_tour::gestion_MacroTour()
{
	while(1) //On dit vérifier si aucun des joueurs a gagné
	{
	/*----------Choix du joueur qui va jouer (redondant)----------*/
		if(tour_joueur!=3)
		{
			tour_joueur=(tour_joueur+1);
			}
		else
		{
			tour_joueur=1;
		}
		cout<<"C'est au tour du joueur "<<tour_joueur<<" de jouer"<<endl;
		gestion_MicroTour();
		
	}
}

void Gestion_tour::gestion_Microtour()
{
	Moteur_jeu action;
	int a;
	sf::Vector2i localPosition;
	localPosition.x=0;
	localPosition.y=0;
	
	/*---------- Etape 1: Renforcement----------*/
	cout<<"Combien de personnne souhaiter vous faire déplacer?""<<endl;
	cin>> a;
	do 
	{
		localPosition = sf::Mouse::getPosition(window);
	}while(LocalPosition.x==0 && Local.Position.y==0);
	
	
	/*---------- Etape 1: Déplacement----------*/
	/*---------- Etape 1: Attaque----------*/
	
	
}

