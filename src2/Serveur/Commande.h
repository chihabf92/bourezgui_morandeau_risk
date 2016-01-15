#ifndef COMMANDE__H
#define COMMANDE__H

/// class Commande - 
class Commande {
  // Attributes
public:
  string type;
  int param1;
  int param2;
  int param3;
  int param4;
  // Operations
public:
  Commande (string name, int param1, int param2, int param3, int param4);
};

#endif
