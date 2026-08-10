#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "tokenize.hpp"

int main(void) {
	std::string str = "print(\"Hello World!\")\na = 20\nb=19\nr=a+b\nprint(r)";
	std::vector<std::string> tokens = tokenize(str);

	std::map<std::string, std::string> vars; // 変数

	for(int i = 0; i < tokens.size(); i++) {
		if(tokens[i] == "=") {
			std::string value = tokens[i + 1];
			for(int j = i + 2; tokens[j] != "\n"; j++) {
				value += tokens[j];
			}
			vars[tokens[i - 1]] = value;
		} else if(tokens[i] == "print") {
			if(tokens[i + 2] == "\"") {
				for(int j = i + 3; tokens[j] != "\""; j++) {
					std::cout << tokens[j] << " ";
				}
				std::cout << std::endl;
			} else {
				std::cout << vars[tokens[i + 2]] << std::endl;
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
		std::cout << tokens[i] << ", ";
	}
	std::cout << std::endl;

	return 0;
}
