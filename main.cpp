#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "token.hpp"
#include "tokenize.hpp"
#include "parser.hpp"
#include "evaluation.hpp"

int main(int argc, char* argv[]) {
	if(argc != 2) {
		std::cerr << "実行するファイルを指定してください" << std::endl;
		return 0;
	}

	std::string filePath = argv[1];
	std::ifstream file(filePath);

	if(!file) {
		std::cerr << "ファイルを開けませんでした" << std::endl;
		return 0;
	}

	// ファイル読み込み
	std::string str = "";
	std::string line;
	while(std::getline(file, line)) {
		str += line + "\n";
	}

	// 末尾の不要な改行を削除
	while(str[str.size() - 1] == '\n') {
		str.pop_back();
	}

	Parser parser;
	Evaluation evaluation;

	Node ast = parser.parseProgram(str);

	evaluation.evaluation(ast);

	file.close();
	return 0;
}
