//
// Created by Samuel Bennion on 3/24/21.
//

#ifndef CS_236_LAB3_INTERPRETER_H
#define CS_236_LAB3_INTERPRETER_H
#include "DatalogProgram.h"
#include "Database.h"

class Interpreter {
private:
    DatalogProgram dlProgram;
    Database db;
    vector<Tuple> tuples;
    vector<Relation> relations;
    void createRelations(vector<Predicate*> schemes);
    void createTuples(vector<Predicate*> facts);
    Relation matchRelationFromQuery(Predicate* query);
public:
    explicit Interpreter(DatalogProgram dlProgram){
        createRelations(dlProgram.getSchemes());
        createTuples(dlProgram.getFacts());
        for(Relation r : relations) {
            db.addRelation(r.getName(), r);
        }
        evalQueries(dlProgram.getQueries());
    }
    void evalQueries(vector<Predicate *> queries);
};


#endif //CS_236_LAB3_INTERPRETER_H
