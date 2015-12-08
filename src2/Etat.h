#ifndef ETAT__H
#define ETAT__H

#include "Plateau.h"
#include "Etape.h"

/// class Etat - etat d'un jeu
class Etat {
  // Associations
  // Attributes
public:
  Plateau p;
  Etape e;
  int nombre_joueur;
  int joueur_en_cours;
};

#endif
