#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "token.hpp"
#include "tokenize.hpp"

int main(void) {
	std::string str = "print(\"Hello World!\")\na = 20\nb=19\nc=a+b\nd=a-b\nprint(c)\nprint(d)";
	std::vector<Token> tokens = tokenize(str);

	std::map<std::string, std::string> vars; // 変数

	for(int i = 0; i < tokens.size(); i++) {
		// 変数の代入
		if(tokens[i].token == "=") {
			std::string value = tokens[i + 1].token;
			for(int j = i + 2; tokens[j].token != "\n"; j++) {
				value += tokens[j].token;
			}
			// +や-が入っていたら計算する
			if(value.find("+") != std::string::npos) {
				value = std::to_string(std::stoi(vars[tokens[i + 1].token]) + std::stoi(vars[tokens[i + 3].token]));
			} else if(value.find("-") != std::string::npos) {
				value = std::to_string(std::stoi(vars[tokens[i + 1].token]) - std::stoi(vars[tokens[i + 3].token]));
			}
			vars[tokens[i - 1].token] = value;
		} else if(tokens[i].token == "print") {
			if(tokens[i + 2].token == "\"") {
				for(int j = i + 3; tokens[j].token != "\""; j++) {
					std::cout << tokens[j].token << " ";
				}
				std::cout << std::endl;
			} else {
				std::cout << vars[tokens[i + 2].token] << std::endl;
			}
		}
	}

	std::cout << "\n==デバッグ用==" << std::endl;

	std::cout << "変数" << std::endl;
	for(const auto& pair : vars) {
		std::cout << pair.first << ":" << pair.second << std::endl;
	}

	std::cout << "処理前\n" << str << std::endl << "処理後" << std::endl;
	for(int i = 0; i < tokens.size(); i++) {
		std::cout << tokens[i].toString();
	}
	std::cout << std::endl;

	return 0;
}
