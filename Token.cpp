//
// Created by Samuel Bennion on 1/27/21.
//

#include "Token.h"

string Token::toString() {
    return "(" + tokenToString(type) + ",\"" + data + "\"," + to_string(lineNum) + ")";
}

string Token::tokenToString(TokenType type) {

    switch(type){
        case COMMA:
            return "COMMA";
            break;
        case PERIOD:
            return "PERIOD";
            break;
        case Q_MARK:
            return "Q_MARK";
            break;
        case LEFT_PAREN:
            return "LEFT_PAREN";
            break;
        case RIGHT_PAREN:
            return "RIGHT_PAREN";
            break;
        case MULTIPLY:
            return "MULTIPLY";
            break;
        case ADD:
            return "ADD";
            break;
        case COLON:
            return "COLON";
            break;
        case COLON_DASH:
            return "COLON_DASH";
            break;
        case RULES:
            return "RULES";
            break;
        case QUERIES:
            return "QUERIES";
            break;
        case FACTS:
            return "FACTS";
            break;
        case SCHEMES:
            return "SCHEMES";
            break;
        case ID:
            return "ID";
            break;
        case STRING:
            return "STRING";
            break;
        case COMMENT:
            return "COMMENT";
            break;
        case UNDEFINED:
            return "UNDEFINED";
            break;
        case enumEOF:
            return "EOF";
            break;
        default:
            return "Uh Oh";
            break;
    }
}

string Token::getTokenType() {
    return this->tokenToString(type);
}

string Token::getData() {
    return this->data;
}

int Token::getLineNum() {
    return this->lineNum;
}
