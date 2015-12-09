#ifndef RENDU__H
#define RENDU__H

/// class Rendu - 
class Rendu {
  // Attributes
public:
  sf::RenderWindow & window;
  std::vector<Graphique_pays> pays;
  std::vector<Graphique_etape> pions;
  sf::Sprite fond;
  // Operations
public:
  void affiche_etat (Etat * e);
};

#endif
