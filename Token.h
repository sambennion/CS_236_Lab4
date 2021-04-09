//
// Created by Samuel Bennion on 1/27/21.
//

#ifndef CS236_LAB1_TOKEN_H
#define CS236_LAB1_TOKEN_H
#include <iostream>

enum TokenType {COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, COLON, COLON_DASH, RULES, QUERIES, FACTS, SCHEMES, ID, STRING, COMMENT, ADD, MULTIPLY, UNDEFINED, enumEOF};
using namespace std;
class Token {
private:
    TokenType type;
    string data;
    int lineNum;
public:
    Token(TokenType type, string data, int lineNum){
        this->type = type;
        this->data = data;
        this->lineNum = lineNum;
    }
    string tokenToString(TokenType type);
    string toString();
    string getTokenType();
    string getData();
    int getLineNum();
};


#endif //CS236_LAB1_TOKEN_H
