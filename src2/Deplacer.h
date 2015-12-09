#ifndef DEPLACER__H
#define DEPLACER__H

#include "Action.h"

/// class Deplacer - 
class Deplacer : public Action {
  // Attributes
public:
  int pays_initial;
  int pays_final;
  int nombre_armee;
  // Operations
public:
  Deplacer ();
};

#endif
