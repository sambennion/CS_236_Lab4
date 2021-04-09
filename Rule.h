//
// Created by Samuel Bennion on 2/18/21.
//

#ifndef CS_236_LAB2_RULE_H
#define CS_236_LAB2_RULE_H
#include "Predicate.h"
#include <sstream>
class Rule {
private:
    Predicate* predicate;
    vector<Predicate*> predicateList;
public:
    Rule(Predicate* predicate){
        this->predicate = predicate;
    }
    Predicate* getHeadPredicate() {
        return this->predicate;
    }
    vector<Predicate*> getPredicateList() {
        return predicateList;
    }
    void addPredicate(Predicate* predicate){
        predicateList.push_back(predicate);
    }
    string toString();
};


#endif //CS_236_LAB2_RULE_H
