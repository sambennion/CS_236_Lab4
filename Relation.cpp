//
// Created by Samuel Bennion on 2/24/21.
//

#include "Relation.h"

Relation Relation::select(int index, std::string value2) {
    Relation r;
    r.name = this->name;
    r.headers = this->headers;
    for(Tuple t : tuples){
        if(t.getValues()[index] == value2){
            r.addTuple(t);
        }
    }
    return r;
}

Relation Relation::select(int index1, int index2) {
    Relation r;
    r.name = this->name;
    r.headers = this->headers;
    for(Tuple t : tuples){
        if(t.getValues()[index1] == t.getValues()[index2]){
            r.addTuple(t);
        }
    }
    return r;
}

Relation Relation::project(std::vector<int> indices) {
    Relation r;
    r.name = this->name;
    r.headers = this->headers;

    Tuple retTuple;
    for(Tuple t : tuples){
        for(unsigned int i = 0; i < indices.size(); i++){
            retTuple.addValue(t.getValues().at(indices.at(i)));
        }
    }
    if(retTuple.getValues().size() > 0){
        r.addTuple(retTuple);
    }
    return r;
}

Relation Relation::rename(std::vector<std::string> ids) {
    Relation r;
    r.name = name;
    r.tuples = tuples;
    if(ids.size() > 0){
        r.headers = ids;
    }
    return r;
}

Relation::Relation() {
    //NULL;
}

int Relation::numOfTuples(std::vector<std::string> vars){
    int howMany = 0;
    for(Tuple t : tuples){
        std::stringstream ss;
        for (unsigned int j = 0; j < t.getValues().size(); j++) {
            howMany++;
        }
    }
    if (howMany != 0){
        return (howMany / vars.size());
    }
    else return 1;
}

void Relation::presentTuples(std::vector<int> positions, std::vector<std::string> IDs, int number) {

    set<int> indicesToSkip = {};
    for (unsigned int i = 0; i < IDs.size(); i++) {
        if (IDs.at(i)[0] == '\'') {
            indicesToSkip.insert(i);
        }
    }
    unsigned int idsToPrint = positions.size() - indicesToSkip.size();
    unsigned int totalItemsToPrint = idsToPrint * number;
    unsigned int totalPrintedItems = 0;
    if (totalItemsToPrint) { // Putting it in this if statement to make sure there is stuff to print.
        for (Tuple t : tuples) {

            string s = "  ";
            unsigned int indexCounter = 0;
            unsigned int loopCount = 1;
            for (unsigned int i = 0; i < t.getValues().size(); i++) {

                if (indexCounter == IDs.size()) {
                    indexCounter = 0;
                    loopCount++;
                }
                if (indicesToSkip.count(indexCounter)) {

                } else if (((totalPrintedItems + 1) / loopCount == IDs.size() - indicesToSkip.size()) ||
                           idsToPrint == 1) {
                    totalPrintedItems++;
                    s += IDs[i % positions.size()] + "=" + t.getValues()[i];
                    if (totalItemsToPrint == totalPrintedItems) {
                        s += "\n";
                    } else if (i < t.getValues().size()) {
                        s += "\n  ";
                    }
                } else {
                    totalPrintedItems++;
                    s += IDs[i % positions.size()] + "=";
                    s += t.getValues()[i] + ", ";

                }
                indexCounter++;
            }
            cout << s;

        }
    }


}

std::string Relation::toString() {

    std::string s;
    s += name + "( ";
    for (const std::string &h : headers) {
        s += h + ", ";
    }
    s += ")\n";
    for (Tuple t : tuples) {
        s += t.toString() + "\n";
    }
    return s;
}
