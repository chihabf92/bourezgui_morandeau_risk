#include "CommandeService.hpp"

CommandeService::CommandeService (UserDB& userDB) : AbstractService("/commande"),
    commandeDB(commandeDB) {
    
}

HttpStatus CommandeService::get (Json::Value& out, int id) const {
    const Commande* commande = commandeDB.getCommande(id);
    if (!commande)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid commande id");
    out["type"] = commande->type;
    out["param1"] = commande->param1;
    out["param2"] = commande->param2;
    out["param3"] = commande->param3;
    out["param4"] = commande->param4;
    return HttpStatus::OK;
}

HttpStatus CommandeService::post (const Json::Value& in, int id) {
    const Commande* commande = commandeDB.getCommande(id);
    if (!user)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid commande id");
    unique_ptr<Commande> commandemod (new Commande(*commande));
    if (in.isMember("type")) {
        commandemod->type = in["type"].asString();
    }
    if (in.isMember("param1")) {
        commandemod->param1 = in["param1"].asInt();
    }
    if (in.isMember("param2")) {
        commandemod->param2 = in["param2"].asInt();
    }
    if (in.isMember("param3")) {
        commandemod->param3 = in["param3"].asInt();
    }
    if (in.isMember("param4")) {
        commandemod->param4 = in["param4"].asInt();
    }    
    commandeDB.setCommande(id,std::move(commandemod));
    return HttpStatus::NO_CONTENT;
}

HttpStatus CommandeService::put (Json::Value& out,const Json::Value& in) {
    string type = in["type"].asString();
    int param1 = in["param1"].asInt();
    int param2 = in["param2"].asInt();
    int param3 = in["param3"].asInt();
    int param4 = in["param4"].asInt();
    out["id"] = commandeDB.addCommande(make_unique<Commande>(type,param1,param2,param3,param4));
    return HttpStatus::CREATED;
}

HttpStatus CommandeService::remove (int id) {
    const Commande* commande = commandeDB.getCommande(id);
    if (!commande)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid commande id");
   commandeDB.removeCommande(id);
    return HttpStatus::NO_CONTENT;
}

