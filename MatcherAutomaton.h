//
// Created by Samuel Bennion on 1/27/21.
//

#ifndef CS236_LAB1_MATCHERAUTOMATON_H
#define CS236_LAB1_MATCHERAUTOMATON_H
#include "Automaton.h"

class MatcherAutomaton: public Automaton {
private:
    string toMatch;

    //[13]

    //= {",", ".", "?", "(", ")", ":", ":-", "*", "+", "Schemes", "Facts", "Rules", "Queries"};
public:
    MatcherAutomaton(TokenType type, string toMatch) : Automaton(type) {
        this->toMatch = toMatch;
    };

    int Start(const string& input);
};


#endif //CS236_LAB1_MATCHERAUTOMATON_H
