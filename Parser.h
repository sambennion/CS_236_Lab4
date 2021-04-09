//
// Created by Samuel Bennion on 2/18/21.
//

#ifndef CS_236_LAB2_PARSER_H
#define CS_236_LAB2_PARSER_H
#include <vector>
#include "Token.h"
#include <sstream>
#include "DatalogProgram.h"
class Parser {
private:
    DatalogProgram datalog;
    int it = 0;
public:
    void Parse(vector<Token*> tokens);
    void schemeList(vector<Token*> tokens);
    void datalogProgram(vector<Token*> tokens);
    void factList(vector<Token*> tokens);
    void ruleList(vector<Token*> tokens);
    void queryList(vector<Token*> tokens);
    void scheme(vector<Token*> tokens);
    void fact(vector<Token*> tokens);
    void rule(vector<Token*> tokens);
    void query(vector<Token*> tokens);
    Predicate* headPredicate(vector<Token*> tokens);
    Predicate* predicate(vector<Token*> tokens);
    vector<Predicate*> predicateList(vector<Token*> tokens);
    vector<Parameter*> parameterList(vector<Token*> tokens);
    void stringList(vector<Token*> tokens);
    void idList(vector<Token*> tokens);
    Parameter* parameter(vector<Token*> tokens);
    Parameter* expression(vector<Token*> tokens);
    void operate(vector<Token*> tokens);
    void testToken(vector<Token*> tokens, string terminal);
    DatalogProgram getDatalogProgram(){
        return datalog;
    }
};


#endif //CS_236_LAB2_PARSER_H
