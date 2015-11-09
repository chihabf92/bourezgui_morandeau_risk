#include <cstdlib>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>

#include "Joueur.hpp"
#include "Etat_jeu.hpp"
#include "Territoire.hpp"
#include "Frontiere.hpp"

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

    /*-----INITIALISATION JOUEUR-----*/

    Joueur joueur_1;
    Joueur joueur_2;
    Joueur joueur_3;

    joueur_1.set_couleur(1); //Rouge 
    joueur_2.set_couleur(2); //Jaune
    joueur_3.set_couleur(3); //Vert

    /*-----INITIALISATION TERRITOIRE----*/

    Territoire Amerique_Nord_1(1,joueur_2.get_couleur(),0,1,76); //Canada,
    Territoire Amerique_Nord_2(2,joueur_1.get_couleur(),0,1,147); //USA gauche
    Territoire Amerique_Nord_3(3,joueur_2.get_couleur(),0,1,150); //USA droite
    Territoire Amerique_Nord_4(4,joueur_3.get_couleur(),0,1,219); //USA Bas

    Territoire Amerique_Sud_1(5,joueur_1.get_couleur(),0,2,331);  //Haut
    /*Territoire Amerique_Sud_2(6,2,0,2);  //Gauche 
    Territoire Amerique_Sud_3(7,3,0,2);  //Droit
    Territoire Amerique_Sud_4(8,1,0,2);  //Bas

    Territoire Europe_1(9,3,0,3); //France
    Territoire Europe_2(10,2,0,3); //Allemagne->Italie
    Territoire Europe_3(11,3,0,3); //Scandinavie
    Territoire Europe_4(12,1,0,3); //Debut Russie
    Territoire Europe_5(13,2,0,3); //Debut Moyen Orient

    Territoire Asie_1(14,2,0,4); //Russie Gauche 
    Territoire Asie_2(15,3,0,4); //Sibérie 
    Territoire Asie_3(16,1,0,4); //Chine Nord Droit
    Territoire Asie_4(17,3,0,4); //Arabie Saoudite
    Territoire Asie_5(18,2,0,4); //Iran
    Territoire Asie_6(19,3,0,4); //Inde
    Territoire Asie_7(20,2,0,4); //Chine Sud Centre
    Territoire Asie_8(21,1,0,4); //Chine Sud Droit

    Territoire Afrique_1(22,3,0,5); //Maroc
    Territoire Afrique_2(23,1,0,5); //Algerie
    Territoire Afrique_3(24,2,0,5); //Egypte->Syrie
    Territoire Afrique_4(25,2,0,5); //Afrique Centrale
    Territoire Afrique_5(26,1,0,5); //Afrique Centrale Gauche
    Territoire Afrique_6(27,2,0,5); //Afrique Sud
    
    Territoire Oceanie_1(28,3,0,6); //Australie Gauche
    Territoire Oceanie_2(29,1,0,6); //Australie Droit*/

   // 1->Rouge
   // 2->Jaune
   // 3-> Vert 

    /*-----INITIALISATION FRONTIERE-----*/
    /*Frontiere frontiere_1(Amerique_Nord_1, Amerique_Nord_2);
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
    Frontiere frontiere_17(Europe_4, Asie_1);
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
    Frontiere frontiere_33(Afrique_2, Afrique_3);       
    Frontiere frontiere_34(Afrique_3, Afrique_4);
    Frontiere frontiere_35(Afrique_3, Afrique_5);
    Frontiere frontiere_36(Afrique_3, Asie_4);

    Frontiere frontiere_42(Afrique_4, Afrique_5);  

    Frontiere frontiere_37(Afrique_4, Afrique_6);
   Frontiere frontiere_39(Oceanie_1, Oceanie_2);*/

    //std::vector<Territoire> territoires;
    //territoires.push_back(Territoire("Afrique",27,2,0,5));



    int level[] =
    { /* 1 2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36                                                                                                          */      
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
            level[Amerique_Sud_1.get_position()]= joueur_3.get_couleur();

    /*INITIALISATION ETAT DE JEU-----*/

    Etat_jeu map;
    if (!map.load("../res/Tileset.png", sf::Vector2u(32, 32), level, 36, 36))
        return -1;


   
    // on fait tourner le programme tant que la fenêtre n'a pas été fermée
    while (window.isOpen())
    {
        // on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
        sf::Event event;
        while (window.pollEvent(event))
        {
            // fermeture de la fenêtre lorsque l'utilisateur le souhaite
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // effacement de la fenêtre en noir
        window.clear(sf::Color::Black);

        // c'est ici qu'on dessine tout
        // On dessine l'arrière plan
        window.draw(sprite);
        window.draw(map);

        //TileMap map;
         window.display();



    }

    return 0;
}