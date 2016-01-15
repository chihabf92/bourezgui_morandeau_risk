#ifndef COMMANDESERVICE__H
#define COMMANDESERVICE__H

#include "HttpStatus.h"
#include "AbstractService.h"
#include "CommandeDB.h"

/// class CommandeService - 
class CommandeService : public AbstractService {
  // Associations
  // Attributes
protected:
  CommandeDB& commandeDB;
  // Operations
public:
  CommandeService (CommandeDB& commandeDB);
  HttpStatus get (Json::Value& out, int id) const;
  HttpStatus post (const Json::Value& in, int id);
  HttpStatus put (Json::Value& out, const Json::Value& in);
  HttpStatus remove (int id);
};

#endif
