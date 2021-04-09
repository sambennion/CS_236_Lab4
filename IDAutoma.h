//
// Created by Samuel Bennion on 2/1/21.
//

#ifndef CS236_LAB1_IDAUTOMA_H
#define CS236_LAB1_IDAUTOMA_H
#include "Automaton.h"

class IDAutoma : public Automaton{
public:
    explicit IDAutoma(TokenType type) : Automaton(type) { this->type = type;};
    int Start(const string &input);

    int s0(const string &input);
};


#endif //CS236_LAB1_IDAUTOMA_H
