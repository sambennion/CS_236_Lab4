//
// Created by Samuel Bennion on 2/1/21.
//

#include "CommentAutoma.h"

int CommentAutoma::Start(const string &input) {
    inputRead = 0;
    this->newLines = 0;
    if (input.at(0) == '#'){
        inputRead++;
        if(input.at(inputRead) == '|'){
            inputRead++;
            return s1(input);
        }
        return s0(input);
    }
    return 0;
}

int CommentAutoma::s0(const string &input) {
    while (input.at(inputRead) != '\n'){
        inputRead++;
        if(inputRead == (int)input.size()) {
            return inputRead;
        }
    }
    return inputRead;
}
int CommentAutoma::s1(const string &input){
    while(input.at(inputRead) != '|' && inputRead < (int)input.size()) {
        if(input.at(inputRead) == '\n'){
            this->newLines++;
        }
        inputRead++;
        if(inputRead == (int)input.size()){
            return 0;
        }
    }
    if (input.at(inputRead) == '|'){
        inputRead++;
        if(input.at(inputRead) == '#') {
            inputRead++;
            return inputRead;
        }
    }
    else if(input.at(inputRead) != '|'){
        if(inputRead == (int)input.size()){
            return 0;
        }
        if(input.at(inputRead) == '\n'){
            this->newLines++;
        }
        inputRead++;
        return s1(input);
    }
    return 0;
}