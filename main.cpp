#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "token.hpp"
#include "tokenize.hpp"
#include "parser.hpp"
#include "evaluation.hpp"

int main(void) {
	std::string str = "print(\"Hello World!\")\nint a = 20\nint b=19\nint c=a+b-2\nint d=(1+2)^2*3\nprint(c)\nprint(d)";
	std::vector<Token> tokens = tokenize(str);

	std::map<std::string, std::string> vars; // 変数

	Parser parser;
	Evaluation evaluation;

	Node ast = parser.parseProgram(str);
	//ast.printNode();

	evaluation.evaluation(ast);

	return 0;
}
