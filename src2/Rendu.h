#ifndef RENDU__H
#define RENDU__H

#include "Graphique_etape.h"
#include "Graphique_pays.h"

/// class Rendu - 
class Rendu {
  // Associations
  // Attributes
public:
  sf::RenderWindow & window;
  std::vector<Graphique_pays> pays;
  std::vector<Graphique_etape> etape;
  sf::Sprite fond;
  // Operations
public:
  void affiche_etat (Etat * e);
  void InitialisationRendu ();
};

#endif
