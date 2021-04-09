//
// Created by Samuel Bennion on 2/18/21.
//

#ifndef CS_236_LAB2_PARAMETER_H
#define CS_236_LAB2_PARAMETER_H
#include "Token.h"
class Parameter {
private:
    Token* token;
public:
    Parameter(Token* token){
        this->token = token;
    }
    Token getToken(){
        return *token;
    };
    std::string toString();
};


#endif //CS_236_LAB2_PARAMETER_H
