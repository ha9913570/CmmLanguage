#include <iostream>
#include <string>
#include <vector>

#include "tokenize.hpp"

int main(void) {
	std::string str = "i=1aiue\no4s+1+223 - (44*2) = ";
	std::vector<std::string> tokens = tokenize(str);

	std::cout << "処理前:" << str << std::endl << "処理後" << std::endl;
	for(int i = 0; i < tokens.size(); i++) {
		std::cout << tokens[i] << ", ";
	}
	std::cout << std::endl;

	return 0;
}
