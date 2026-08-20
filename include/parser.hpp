#ifndef PARSER
#define PARSER

#include <string>
#include <vector>

#include "token.hpp"
#include "tokenize.hpp"
#include "var.hpp"
#include "node.hpp"

class Parser {
	private:
		Node rootNode;

		bool isVarDeclaration(std::string token);

	public:
		Node parseProgram(std::string program);
		Node parseSentence(std::string sentence);
		Node parseVarDeclaration(std::vector<Token> tokens);
		Node parseCallSentence(std::vector<Token> tokens);
};

#endif // PARSER
