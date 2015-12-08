#include <cstdlib>
#include <iostream>
#include <cstring>
#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <ctime>

#include "Joueur.hpp"
#include "Etat_jeu.hpp"
#include "Territoire.hpp"
#include "Frontiere.hpp"
#include "Moteur_jeu.hpp"
#include "Ia.hpp"


using namespace sf;
using namespace std;


int main()
{

    // création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(1152, 1152), "risk");
    
    //créaton de l'arrière plan
    sf::Texture arriere_plan;
    if (!arriere_plan.loadFromFile("../res/carte_2.png"))
    {
        cout<<"erreur lors du chargement de l'image"<<endl;// erreur...
    }
    sf::Sprite sprite;
    sprite.setTexture(arriere_plan);

    //-----INITIALISATION JOUEUR-----

    Joueur joueur_1;
    Joueur joueur_2;
    Joueur joueur_3;

    joueur_1.set_couleur(1); //Rouge 
    joueur_2.set_couleur(2); //Jaune
    joueur_3.set_couleur(3); //Vert

    
    //Initialisation
	Moteur_jeu action;
    Territoire pays[29];
    string s[29];
    Text text[29];
    int i;
	Joueur* j=&joueur_2;
	int pionSupplementaire;
	int pionDeplacement;
	int pionAttaque;
	int hasard;
	Ia ia;
	Territoire a;
	Territoire b;
	pionSupplementaire=2;
	int z;

	
	
    //-----INITIALISATION TERRITOIRE----

    Territoire Amerique_Nord_1(0,joueur_2.get_couleur(),10,1,76,"Amerique_Nord_1",96,64,1,2,30,30,30,30); //Canada,
    pays[0]=Amerique_Nord_1;
    Territoire Amerique_Nord_2(1,joueur_1.get_couleur(),10,1,147,"Amerique_Nord_2",75,145,0,2,3,30,30,30); //USA gauche
    pays[1]=Amerique_Nord_2;
    Territoire Amerique_Nord_3(2,joueur_2.get_couleur(),10,1,150,"Amerique_Nord_3",170,145,0,1,3,30,30,30); //USA droite
    pays[2]=Amerique_Nord_3;
    Territoire Amerique_Nord_4(3,joueur_3.get_couleur(),10,1,219,"Amerique_Nord_4",112,224,1,2,4,30,30,30); //USA Bas
    pays[3]=Amerique_Nord_4;


    Territoire Amerique_Sud_1(4,joueur_1.get_couleur(),10,2,331,"Amerique_Sud_1",205,288,3,5,6,30,30,30);  //Haut
    pays[4]=Amerique_Sud_1;
    Territoire Amerique_Sud_2(5,joueur_2.get_couleur(),10,2,403,"Amerique_Sud_2",205,330,4,6,7,30,30,30);  //Gauche 
    pays[5]=Amerique_Sud_2;
    Territoire Amerique_Sud_3(6,joueur_3.get_couleur(),10,2,405,"Amerique_Sud_3",280,330,4,5,7,30,30,30);  //Droit
    pays[6]=Amerique_Sud_3;
    Territoire Amerique_Sud_4(7,joueur_1.get_couleur(),10,2,511,"Amerique_Sud_4",245,480,5,6,30,30,30,30);  //Bas
    pays[7]=Amerique_Sud_4;

    Territoire Europe_1(8,joueur_3.get_couleur(),10,3,158,"Europe_1",420,140,9,30,30,30,30,30); //France
    pays[8]=Europe_1;
    Territoire Europe_2(9,joueur_2.get_couleur(),10,3,124,"Europe_2",510,130,8,10,12,30,30,30); //Allemagne->Italie
    pays[9]=Europe_2;
    Territoire Europe_3(10,joueur_3.get_couleur(),10,3,89,"Europe_3",540,45,9,11,12,30,30,30); //Scandinavie
    pays[10]=Europe_3;
    Territoire Europe_4(11,joueur_1.get_couleur(),10,3,91,"Europe_4",585,60,13,11,12,30,30,30); //Debut Russie
    pays[11]=Europe_4;
    Territoire Europe_5(12,joueur_2.get_couleur(),10,3,162,"Europe_5",550,120,10,11,16,30,30,30); //Debut Moyen Orient
    pays[12]=Europe_5;

    Territoire Asie_1(13,joueur_2.get_couleur(),10,4,93,"Asie_1",650,75,11,14,16,17,18,30); //Russie Gauche 
    pays[13]=Asie_1;
    Territoire Asie_2(14,joueur_3.get_couleur(),10,4,95,"Asie_2",740,45,13,15,18,19,30,30); //Sibérie ur
    pays[14]=Asie_2;
    Territoire Asie_3(15,joueur_1.get_couleur(),10,4,98,"Asie_3",800,65,14,19,20,30,30,30); //Chine Nord Droit
    pays[15]=Asie_3;
    Territoire Asie_4(16,joueur_3.get_couleur(),10,4,235,"Asie_4",600,160,23,12,13,17,30,30); //Arabie Saoudite
    pays[16]=Asie_4;
    Territoire Asie_5(17,joueur_2.get_couleur(),10,4,200,"Asie_5",640,140,13,16,18,30,30,30); //Iran
    pays[17]=Asie_5;
    Territoire Asie_6(18,joueur_3.get_couleur(),10,4,202,"Asie_6",720,130,13,14,17,19,30,30); //Inde
    pays[18]=Asie_6;
    Territoire Asie_7(19,joueur_2.get_couleur(),10,4,204,"Asie_7",780,130,14,15,18,20,30,30); //Chine Sud Centre
    pays[19]=Asie_7;
    Territoire Asie_8(20,joueur_1.get_couleur(),10,4,206,"Asie_8",840,130,15,19,30,30,30,30); //Chine Sud Droit
    pays[20]=Asie_8;

    Territoire Afrique_1(21,joueur_3.get_couleur(),10,5,265,"Afrique_1",416,256,22,24,30,30,30,30); //Maroc
    pays[21]=Afrique_1;
    Territoire Afrique_2(22,joueur_1.get_couleur(),10,5,230,"Afrique_2",460,220,21,23,24,30,30,30); //Algerie
    pays[22]=Afrique_2;
    Territoire Afrique_3(23,joueur_2.get_couleur(),10,5,233,"Afrique_3",560,220,22,24,25,16,30,30); //Egypte->Syrie
    pays[23]=Afrique_3;
    Territoire Afrique_4(24,joueur_2.get_couleur(),10,5,303,"Afrique_4",515,300,21,22,23,25,26,30); //Afrique Centrale
    pays[24]=Afrique_4;
    Territoire Afrique_5(25,joueur_1.get_couleur(),10,5,342,"Afrique_5",570,260,23,24,26,30,30,30); //Afrique Centrale Gauche
    pays[25]=Afrique_5;
    Territoire Afrique_6(26,joueur_3.get_couleur(),10,5,449,"Afrique_6",570,370,24,26,30,30,30,30); //Afrique Sud
    pays[26]=Afrique_6;
    
    Territoire Oceanie_1(28,joueur_3.get_couleur(),10,6,459,"Oceanie_1",900,380,29,30,30,30,30,30); //Australie Gauche
    pays[27]=Oceanie_1;
    Territoire Oceanie_2(29,joueur_1.get_couleur(),10,6,461,"Oceanie_2",955,390,28,30,30,30,30,30); //Australie Droit
    pays[28]=Oceanie_2;


	//Initialisation zone afichage des teritoires
	
	
	tab[0][0]=106;//x1					x1,y1	*------------*  x2,y1
	tab[0][1]=198;//x2							|			 |	
	tab[0][2]=55;//y1							|			 |
	tab[0][3]=93;//y2					x1,y2	*------------*	x2,y2

	tab[1][0]=87; //Amerique Nord 2
	tab[1][1]=155;
	tab[1][2]=106;
	tab[1][3]=179;

	tab[2][0]=162;//Amerique Nord 
	tab[2][1]=226;
	tab[2][2]=106;
	tab[2][3]=179;	
	
	tab[3][0]=94; //Amerique Nord 4	
	tab[3][1]=145;
	tab[3][2]=191;
	tab[3][3]=246;

	tab[4][0]=199; //Amerique Sud 1
	tab[4][1]=266;
	tab[4][2]=271;
	tab[4][3]=316;

	tab[5][0]=207; //Amerique Sud 2	
	tab[5][1]=251;
	tab[5][2]=328;
	tab[5][3]=431;
	
	tab[6][0]=262; // Amerique Sud 3
	tab[6][1]=319;
	tab[6][2]=328;
	tab[6][3]=431;

	tab[7][0]=226; //Amerique Sud 4
	tab[7][1]=269;
	tab[7][2]=448;
	tab[7][3]=502;

	tab[8][0]=446; //Europe 1
	tab[8][1]=490; 
	tab[8][2]=121;  
	tab[8][3]=167;
		
	tab[9][0]=509; //Europe 2
	tab[9][1]=538;
	tab[9][2]=99;
	tab[9][3]=150;

	tab[10][0]=513; //Europe 3
	tab[10][1]=579;
	tab[10][2]=44;
	tab[10][3]=101;

	tab[11][0]=592; //Europe 4
	tab[11][1]=640;
	tab[11][2]=50;
	tab[11][3]=106;
	
	tab[12][0]=549; //Europe 5
	tab[12][1]=600;
	tab[12][2]=117;
	tab[12][3]=160;

	tab[13][0]=634; //Asie 1
	tab[13][1]=714;
	tab[13][2]=41;
	tab[13][3]=125;

	tab[14][0]=724; //Asie 2
	tab[14][1]=793;
	tab[14][2]=32;
	tab[14][3]=124;

	tab[15][0]=799; //ASie 3
	tab[15][1]=895;
	tab[15][2]=44;
	tab[15][3]=123;

	tab[16][0]=596; //Asie 4
	tab[16][1]=631; 
	tab[16][2]=166;
	tab[16][3]=233;

	tab[17][0]=635; //Asie 5
	tab[17][1]=681;
	tab[17][2]=133;
	tab[17][3]=200;	
	
	tab[18][0]=690; //Asie 6
	tab[18][1]=750;
	tab[18][2]=134;
	tab[18][3]=248;

	tab[19][0]=758; //Asie 7
	tab[19][1]=817;
	tab[19][2]=132;
	tab[19][3]=245;

	tab[20][0]=823; // Asie 8
	tab[20][1]=872;
	tab[20][2]=131;
	tab[20][3]=263;
	
	tab[21][0]=404; // Afrique 1
	tab[21][1]=433;
	tab[21][2]=199;
	tab[21][3]=284;

	tab[22][0]=441; //Afrique 2
	tab[22][1]=506;
	tab[22][2]=175;
	tab[22][3]=237;

	tab[23][0]=516; //Afrique 3
	tab[23][1]=594;
	tab[23][2]=182;
	tab[23][3]=238;
		
	tab[24][0]=447; //Afrique 4
	tab[24][1]=543;
	tab[24][2]=246;
	tab[24][3]=353;

	tab[25][0]=557; //Afrique 5
	tab[25][1]=625;
	tab[25][2]=252;
	tab[25][3]=362;

	tab[26][0]=513; //Afrique 6
	tab[26][1]=598;
	tab[26][2]=373;
	tab[26][3]=435;
	
	tab[27][0]=859; //Océanie 1 
	tab[27][1]=928;
	tab[27][2]=369;
	tab[27][3]=441;


   // 1->Rouge
   // 2->Jaune
   // 3-> Vert 

    //-----INITIALISATION FRONTIERE-----


	//Initialisation des zones d'affichage des pions
	
	sf::Font font;
	if(!font.loadFromFile("../res/arial.ttf"))
	{	return -1;
	}


    int level[] =
    { // 1 2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36                                                                                                          */      
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//1
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//2
        0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 1, 0, 2, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,//3
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//4
        0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//5
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 3, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,//6
        0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//7
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//8
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//9
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//10
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//11
        0, 0, 0, 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//12
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0,//13
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//14
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//15
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//16
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//17
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//18
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//19
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//20
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//21
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//22
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//23
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//24
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//25
    };

    //INITIALISATION ETAT DE JEU-----

    Etat_jeu map;


    // on fait tourner le programme tant que la fenêtre n'a pas été fermée
    while (window.isOpen())
    {

        // on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
        sf::Event event;
        
        while (window.pollEvent(event))
		{
		// on regarde le type de l'évènement...
			switch (event.type)
			{
			// fenêtre fermée
				case sf::Event::Closed:
					window.close();
					break;

			// touche pressée (commandes d'action)
				case sf::Event::KeyPressed:
					if(event.key.code == sf::Keyboard::Up)
					{

					}
					else if(event.key.code == sf::Keyboard::Down)
					{

					}
					else if(event.key.code == sf::Keyboard::Escape)
					{

					}
					else if(event.key.code == sf::Keyboard::Right)
					{

					}
					else if(event.key.code == sf::Keyboard::Left)
					{
						//Tour complet d'un IA
						ia.SeRenforcer(*j, pays, pionSupplementaire);
						ia.SeDeplacer(*j, pays);
						ia.Attaquer(*j, pays);
						if(j==&joueur_2)
							j=&joueur_3;
						else j=&joueur_2;
					}
					break;
			
			// on ne traite pas les autres types d'évènements
			default:
				break;
			}
		}
		
		//Création de la fenêtre du plan avec les pions
		if (!map.load("../res/Tileset.png", sf::Vector2u(32, 32), level, 36, 25))
        {
			return -1;
		}
       
        // effacement de la fenêtre en noir
        window.clear(sf::Color::Black);
		
        for(i=0;i<29;i++)
        {
            s[i]=std::to_string(pays[i].nombre_pion);
            text[i].setFont(font);
            text[i].setString(s[i]);
            text[i].setCharacterSize(18);
            text[i].setColor(sf::Color::Black);
            text[i].setPosition(pays[i].x,pays[i].y);

        }
		
		// c'est ici qu'on dessine tout
        window.draw(sprite);
        window.draw(map);		
        
        for(i=0;i<29;i++)
        {
            window.draw(text[i]);
        }


         window.display();

    }

    return 0;
}

