//
// Created by Samuel Bennion on 2/3/21.
//

#include "UndefinedCommentAutoma.h"
int UndefinedCommentAutoma::Start(const string &input) {
    inputRead = 0;
    this->newLines = 0;
    if (input.at(0) == '#'){
        inputRead++;
        if(input.at(inputRead) == '|'){
            inputRead++;
            return s1(input);
        }
        return 0;
    }
    return 0;
}

int UndefinedCommentAutoma::s1(const string &input){
//    if(input.at(inputRead) == '\n'){
//        this->newLines++;
//        inputRead++;
//    }
    while(input.at(inputRead) != '|' && inputRead < (int)input.size()) {
        if(input.at(inputRead) == '\n'){
            this->newLines++;
        }
        inputRead++;
        if(inputRead == (int)input.length()){
            return inputRead;
        }
    }
    if (input.at(inputRead) == '|'){
        inputRead++;
        if(input.at(inputRead) == '#') {
            inputRead++;
            return 0;
        }
        if(input.at(inputRead) == '\n'){
            this->newLines++;
        }
        inputRead++;
        return s1(input);
    }
    else if(input.at(inputRead) != '|'){
        if(inputRead == (int)input.size()){
            return inputRead;
        }
        if(input.at(inputRead) == '\n'){
            this->newLines++;
        }
        inputRead++;
        return s1(input);
    }
    return 0;
}