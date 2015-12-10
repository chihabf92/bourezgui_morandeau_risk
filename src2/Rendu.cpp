#include "Rendu.hpp"

using namespace sf;
using namespace std;



void Rendu::affiche_etat (Etat * e)
{
	int i;
	
	// changement de la taille de la fenêtre
	window.setSize(sf::Vector2u(1000, 1000));

	// changement du titre de la fenêtre
	window.setTitle("Risk");
	
	//Chargement de l'arrière plan sur le sprite qui lui est destiné
	sf::Texture arriere_plan;
    if (!arriere_plan.loadFromFile("../res/carte_2.png"))
    {
        cout<<"erreur lors du chargement de l'image"<<endl;// erreur...
    }
    fond.setTexture(arriere_plan);
    
    /* 
    //On met à jour par rapport à l'état
	for(i=0;i<pays.size();i++)
	{
		pays[i].nombre_armee=e.p.p[i];
		pays[i].pion=;
	} 
	*/    
    
    // on fait tourner le programme tant que la fenêtre n'a pas été fermée
    while (window.isOpen())
    {
        // on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
        sf::Event event;
        
	    while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
		
       
        // effacement de la fenêtre en noir
        window.clear(sf::Color::Black);
		
		// c'est ici qu'on dessine tout
        window.draw(fond);       
        for(i=0;i<pays.size();i++)
        {
			window.draw(pays[i].nombre_armee);
        }		      
        /*for(i=0;i<etape.size();i++)
        {
            window.draw(etape[i]);
        }*/

         window.display();

    }	

}
void Rendu::InitialisationRendu()
{
	int i;
	std::vector<Graphique_pays> tampon(29);
	pays=tampon;
	  
	sf::Font font;
	font.loadFromFile("../res/arial.ttf");
	/*if(!font.loadFromFile("../res/arial.ttf"))
	{	return -1;
	}*/
		
	//Initialisation des textes affichant le nombre de pion
	for(i=0;i<29;i++)
	{
		string s="0";
        pays[i].nombre_armee.setFont(font);
        pays[i].nombre_armee.setString(s);
        pays[i].nombre_armee.setCharacterSize(18);
        pays[i].nombre_armee.setColor(sf::Color::Black);
        pays[i].nombre_armee.setPosition(pays[i].x,pays[i].y);
	}
}
