//
// Created by Samuel Bennion on 2/1/21.
//

#ifndef CS236_LAB1_AUTOMATON_H
#define CS236_LAB1_AUTOMATON_H
#include <iostream>
#include "Token.h"
//enum TokenType {COMMA, PERIOD, Q_MARK, LEFT_PAREN, COLON, RIGHT_PAREN,
//        COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING, COMMENT, UNDEFINED,EOF};
class Automaton {
protected:
    int inputRead = 0;
    int newLines = 0;
    TokenType type;
public:
    Automaton(TokenType type) {this->type = type;};
    virtual int Start(const std::string& input) = 0;
    virtual Token* CreateToken(std::string input, int lineNumber) {
        return new Token(type, input, lineNumber);
    }
    virtual int NewLinesRead() const { return newLines; }
};


#endif //CS236_LAB1_AUTOMATON_H
