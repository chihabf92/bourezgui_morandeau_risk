#ifndef ATTAQUER__H
#define ATTAQUER__H

#include "Action.h"

/// class Attaquer - 
class Attaquer : public Action {
  // Attributes
public:
  int nombre_armee;
  int defenseur;
  int attaquant;
  // Operations
public:
  Attaquer ();
};

#endif
