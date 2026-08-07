#include <iostream>
#include <string>
#include <vector>

#include "tokenize.hpp"

int main(void) {
	std::string str = "41+223 - (44*2) = ";
	std::vector<std::string> tokens = tokenize(str);

	std::cout << "処理前:" << str << std::endl << "処理後" << std::endl;
	for(int i = 0; i < tokens.size(); i++) {
		std::cout << tokens[i] << std::endl;
	}

	return 0;
}
