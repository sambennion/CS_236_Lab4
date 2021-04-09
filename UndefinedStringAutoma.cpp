//
// Created by Samuel Bennion on 2/1/21.
//

#include "UndefinedStringAutoma.h"
int UndefinedStringAutoma::Start(const string &input) {
    // bool isMatch = true;
    inputRead = 0;
    this->newLines = 0;
    if(input.at(0) == '\''){
        inputRead++;
        return s0(input);
    }
    else{
        return 0;
    }
}
int UndefinedStringAutoma::s0(const string &input){

    while((input.at(inputRead) != '\'' && inputRead < (int)input.size()) || isDoubleQuote(input)) {
        if (input.at(inputRead) == '\n') {
            this->newLines++;
            //cout << this->newLines << endl;
        }
        if (isDoubleQuote((input))) {
            inputRead++;
        }
        inputRead++;
        if(inputRead == (int)input.length()){
            //newLines--;
            return inputRead;
        }
    }
    if(input.at(inputRead) == '\''){
        inputRead++;
        return 0;
    }
    return 0;
}
bool UndefinedStringAutoma::isDoubleQuote(const string input){
    if((int)input.size() > inputRead+2){
        if(input.at(inputRead) == '\'' && input.at(inputRead+1) == '\''){
            return true;
        }
    }
    return false;
}