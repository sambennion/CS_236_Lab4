//
// Created by Samuel Bennion on 2/1/21.
//

#ifndef CS236_LAB1_COMMENTAUTOMA_H
#define CS236_LAB1_COMMENTAUTOMA_H
#include "Automaton.h"

class CommentAutoma : public Automaton {
private:

public:
    explicit CommentAutoma(TokenType type) : Automaton(type){this->type = type;};

    int Start(const std::string &input);
    int s0(const std::string &input);

    int s1(const string &input);
};


#endif //CS236_LAB1_COMMENTAUTOMA_H
