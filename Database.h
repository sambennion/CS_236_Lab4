//
// Created by Samuel Bennion on 3/18/21.
//

#ifndef CS_236_LAB3_DATABASE_H
#define CS_236_LAB3_DATABASE_H
#include "Relation.h"
#include <map>
class Database {
private:
    std::map<std::string, Relation> relations;
public:
    void addRelation(std::string name, Relation relation){
        relations.insert({name, relation});
    }
};


#endif //CS_236_LAB3_DATABASE_H
