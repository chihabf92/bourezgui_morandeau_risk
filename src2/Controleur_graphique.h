#ifndef CONTROLEUR_GRAPHIQUE__H
#define CONTROLEUR_GRAPHIQUE__H

#include "Moteur.h"

/// class Controleur_graphique - permet de gérer les évenements
class Controleur_graphique {
  // Associations
  // Attributes
public:
  Rendu & vue;
  Moteur & moteur;
  Etat & e;
  // Operations
public:
  void gerer_evenement (sf::Event e);
};

#endif
