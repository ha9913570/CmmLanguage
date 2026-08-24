#ifndef PARSER
#define PARSER

#include <string>
#include <vector>

#include "node.hpp"
#include "tokenize.hpp"

class Parser {
private:
    Node rootNode;

    bool isVarDeclaration(std::string token);

public:
    Node parseProgram(std::string program);
    Node parseSentence(std::string sentence);
    Node parseVarDeclaration(std::vector<std::string> tokens);
    Node parseCallSentence(std::vector<std::string> tokens);
};

#endif  // PARSER
