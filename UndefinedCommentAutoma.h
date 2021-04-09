//
// Created by Samuel Bennion on 2/3/21.
//

#ifndef CS236_LAB1_UNDEFINEDCOMMENTAUTOMA_H
#define CS236_LAB1_UNDEFINEDCOMMENTAUTOMA_H
#include "Automaton.h"

class UndefinedCommentAutoma : public Automaton {
private:

public:
    explicit UndefinedCommentAutoma(TokenType type) : Automaton(type){this->type = type;};

    int Start(const std::string &input);

    int s1(const string &input);
};


#endif //CS236_LAB1_UNDEFINEDCOMMENTAUTOMA_H
