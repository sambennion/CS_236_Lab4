//
// Created by Samuel Bennion on 3/24/21.
//

#include "Interpreter.h"

void Interpreter::evalQueries(vector<Predicate *> queries) {

    for (Predicate *q : queries) {
        vector<int> indices;
        Relation matchingRelation;
        vector<string> varsUsedInQuery;
        matchingRelation = matchRelationFromQuery(q);
        vector<Parameter *> qParams = q->getParameters();
        int dupPosition;
        for (unsigned int i = 0; i < qParams.size(); i++) {
            string tType = qParams[i]->getToken().getTokenType();
            string tData = qParams[i]->getToken().getData();
            bool isDuplicateVar = false;
            if (tType == "STRING") {
                matchingRelation = matchingRelation.select(i, tData);
            } else if (tType == "ID") {
                for (unsigned int j = 0; j < varsUsedInQuery.size(); j++) {
                    if (varsUsedInQuery[j] == tData) {
                        isDuplicateVar = true;
                        dupPosition = j;
                    }
                }
            }
            if(isDuplicateVar){
                matchingRelation = matchingRelation.select(dupPosition, i);
            }
            else{
                varsUsedInQuery.push_back(tData);
                indices.push_back(i);
            }
        }
        matchingRelation = matchingRelation.project(indices);
        matchingRelation = matchingRelation.rename(varsUsedInQuery);

        //Everything below is for printing the query results
        stringstream ss;
        for(unsigned int i = 0; i < qParams.size(); i++){
            ss << qParams[i]->toString();
            if(!(i == (qParams.size()-1))){
                ss << ",";
            }
        }
        int num = matchingRelation.numOfTuples(varsUsedInQuery);
        cout << matchingRelation.getName() << "(" << ss.str() << ")?";
        if((matchingRelation.getTuples().size() > 0)){
            cout << " Yes(" << num << ")" << endl;
        }
        else{
            cout << " No" << endl;
        }
        matchingRelation.presentTuples(indices, varsUsedInQuery, num);
        //cout << matchingRelation.tuplesResults(indices, varsUsedInQuery, num);
    }
}
Relation Interpreter::matchRelationFromQuery(Predicate *query) {
    unsigned int i = 0;
    while((query->getName() != relations[i].getName()) || i == relations.size()){
        i++;
    }
    if(query->getName() == relations[i].getName()){
        return relations[i];
    }
        else{
            return Relation();
        }
}

void Interpreter::createTuples(vector<Predicate *> facts) {
    for (Predicate *f : facts) {
        tuples.push_back(Tuple(f->getName(), f->getParametersAsString()));
    }
    unsigned int i;
    for (Tuple t : tuples) {
        i = 0;
        while ((t.getRelationName() != relations[i].getName()) || i == relations.size()) {
            i++;
        }
        if (t.getRelationName() == relations[i].getName()) {
            t.setRelationName(relations[i].getName());
            relations[i].addTuple(t);
        }
    }
}

void Interpreter::createRelations(vector<Predicate *> schemes) {
    for(Predicate* s : schemes){
        relations.push_back(Relation(s->getName(), s->getParametersAsString()));
    }
}
