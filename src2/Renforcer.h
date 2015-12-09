#ifndef RENFORCER__H
#define RENFORCER__H

#include "Action.h"

/// class Renforcer - 
class Renforcer : public Action {
  // Attributes
public:
  int pays_a_renforcer;
  int nombre_armee_a_mettre;
  // Operations
public:
  Renforcer ();
};

#endif
