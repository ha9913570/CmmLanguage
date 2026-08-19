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

		// 変数宣言の文かどうかを判定する関数
		bool isVarDeclaration(std::string token) {
			bool result = false;
			if(token == "int") {
				result = true;
			}
			return result;
		}
	public:
		// プログラム全体をパースする関数
		Node parseProgram(std::string program) {
			std::vector<std::string> sentences;
			std::string temp = "";
			for(int i = 0; i < program.size(); i++) {
				if(program[i] == '\n') {
					sentences.push_back(temp);
					temp = "";
				} else {
					temp += program[i];
				}
			}
			sentences.push_back(temp);

			rootNode.value = "root";
			rootNode.type = "program";
			for(int i = 0; i < sentences.size(); i++) {
				rootNode.node.push_back(parseSentence(sentences[i]));
			}

			return rootNode;
		}

		// プログラム中の1文をパースする関数
		Node parseSentence(std::string sentence) {
			Node sentenceNode;

			std::vector<Token> tokens = tokenize(sentence);
			if(isVarDeclaration(tokens[0].token)) {
				sentenceNode = parseVarDeclaration(tokens);
				sentenceNode.type = "var";
			} else {
				sentenceNode = parseCallSentence(tokens);
				sentenceNode.type = "call";
			}

			sentenceNode.value = sentence;
			return sentenceNode;
		}

		// 変数宣言の文をパースする関数
		Node parseVarDeclaration(std::vector<Token> tokens) {
			std::string value = "";
			for(int i = 3; i < tokens.size(); i++) {
				value += tokens[i].token;
			}

			Node mainNode;
			Node typeNode("varType", tokens[0].token);
			Node nameNode("varName", tokens[1].token);
			Node valueNode("varValue", value);

			mainNode.node.push_back(typeNode);
			mainNode.node.push_back(nameNode);
			mainNode.node.push_back(valueNode);

			return mainNode;
		}
		
		// 関数呼び出しの文をパースする関数
		Node parseCallSentence(std::vector<Token> tokens) {
			// 引数ノードを作成
			std::vector<Node> argNodes;
			std::string argValue = "";
			Node tempNode("arg", "");
			for(int i = 2; tokens[i].token != ")"; i++) {
				if(tokens[i].token == ",") {
					tempNode.value = argValue;
					argNodes.push_back(tempNode);
					argValue = "";
				} else {
					argValue += tokens[i].token;
				}
			}
			tempNode.value = argValue;
			argNodes.push_back(tempNode);

			Node mainNode;
			Node callNode("function", tokens[0].token);
			Node startNode("startArg", tokens[1].token);
			Node endNode("endArg", tokens[tokens.size() - 2].token);

			mainNode.node.push_back(callNode);
			mainNode.node.push_back(startNode);
			for(int i = 0; i < argNodes.size(); i++) {
				mainNode.node.push_back(argNodes[i]);
			}
			mainNode.node.push_back(endNode);

			return mainNode;
		}
};

#endif // PARSER
