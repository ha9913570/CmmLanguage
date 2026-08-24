#ifndef RPN_TOOL
#define RPN_TOOL

#include <string>
#include <vector>

std::vector<std::string> InfixNotationToRPN(std::vector<std::string> infixArray);
std::string calcRPN(std::vector<std::string> rpnArray);

#endif  // RPN_TOOL