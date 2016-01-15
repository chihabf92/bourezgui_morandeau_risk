#ifndef COMMANDEDB__H
#define COMMANDEDB__H

#include "Commande.h"

/// class CommandeDB - 
class CommandeDB {
  // Associations
  // Attributes
protected:
  int idseq;
  map<int,unique_ptr<Commande> > commande;
  // Operations
public:
  CommandeDB ();
  const Commande* getCommande (int id) const;
  int addCommande (unique_ptr<Commande> commande);
  void removeCommande (int id);
  const Commande* makeCommande (int id, unique_ptr<Commande> commande);
};

#endif
