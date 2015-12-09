#ifndef PAYS__H
#define PAYS__H

/// class Pays - 
class Pays {
  // Attributes
public:
  int nombre_armee;
  int joueur;
  int identifiant_pays;
  std::vector<int> voisin;
  // Operations
public:
  Pays ();
  Pays (int a, int b, int c, std::vector<int> d);
};

#endif
