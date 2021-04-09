//
// Created by Samuel Bennion on 2/18/21.
//

#include "Parser.h"


void Parser::Parse(vector<Token*> tokens) {
    try{
        datalogProgram(tokens);
    }catch(Token* err) {
        cout << "Failure!\n  " << err->toString();
        return;
    }
    //We don't need toString() for this lab
//    cout << "Success!" << endl;
//    cout << datalog.toString();
}
void Parser::datalogProgram(vector<Token*> tokens) {
    if(tokens.at(it)->getTokenType() == "SCHEMES"){
        it++;
    } else{
        throw tokens.at(it);
    }
    if(tokens.at(it)->getTokenType() == "COLON"){
        it++;
    } else{
        throw tokens.at(it);
    }
    scheme(tokens);
    schemeList(tokens);
    if(tokens.at(it)->getTokenType() == "FACTS"){
        it++;
    } else{
        throw tokens.at(it);
    }
    if(tokens.at(it)->getTokenType() == "COLON"){
        it++;
    } else{
        throw tokens.at(it);
    }
    factList(tokens);
    if(tokens.at(it)->getTokenType() == "RULES"){
        it++;
    } else{
        throw tokens.at(it);
    }
    if(tokens.at(it)->getTokenType() == "COLON"){
        it++;
    } else{
        throw tokens.at(it);
    }
    ruleList(tokens);
    if(tokens.at(it)->getTokenType() == "QUERIES"){
        it++;
    } else{
        throw tokens.at(it);
    }
    if(tokens.at(it)->getTokenType() == "COLON"){
        it++;
    } else{
        throw tokens.at(it);
    }
    query(tokens);
    queryList(tokens);
    if(tokens.at(it)->getTokenType() == "EOF"){
        it++;
    } else{
        throw tokens.at(it);
    }
}
void Parser::schemeList(vector<Token*> tokens) {
    if(tokens.at(it)->getTokenType() == "ID") {
        scheme(tokens);
        schemeList(tokens);
    }
    else{
        return;
    }

}

void Parser::factList(vector<Token*> tokens) {
    if(tokens.at(it)->getTokenType() == "ID") {
        fact(tokens);
        factList(tokens);
    }
    else{
        return;
    }
}

void Parser::ruleList(vector<Token*> tokens) {
    if(tokens.at(it)->getTokenType() == "ID") {
        rule(tokens);
        ruleList(tokens);
    }
    else{
        return;
    }
}

void Parser::queryList(vector<Token*> tokens) {
    if(tokens.at(it)->getTokenType() == "ID") {
        query(tokens);
        queryList(tokens);
    }
    else{
        return;
    }
}

void Parser::scheme(vector<Token*> tokens) {
    int schemeBegin = it; //used for adding scheme to datalog
    if(tokens.at(it)->getTokenType() == "ID"){
        it++;
    } else{
        throw tokens.at(it);
    }
    if(tokens.at(it)->getTokenType() == "LEFT_PAREN"){
        it++;
    } else{
        throw tokens.at(it);
    }
    if(tokens.at(it)->getTokenType() == "ID"){
        it++;
    } else{
        throw tokens.at(it);
    }
    idList(tokens);
    if(tokens.at(it)->getTokenType() == "RIGHT_PAREN"){
        it++;
    } else{
        throw tokens.at(it);
    }
    //Add scheme to scheme vector
    Predicate* scheme = new Predicate(tokens.at(schemeBegin)->getData());
    datalog.addScheme(scheme);
    schemeBegin++;
    while(schemeBegin < it){
        if(tokens.at(schemeBegin)->getTokenType() == "ID") {
            datalog.getSchemes().at(datalog.getSchemes().size()-1)->addParameter(new Parameter(tokens.at(schemeBegin)));
        }
        schemeBegin++;
    }
    //cout << datalog.toString() << endl;
}


void Parser::fact(vector<Token*> tokens) {
    int factBegin = it;
    if(tokens.at(it)->getTokenType() == "ID"){
        it++;
    } else{
        throw tokens.at(it);
    }
    if(tokens.at(it)->getTokenType() == "LEFT_PAREN"){
        it++;
    } else{
        throw tokens.at(it);
    }
    if(tokens.at(it)->getTokenType() == "STRING"){
        it++;
    } else{
        throw tokens.at(it);
    }
    stringList(tokens);
    if(tokens.at(it)->getTokenType() == "RIGHT_PAREN"){
        it++;
    } else{
        throw tokens.at(it);
    }
    if(tokens.at(it)->getTokenType() == "PERIOD"){
        it++;
    } else{
        throw tokens.at(it);
    }
    //Add fact to datalog
    Predicate* fact = new Predicate(tokens.at(factBegin)->getData());
    datalog.addFact(fact);
    factBegin++;
    while(factBegin < it){
        if(tokens.at(factBegin)->getTokenType() == "STRING") {
            datalog.getFacts().at(datalog.getFacts().size()-1)->addParameter(new Parameter(tokens.at(factBegin)));
            datalog.addToDomain(tokens.at(factBegin)->getData());
        }
        factBegin++;
    }
}

void Parser::rule(vector<Token*> tokens) {
    //headPredicate(tokens); moved to below
    Rule* rule = new Rule(headPredicate(tokens));
    this->testToken(tokens, "COLON_DASH");
    //predicate(tokens);
    rule->addPredicate(predicate(tokens));
    //predicateList(tokens);
    vector<Predicate*> predList = predicateList(tokens);
    for(unsigned int i = 0; i < predList.size(); i++){
        //datalog.getRules().at(datalog.getRules().size()-1)->addPredicate(predList[i]);
        rule->addPredicate((predList[i]));
    }
    datalog.addRule(rule);

    this->testToken(tokens, "PERIOD");


}

void Parser::query(vector<Token*> tokens) {
    datalog.addQuery(predicate(tokens));
    this->testToken(tokens, "Q_MARK");
}

Predicate* Parser::headPredicate(vector<Token*> tokens) {
    int headPredicateBegin = it;
    this->testToken(tokens, "ID");
    this->testToken(tokens, "LEFT_PAREN");
    this->testToken(tokens, "ID");
    idList(tokens);
    this->testToken(tokens, "RIGHT_PAREN");
    Predicate* headPredicate = new Predicate(tokens.at(headPredicateBegin)->getData());
    headPredicateBegin++;
    while(headPredicateBegin < it){
        if(tokens.at(headPredicateBegin)->getTokenType() == "ID") {
            headPredicate->addParameter(new Parameter(tokens.at(headPredicateBegin)));
        }
        headPredicateBegin++;
    }
    return headPredicate;
}

Predicate* Parser::predicate(vector<Token*> tokens) {
    int predicateBegin = it;
    this->testToken(tokens, "ID");
    this->testToken(tokens, "LEFT_PAREN");
    Parameter* param = parameter(tokens);
    vector<Parameter*> paramList =  parameterList(tokens);
    this->testToken(tokens, "RIGHT_PAREN");
    //add predicate to datalog
    Predicate* predicate = new Predicate(tokens.at(predicateBegin)->getData());
    //datalog.addFact(fact);
    predicateBegin++;
    // I can't get this code to work for some reason... I need it to work for expressions to work.
    predicate->addParameter(param);
    for(unsigned int i = 0; i < paramList.size(); i++){
        predicate->addParameter(paramList[i]);
    }

    /*
    while(predicateBegin < it){
        if(tokens.at(predicateBegin)->getTokenType() == "STRING" || tokens.at(predicateBegin)->getTokenType() == "ID" || tokens.at(it)->getTokenType() == "LEFT_PAREN") { // added ID because rules were having problems.
            predicate->addParameter(new Parameter(tokens.at(predicateBegin)));
        }
        predicateBegin++;
    }
*/
    return predicate;
}

vector<Predicate*> Parser::predicateList(vector<Token*> tokens) {
    vector<Predicate*> predicateListV;
    if(tokens.at(it)->getTokenType() == "COMMA"){
        this->testToken(tokens, "COMMA");
        //predicate(tokens); moved to line below
        predicateListV.push_back(predicate(tokens));
        vector<Predicate*> recursivePredList = predicateList(tokens); //just added this but it doesn't seem to do a lot.
        for(unsigned int i = 0; i < recursivePredList.size(); i++){
            predicateListV.push_back(recursivePredList[i]);
        }

    }
    else{
        return {};
    }
    return predicateListV;

}

vector<Parameter*> Parser::parameterList(vector<Token*> tokens) {
    vector<Parameter*> paramList = {};
    if(tokens.at(it)->getTokenType() == "COMMA"){
        this->testToken(tokens, "COMMA");
        paramList.push_back(parameter(tokens));
        vector<Parameter*>recursiveParamList =  parameterList(tokens);
        for(unsigned int i = 0; i < recursiveParamList.size(); i++){
            paramList.push_back(recursiveParamList[i]);
        }
    }
    else{
        return {};
    }
    return paramList;
}

void Parser::stringList(vector<Token*> tokens) {
    if(tokens.at(it)->getTokenType() == "COMMA"){
        this->testToken(tokens, "COMMA");
        this->testToken(tokens, "STRING");
        stringList(tokens);
    }
    else{
        return;
    }
}

void Parser::idList(vector<Token*> tokens) {
    if(tokens.at(it)->getTokenType() == "COMMA"){
        this->testToken(tokens, "COMMA");
        this->testToken(tokens, "ID");
        idList(tokens);
    }
    else{
        return;
    }
}

Parameter* Parser::parameter(vector<Token*> tokens) {
    int parameterBegin = it;
    if(tokens.at(it)->getTokenType() == "STRING") {
        this->testToken(tokens, "STRING");
        return new Parameter(tokens.at(parameterBegin));
    }
    else if(tokens.at(it)->getTokenType() == "ID") {
        this->testToken(tokens, "ID");
        return new Parameter(tokens.at(parameterBegin));
    }
    else if(tokens.at(it)->getTokenType() == "LEFT_PAREN"){
        return expression(tokens);
    }
    else{
        throw tokens.at(it);
    }
}

Parameter* Parser::expression(vector<Token*> tokens) {
    int expressionBegin = it;
    int lnNum = tokens.at(it)->getLineNum();
    testToken(tokens, "LEFT_PAREN");
    parameter(tokens);
    operate(tokens);
    parameter(tokens);
    testToken(tokens, "RIGHT_PAREN");
    // creating a token for expression
    string strExpression = "";
    while(expressionBegin < it){
        strExpression.append(tokens.at(expressionBegin)->getData());
        expressionBegin++;
    }
    Parameter* expression = new Parameter(new Token(ID, strExpression, lnNum));
    return expression;
}

void Parser::operate(vector<Token*> tokens) {
    if(tokens.at(it)->getTokenType() == "ADD"){
        testToken(tokens, "ADD");
    }
    else if (tokens.at(it)->getTokenType() == "MULTIPLY"){
        testToken(tokens, "MULTIPLY");
    }
    else{
        throw tokens.at(it);
    }
}

void Parser::testToken(vector<Token*> tokens, string terminal) {
    if(tokens.at(it)->getTokenType() == terminal){
        it++;
    } else{
        throw tokens.at(it);
    }
}
