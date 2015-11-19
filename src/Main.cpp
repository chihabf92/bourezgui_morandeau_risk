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


using namespace sf;
using namespace std;

//int main()
//{
	//Etat etat;
	//etat.Initialisation();
	//etat.Affichage();
	
	//return -1;
//}


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

    
    sf::Text text1;
    sf::Text text2;
	sf::Text text3;
	sf::Text text4;
	Moteur_jeu action;
    Territoire* pays[29];
    string s[29];
    Text text[29];
    int i;
	
	
    //-----INITIALISATION TERRITOIRE----

    Territoire Amerique_Nord_1(0,joueur_2.get_couleur(),10,1,76,"Amerique_Nord_1",96,64,1,2,30,30,30,30); //Canada,
    pays[0]=&Amerique_Nord_1;
    Territoire Amerique_Nord_2(1,joueur_1.get_couleur(),2,1,147,"Amerique_Nord_2",75,145,0,2,3,30,30,30); //USA gauche
    pays[1]=&Amerique_Nord_2;
    Territoire Amerique_Nord_3(2,joueur_2.get_couleur(),5,1,150,"Amerique_Nord_3",170,145,0,1,3,30,30,30); //USA droite
    pays[2]=&Amerique_Nord_3;
    Territoire Amerique_Nord_4(3,joueur_3.get_couleur(),5,1,219,"Amerique_Nord_4",112,224,1,2,4,30,30,30); //USA Bas
    pays[3]=&Amerique_Nord_4;


    Territoire Amerique_Sud_1(4,joueur_1.get_couleur(),0,2,331,"Amerique_Sud_1",205,288,3,5,6,30,30,30);  //Haut
    pays[4]=&Amerique_Sud_1;
    Territoire Amerique_Sud_2(5,joueur_2.get_couleur(),0,2,403,"Amerique_Sud_2",205,330,4,6,7,30,30,30);  //Gauche 
    pays[5]=&Amerique_Sud_2;
    Territoire Amerique_Sud_3(6,joueur_3.get_couleur(),0,2,405,"Amerique_Sud_3",280,330,4,5,7,30,30,30);  //Droit
    pays[6]=&Amerique_Sud_3;
    Territoire Amerique_Sud_4(7,joueur_1.get_couleur(),0,2,511,"Amerique_Sud_4",245,480,5,6,30,30,30,30);  //Bas
    pays[7]=&Amerique_Sud_4;

    Territoire Europe_1(8,joueur_3.get_couleur(),0,3,158,"Europe_1",0,0,9,30,30,30,30,30); //France
    pays[8]=&Europe_1;
    Territoire Europe_2(9,joueur_2.get_couleur(),0,3,124,"Europe_2",0,0,8,10,12,30,30,30); //Allemagne->Italie
    pays[9]=&Europe_2;
    Territoire Europe_3(10,joueur_3.get_couleur(),0,3,89,"Europe_3",0,0,9,11,12,30,30,30); //Scandinavie
    pays[10]=&Europe_3;
    Territoire Europe_4(11,joueur_1.get_couleur(),0,3,91,"Europe_4",0,0,13,11,12,30,30,30); //Debut Russie
    pays[11]=&Europe_4;
    Territoire Europe_5(12,joueur_2.get_couleur(),0,3,162,"Europe_5",0,0,10,11,16,30,30,30); //Debut Moyen Orient
    pays[12]=&Europe_5;

    Territoire Asie_1(13,joueur_2.get_couleur(),0,4,93,"Asie_1",0,0,11,14,16,17,18,30); //Russie Gauche 
    pays[13]=&Asie_1;
    Territoire Asie_2(14,joueur_3.get_couleur(),0,4,95,"Asie_2",0,0,13,15,18,19,30,30); //Sibérie ur
    pays[14]=&Asie_2;
    Territoire Asie_3(15,joueur_1.get_couleur(),0,4,98,"Asie_3",0,0,14,19,20,30,30,30); //Chine Nord Droit
    pays[15]=&Asie_3;
    Territoire Asie_4(16,joueur_3.get_couleur(),0,4,235,"Asie_4",0,0,23,12,13,17,30,30); //Arabie Saoudite
    pays[16]=&Asie_4;
    Territoire Asie_5(17,joueur_2.get_couleur(),0,4,200,"Asie_5",0,0,13,16,18,30,30,30); //Iran
    pays[17]=&Asie_5;
    Territoire Asie_6(18,joueur_3.get_couleur(),0,4,202,"Asie_6",0,0,13,14,17,19,30,30); //Inde
    pays[18]=&Asie_6;
    Territoire Asie_7(19,joueur_2.get_couleur(),0,4,204,"Asie_7",0,0,14,15,18,20,30,30); //Chine Sud Centre
    pays[19]=&Asie_7;
    Territoire Asie_8(20,joueur_1.get_couleur(),0,4,206,"Asie_8",0,0,15,19,30,30,30,30); //Chine Sud Droit
    pays[20]=&Asie_8;

    Territoire Afrique_1(21,joueur_3.get_couleur(),0,5,265,"Afrique_1",416,256,22,24,30,30,30,30); //Maroc
    pays[21]=&Afrique_1;
    Territoire Afrique_2(22,joueur_1.get_couleur(),0,5,230,"Afrique_2",460,220,21,23,24,30,30,30); //Algerie
    pays[22]=&Afrique_2;
    Territoire Afrique_3(23,joueur_2.get_couleur(),0,5,233,"Afrique_3",560,220,22,24,25,16,30,30); //Egypte->Syrie
    pays[23]=&Afrique_3;
    Territoire Afrique_4(24,joueur_2.get_couleur(),0,5,303,"Afrique_4",515,300,21,22,23,25,26,30); //Afrique Centrale
    pays[24]=&Afrique_4;
    Territoire Afrique_5(25,joueur_1.get_couleur(),0,5,342,"Afrique_5",570,260,23,24,26,30,30,30); //Afrique Centrale Gauche
    pays[25]=&Afrique_5;
    Territoire Afrique_6(26,joueur_3.get_couleur(),0,5,449,"Afrique_6",570,370,24,26,30,30,30,30); //Afrique Sud
    pays[26]=&Afrique_6;
    
    Territoire Oceanie_1(28,joueur_3.get_couleur(),0,6,459,"Oceanie_1",0,0,29,30,30,30,30,30); //Australie Gauche
    pays[27]=&Oceanie_1;
    Territoire Oceanie_2(29,joueur_1.get_couleur(),0,6,461,"Oceanie_2",0,0,28,30,30,30,30,30); //Australie Droit
    pays[28]=&Oceanie_2;
/*

   // 1->Rouge
   // 2->Jaune
   // 3-> Vert 

    //-----INITIALISATION FRONTIERE-----
    Frontiere frontiere_1(Amerique_Nord_1, Amerique_Nord_2);
    Frontiere frontiere_2(Amerique_Nord_1, Amerique_Nord_3);
    Frontiere frontiere_3(Amerique_Nord_2, Amerique_Nord_3);
    Frontiere frontiere_4(Amerique_Nord_2, Amerique_Nord_4);      
    Frontiere frontiere_5(Amerique_Nord_3, Amerique_Nord_4);
    Frontiere frontiere_6(Amerique_Nord_4, Amerique_Sud_1);
    Frontiere frontiere_7(Amerique_Sud_1, Amerique_Sud_2);
    Frontiere frontiere_8(Amerique_Sud_1, Amerique_Sud_3);
    Frontiere frontiere_9(Amerique_Sud_2, Amerique_Sud_3);
    Frontiere frontiere_10(Amerique_Sud_2, Amerique_Sud_4);
    Frontiere frontiere_11(Amerique_Sud_3, Amerique_Sud_4);
    
    Frontiere frontiere_12(Europe_1, Europe_2);
    Frontiere frontiere_13(Europe_2, Europe_3);
    Frontiere frontiere_14(Europe_2, Europe_5);
    Frontiere frontiere_15(Europe_3, Europe_5);

    Frontiere frontiere_40(Europe_3, Europe_4);  

    Frontiere frontiere_16(Europe_4, Europe_5);
    Frontiere frontiere_17(Europe_4, Asie_1);    int tampon[6]={1,30,30,30,30,30};
    
    Frontiere frontiere_18(Europe_5, Asie_4);
    Frontiere frontiere_19(Asie_1, Asie_2);
    Frontiere frontiere_20(Asie_1, Asie_4);
    Frontiere frontiere_21(Asie_1, Asie_5);

    Frontiere frontiere_41(Asie_1, Asie_6);  

    Frontiere frontiere_22(Asie_2, Asie_3);
    Frontiere frontiere_23(Asie_2, Asie_6);
    Frontiere frontiere_24(Asie_2, Asie_7); 
    Frontiere frontiere_25(Asie_3, Asie_7);
    Frontiere frontiere_26(Asie_3, Asie_8); 
    Frontiere frontiere_27(Asie_4, Asie_5);
    Frontiere frontiere_28(Asie_5, Asie_6); 
    Frontiere frontiere_29(Asie_6, Asie_7);
    Frontiere frontiere_30(Asie_7, Asie_8); 
    Frontiere frontiere_31(Afrique_1, Afrique_2);
    Frontiere frontiere_32(Afrique_1, Afrique_4);
    Frontiere frontiere_33(Afrique_2, Afrique_3);           int tampon[6]={1,30,30,30,30,30};
    
    Frontiere frontiere_34(Afrique_3, Afrique_4);
    Frontiere frontiere_35(Afrique_3, Afrique_5);
    Frontiere frontiere_36(Afrique_3, Asie_4);

    Frontiere frontiere_42(Afrique_4, Afrique_5);  

    Frontiere frontiere_37(Afrique_4, Afrique_6);
	Frontiere frontiere_39(Oceanie_1, Oceanie_2);*/


	//Initialisation des zones d'affichage des pions
	
	sf::Font font;
	if(!font.loadFromFile("../res/arial.ttf"))
	{	return -1;
	}
   
	
    //std::vector<Territoire> territoires;
    //territoires.push_back(Territoire("Afrique",27,2,0,5));
    
   /* for(int i=0;i<29;i++)
        cout<<pays[i]->nom<<endl;*/



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
            //level[Oceanie_2.get_position()]= joueur_2.get_couleur();

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
						action.DeplacerXPionsDeAversB(&joueur_2,pays[0], pays[2], 2);
					}
					else if(event.key.code == sf::Keyboard::Down)
					{
						action.AttaquerBavecXpionsDeA(&joueur_2, pays[0], pays[1], 2);
						level[pays[0]->get_position()]=pays[0]->get_couleur();
						cout<<"Couleur de AmN2: "<<pays[1]->couleur<<endl;
						level[pays[1]->get_position()]=pays[1]->couleur;
					}
					else if(event.key.code == sf::Keyboard::Escape)
					{
						action.AjouterXpions(&joueur_2, pays[0], 2);
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
    
        
/*        //Amerique_Nord_1
		std::string s1 = std::to_string(pays[0]->nombre_pion);
		text1.setFont(font);
		text1.setString(s1);
		text1.setCharacterSize(18);
		text1.setColor(sf::Color::Black);
		text1.setPosition(pays[0]->x,pays[0]->y);
	
		//Amerique_Nord_2
		std::string s2 = std::to_string(pays[1]->nombre_pion);
		text2.setFont(font);
		text2.setString(s2);
		text2.setCharacterSize(18);
		text2.setColor(sf::Color::Black);
		text2.setPosition(pays[1]->x,pays[1]->y);
	
		//Amerique_Nord_3
		std::string s3 = std::to_string(pays[2]->nombre_pion);
		text3.setFont(font);
		text3.setString(s3);
		text3.setCharacterSize(18);
		text3.setColor(sf::Color::Black);
		text3.setPosition(pays[2]->x,pays[2]->y);
	
		//Amerique_Nord_4
		std::string s4 = std::to_string(pays[3]->nombre_pion);
		text4.setFont(font);
		text4.setString(s4);
		text4.setCharacterSize(18);
		text4.setColor(sf::Color::Black);
		text4.setPosition(pays[3]->x,pays[3]->y);
*/
        for(i=0;i<4;i++)
        {
            s[i]=std::to_string(pays[i]->nombre_pion);
            text[i].setFont(font);
            text[i].setString(s[i]);
            text[i].setCharacterSize(18);
            text[i].setColor(sf::Color::Black);
            text[i].setPosition(pays[i]->x,pays[i]->y);

        }
		
		// c'est ici qu'on dessine tout
        // On dessine l'arrière plan
        window.draw(sprite);
        window.draw(map);
/*        window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
*/		
        for(i=0;i<4;i++)
        {
            window.draw(text[i]);
        }
        //TileMap map;
         window.display();

    }

    return 0;
}

