//
// Created by Samuel Bennion on 2/18/21.
//

#ifndef CS_236_LAB2_PREDICATE_H
#define CS_236_LAB2_PREDICATE_H

#include <vector>
#include "Parameter.h"
class Predicate {
private:
    std::string name;
    vector<Parameter*> parameters{};
public:
    Predicate(string name){
        this->name = name;
    }
    void addParameter(Parameter* param) {
        parameters.push_back(param);
    }
    string toString();

    std::string getName(){
        return name;
    }
    vector<Parameter*> getParameters(){
        return parameters;
    }
    vector<string> getParametersAsString(){
        vector<string> pAsString;
        for(Parameter* p : parameters){
            pAsString.push_back(p->toString());
        }
        return pAsString;
    }
};


#endif //CS_236_LAB2_PREDICATE_H
