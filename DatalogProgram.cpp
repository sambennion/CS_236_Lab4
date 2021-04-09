//
// Created by Samuel Bennion on 2/18/21.
//

#include "DatalogProgram.h"

string DatalogProgram::toString() {
    stringstream ss;
    //cout << "schemes" << endl;
    ss << "Schemes(" << schemes.size() << "):\n";
    for (unsigned int i = 0; i < schemes.size(); i++) {
        ss << "  " << schemes[i]->toString() << '\n';
    }
    //cout << "facts" << endl;
    ss << "Facts(" << facts.size() << "):\n";
    for (unsigned int i = 0; i < facts.size(); i++) {
        ss << "  " << facts[i]->toString() << ".\n";
    }
    //cout << "rules" << endl;
    ss << "Rules(" << rules.size() << "):\n";
    for (unsigned int i = 0; i < rules.size(); i++) {
        ss << "  " << rules[i]->toString();
    }
    //cout << "Queries" << endl;
    ss << "Queries(" << queries.size() << "):\n";
    for (unsigned int i = 0; i < queries.size(); i++) {
        ss << "  " << queries[i]->toString() << "?\n" ;
    }
    //cout << "Domain" << endl;
    ss << "Domain(" << domain.size() << "):\n";
    for (set<string>::iterator i = domain.begin(); i != domain.end(); i++) {
        ss << "  " << *i << '\n';
    }
    return ss.str();
}

