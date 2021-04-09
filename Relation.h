//
// Created by Samuel Bennion on 2/24/21.
//

#ifndef CS_236_LAB3_RELATION_H
#define CS_236_LAB3_RELATION_H
#include "Tuple.h"
#include <set>
using namespace std;
class Relation {
private:
    std::string name;
    std::vector<std::string> headers;
    std::set<Tuple> tuples = {}; // needs to be a set

public:
    Relation();

    Relation(std::string _name, std::vector<std::string> _headers) {
        name = std::move(_name);
        headers = std::move(_headers);
    }

    void addTuple(const Tuple &tuple) {
        tuples.insert(tuple);
    }

    std::string toString();

    std::string getName() {
        return name;
    }

    std::set<Tuple> getTuples() {
        return tuples;
    }

    Relation select(int index, std::string value2);

    Relation select(int index1, int index2);

    Relation project(std::vector<int> indices);

    Relation rename(std::vector<std::string> ids);

    int numOfTuples(std::vector<std::string> vars);

    void presentTuples(std::vector<int> positions, std::vector<std::string> IDs, int number);

};

#endif //CS_236_LAB3_RELATION_H
