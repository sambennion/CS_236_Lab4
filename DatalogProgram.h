//
// Created by Samuel Bennion on 2/18/21.
//

#ifndef CS_236_LAB2_DATALOGPROGRAM_H
#define CS_236_LAB2_DATALOGPROGRAM_H
#include "Rule.h"
#include <set>
class DatalogProgram {
private:
    vector<Predicate*> schemes;
    vector<Predicate*> facts;
    vector<Rule*> rules;
    vector<Predicate*> queries;
    set<string> domain;
public:
    DatalogProgram(){};
    void addScheme(Predicate* scheme) {
        schemes.push_back(scheme);
    }
    void addFact(Predicate* fact) {
        facts.push_back(fact);
    }
    void addRule(Rule* rule) {
        rules.push_back(rule);
    }
    void addQuery(Predicate* query) {
        queries.push_back(query);
    }
    void addToDomain(string id) {
        domain.insert(id);
    }
    vector<Predicate*> getSchemes() {
        return schemes;
    }
    vector<Predicate*> getFacts() {
        return facts;
    }
    vector<Rule*> getRules() {
        return rules;
    }
    vector<Predicate*> getQueries() {
        return queries;
    }
    set<string> getDomain() {
        return domain;
    }
    string toString();
};


#endif //CS_236_LAB2_DATALOGPROGRAM_H
