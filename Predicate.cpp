//
// Created by Samuel Bennion on 2/18/21.
//

#include "Predicate.h"
#include <sstream>
string Predicate::toString() {
    stringstream ss;
    ss << name << '(';
    for (unsigned i=0; i < parameters.size(); i++) {
        ss << parameters[i]->toString();
        if (i < parameters.size()-1)
            ss << ',';
    }
    /*
    if(this->name == "Query"){
        ss << ").";
    }
    else{
     */
        ss << ")";
    //}

    return ss.str();
}
