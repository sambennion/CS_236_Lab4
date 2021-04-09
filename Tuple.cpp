//
// Created by Samuel Bennion on 3/18/21.
//


#include "Tuple.h"

void Tuple::printTuples(){
    //cout << "relationName: " << relationName << endl;
    //cout << "starting printTuple()..." << endl;
    int j = 0;
    for (unsigned int i = 0; i < values.size(); i++){
        if ((j%2 == 0)){
            std::cout << "\n";
        }
        std::string output = values[i];
        std::cout << output;
        j++;
    }
    std::cout << "\n" << std::endl;

}

Tuple::Tuple() {
   // NULL;
}

void Tuple::setRelationName(std::string name) {
    relationName = name;
}

std::string Tuple::toString() {
    std::string s;
    s += "( ";
    for(std::string v : values){
        s += v + ", ";
    }
    s += " )";
    return s;
}
