#ifndef TOKENIZE
#define TOKENIZE

#include <string>
#include <vector>

#include "token.hpp"

bool isSymbol(char c);
bool isNumber(char c);
bool isSpace(char c);
std::vector<Token> tokenize(std::string s);

#endif  // TOKENIZE
