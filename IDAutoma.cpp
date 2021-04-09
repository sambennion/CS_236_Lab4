//
// Created by Samuel Bennion on 2/1/21.
//

#include "IDAutoma.h"

int IDAutoma::Start(const string &input) {
    inputRead = 0;
    if((input.at(0) >= 'a' && input.at(0) <= 'z') || (input.at(0) >= 'A' && input.at(0) <= 'Z') ){
        inputRead++;
        return s0(input);
    }
    return 0;
}

int IDAutoma::s0(const string &input) {
    if((input.at(inputRead) >= 'a' && input.at(inputRead) <= 'z') || (input.at(inputRead) >= 'A' && input.at(inputRead) <= 'Z') ||
    (input.at(inputRead) >= '0' && input.at(inputRead) <= '9')){
        inputRead++;
        if(inputRead == (int)input.size()){
            return inputRead;
        }
        return s0(input);
    }
    else{
        return inputRead;
    }
    //return 0;
}
