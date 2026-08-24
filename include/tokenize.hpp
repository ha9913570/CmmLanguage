#ifndef TOKENIZE
#define TOKENIZE

#include <string>
#include <vector>

bool isSymbol(char c);
bool isNumber(char c);
bool isSpace(char c);
std::vector<std::string> tokenize(std::string s);

#endif  // TOKENIZE
