#ifndef GRAPHIQUE_PAYS__H
#define GRAPHIQUE_PAYS__H

/// class Graphique_pays - 
class Graphique_pays {
  // Attributes
public:
  sf::Text nombre_armee;
  sf::Sprite pion;
  int x_pion;
  int y_pion;
  int id;
  int x_text;
  int y_text;
  // Operations
public:
  Graphique_pays ();
  Graphique_pays (int a, int b, int c, int d);
  void Set_coordonnes (int a, int b, int c, int d);
};

#endif
