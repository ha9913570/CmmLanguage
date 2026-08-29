#ifndef PARSER
#define PARSER

#include <string>
#include <vector>

#include "node.hpp"

bool isVarDeclaration(std::string token);
Node parseProgram(std::string program);
Node parseSentence(std::string sentence);
Node parseVarDeclaration(std::vector<std::string> tokens);
Node parseCallSentence(std::vector<std::string> tokens);
int countIndent(std::vector<std::string> tokens);

#endif  // PARSER
