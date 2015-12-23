#include "Rendu.hpp"

using namespace sf;
using namespace std;

Rendu::Rendu (): window(sf::VideoMode(1152, 1152), "risk")
{
}

void Rendu::Initialisation_Rendu()
{
     std::vector<Graphique_pays> territoire(29);
     pays=territoire;
     pays[0].Set_coordonnes(130,64,96,64);
     pays[1].Set_coordonnes(120,130,75,145);
     pays[2].Set_coordonnes(200,130,170,145);
     pays[3].Set_coordonnes(110,200,112,224);
     pays[4].Set_coordonnes(235,288,205,288);
     pays[5].Set_coordonnes(220,360,205,330);
     pays[6].Set_coordonnes(285,360,280,330);
     pays[7].Set_coordonnes(245,450,245,480);    
     pays[8].Set_coordonnes(465,130,430,140);    
     pays[9].Set_coordonnes(515,105,510,130);    
     pays[10].Set_coordonnes(550,70,540,45);    
     pays[11].Set_coordonnes(610,70,585,60);    
     pays[12].Set_coordonnes(580,125,550,120);    
     pays[13].Set_coordonnes(680,70,650,75);    
     pays[14].Set_coordonnes(745,75,740,45);    
     pays[15].Set_coordonnes(840,70,800,65);    
     pays[16].Set_coordonnes(610,195,600,160);    
     pays[17].Set_coordonnes(655,170,640,140);    
     pays[18].Set_coordonnes(720,175,720,130);    
     pays[19].Set_coordonnes(780,175,780,130);    
     pays[20].Set_coordonnes(840,175,840,130);    
     pays[21].Set_coordonnes(415,230,416,256);    
     pays[22].Set_coordonnes(455,195,460,220);    
     pays[23].Set_coordonnes(535,195,560,220);    
     pays[24].Set_coordonnes(500,260,515,300);    
     pays[25].Set_coordonnes(570,300,570,260);    
     pays[26].Set_coordonnes(550,395,570,370);    
     pays[27].Set_coordonnes(880,400,900,380);    
     pays[28].Set_coordonnes(940,400,955,390);    
     
}

void Rendu::Affiche_etat (Etat * e)
{ 
    int i;
    
    //Différentes initiations
    //Chargement de l'arrière plan sur le sprite qui lui est destiné
    sf::Texture arriere_plan;
    if (!arriere_plan.loadFromFile("../res/carte_2.png"))
    {
        cout<<"erreur lors du chargement de l'image"<<endl;// erreur...
    }
    fond.setTexture(arriere_plan);
    
    //Initialisation de la police d'écriture  
    sf::Font font;
    font.loadFromFile("../res/arial.ttf");
    if(!font.loadFromFile("../res/arial.ttf"))
    {   cout<<"Probleme police ecriture"<<endl;
    }
    
    //Initialisation des textes affichant le nombre de pion en fonction de l'état
    for(i=0;i<pays.size();i++)
    {
        string s=to_string(e->p.p[i].nombre_armee);
        pays[i].nombre_armee.setFont(font);
        pays[i].nombre_armee.setString(s);
        pays[i].nombre_armee.setCharacterSize(18);
        pays[i].nombre_armee.setColor(sf::Color::Black);
        pays[i].nombre_armee.setPosition(pays[i].x_text,pays[i].y_text);
    }
    
    
    //Initialisation des sprites affichant le pion en fonction de l'état
    sf::Texture texture0;
    texture0.loadFromFile("../res/rouge.png");
    sf::Texture texture1;
    texture1.loadFromFile("../res/jaune.png");
    sf::Texture texture2;
    texture2.loadFromFile("../res/vert.png");
    for(i=0;i<pays.size();i++)
    {
        switch(e->p.p[i].joueur)
        {
            case 0:         
                pays[i].pion.setTexture(texture0);
                break;
            case 1:
                pays[i].pion.setTexture(texture1);
                break;
            case 2:
                pays[i].pion.setTexture(texture2);
                break;
            default:
                break;          
        }
        pays[i].pion.setPosition(sf::Vector2f(pays[i].x_pion, pays[i].y_pion));
    }
    
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
            window.draw(pays[i].pion);
        }             
        /*for(i=0;i<etape.size();i++)
        {
            window.draw(etape[i]);
        }*/

         window.display();

    }   
}
