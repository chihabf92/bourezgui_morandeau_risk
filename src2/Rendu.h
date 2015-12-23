#ifndef RENDU__H
#define RENDU__H

#include "Graphique_etape.h"
#include "Graphique_pays.h"

/// class Rendu - 
class Rendu {
  // Associations
  // Attributes
public:
  sf::RenderWindow  window;
  std::vector<Graphique_pays> pays;
  std::vector<Graphique_etape> etape;
  sf::Sprite fond;
  // Operations
public:
  Rendu  ();
  void Affiche_etat (Etat * e);
  void Initialisation_Rendu ();
};

#endif
