//
// Created by Samuel Bennion on 1/27/21.
//

#include "Lexer.h"

using namespace std;
void Lexer::Run(std::string input) {
    int lineNumber = 1;
    // While there are more characters to tokenize

    while((int)input.size() > 0) {
        int maxRead = 0;
        Automaton* maxAutomaton = automata[0];
        // TODO: you need to handle whitespace inbetween tokens DONE
        while(isspace(input.at(0))){
            if(input.at(0) == '\n'){
                lineNumber++;
            }
            input.erase(0,1);
            if(!input.size()){
                Token* newToken = new Token(enumEOF, "", lineNumber);
                tokens.push_back(newToken);
                return;
            }
        }
        // Here is the "Parallel" part of the algorithm
        // Each automaton runs with the same input
        for(int i = 0; i < (int)automata.size(); i++) {
                int inputRead = automata[i]->Start(input);
                if (inputRead > maxRead) {
                    maxRead = inputRead;
                    maxAutomaton = automata[i];
                }
        }
        // Here is the "Max" part of the algorithm
        if (maxRead > 0) {
            Token *newToken;
            newToken = maxAutomaton->CreateToken(input.substr(0, maxRead), lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            /*
            if(newToken->tokenToString() != "COMMENT"){
                tokens.push_back(newToken);
            }
             */
            if(newToken->toString().substr(1, 7) != "COMMENT"){
                tokens.push_back(newToken);
            }
        }
        // No automaton accepted input; create invalid token
        else {
            maxRead = 1;
            Token* newToken = new Token(UNDEFINED, string(1, input[0]), lineNumber);
            tokens.push_back(newToken);
        }
        // Update ‘input‘ by removing characters read to create Token
        input.erase(0,maxRead);
    }
    if(!input.size()){
        Token* newToken = new Token(enumEOF, "", lineNumber);
        tokens.push_back(newToken);
        return;
    }
}

void Lexer::printTokens() {
    for(int i = 0; i < (int)tokens.size(); i++){
        cout << tokens.at(i)->toString() << endl;
    }
    cout << "Total Tokens = " << (int)tokens.size();
}
