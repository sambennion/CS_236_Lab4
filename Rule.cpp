//
// Created by Samuel Bennion on 2/18/21.
//

#include "Rule.h"


string Rule::toString() {
    for(unsigned i = 0; i < this->predicateList.size(); i++){
        stringstream ss;
        ss << predicate->toString() << " :- ";
        for (unsigned i=0; i < predicateList.size(); i++) {
            ss << predicateList[i]->toString();
            if (i < predicateList.size()-1)
                ss << ',';
        }
        ss << ".\n";
        return ss.str();
    }
    return "";
}
